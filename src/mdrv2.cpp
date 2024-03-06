#include "mdrv2.hpp"

#include "pcie.hpp"

#include <boost/asio/io_context.hpp>
#include <boost/container/flat_map.hpp>
#include <phosphor-logging/lg2.hpp>
#include <phosphor-logging/log.hpp>
#include <sdbusplus/asio/connection.hpp>
#include <sdbusplus/asio/object_server.hpp>

#include <fstream>

std::unordered_map<std::string, std::unique_ptr<PcieDevice>> pcieDevices;
std::unique_ptr<sdbusplus::bus::match_t> motherboardConfigMatch;
boost::asio::io_context io;

bool readDataFromFlash(MDRPCIeHeader* mdrHdr, uint8_t* data)
{
    if (mdrHdr == nullptr)
    {
        phosphor::logging::log<phosphor::logging::level::ERR>(
            "Read data from flash error - Invalid mdr header");
        return false;
    }
    if (data == nullptr)
    {
        phosphor::logging::log<phosphor::logging::level::ERR>(
            "Read data from flash error - Invalid data point");
        return false;
    }
    std::ifstream pcieFile(mdrType2File, std::ios_base::binary);
    if (!pcieFile.good())
    {
        phosphor::logging::log<phosphor::logging::level::ERR>(
            "Read data from flash error - Open MDRV2 table file failure");
        return false;
    }
    pcieFile.clear();
    pcieFile.seekg(0, std::ios_base::end);
    size_t fileLength = pcieFile.tellg();
    pcieFile.seekg(0, std::ios_base::beg);
    if (fileLength < sizeof(MDRPCIeHeader))
    {
        phosphor::logging::log<phosphor::logging::level::ERR>(
            "MDR V2 file size is smaller than mdr header");
        return false;
    }
    pcieFile.read(reinterpret_cast<char*>(mdrHdr), sizeof(MDRPCIeHeader));
    if (mdrHdr->dataSize > pcieTableStorageSize)
    {
        phosphor::logging::log<phosphor::logging::level::ERR>(
            "Data size out of limitation");
        pcieFile.close();
        return false;
    }
    fileLength -= sizeof(MDRPCIeHeader);
    if (fileLength < mdrHdr->dataSize)
    {
        pcieFile.read(reinterpret_cast<char*>(data), fileLength);
    }
    else
    {
        pcieFile.read(reinterpret_cast<char*>(data), mdrHdr->dataSize);
    }
    pcieFile.close();
    return true;
}

void updatePcieInfo(UpdateDBusData infoPcieDevs,
                    const std::string& motherboardPath)
{
    pcieDevices.clear();
    uint32_t offset = 0;
    while (offset < infoPcieDevs.mdrHdr.dataSize)
    {
        auto PCIheaderMDRV = reinterpret_cast<const PCIHeaderMDRV*>(
            infoPcieDevs.dataStorage + offset);

        if (PCIheaderMDRV->header != 0x45494350)
        {
            phosphor::logging::log<phosphor::logging::level::ERR>(
                "PCI MDRV header signature is wrong",
                phosphor::logging::entry("SIGNATURE=0x%08x",
                                         int(PCIheaderMDRV->header)));
            break;
        }
        uint8_t* PCIConfigSpace = infoPcieDevs.dataStorage + offset +
                                  sizeof(PCIHeaderMDRV);

        offset += (sizeof(PCIHeaderMDRV) + configSpaceSize);

        uint8_t bus_addr = PCIheaderMDRV->bus;
        uint8_t device_addr = PCIheaderMDRV->device;
        std::string path;

        path = std::string(PCIeDevicesPath) + "/Bus_" +
               getStringFromData(sizeof(bus_addr), bus_addr, false) +
               "_Device_" +
               getStringFromData(sizeof(device_addr), device_addr, false);

        std::string log_message;
        if (auto it = pcieDevices.find(path); it != pcieDevices.end())
        {
            log_message = "Append to object: " + path;
            phosphor::logging::log<phosphor::logging::level::INFO>(
                log_message.c_str());
            it->second->configData[PCIheaderMDRV->function] = PCIConfigSpace;
        }
        else
        {
            log_message = "Create object: " + path;
            phosphor::logging::log<phosphor::logging::level::INFO>(
                log_message.c_str());
            std::unique_ptr<PcieDevice> MyDev =
                std::make_unique<PcieDevice>(*infoPcieDevs.bus, path);
            MyDev->configData[PCIheaderMDRV->function] = PCIConfigSpace;
            pcieDevices.emplace(
                path, std::forward<std::unique_ptr<PcieDevice>>(MyDev));
        }
    }

    for (auto& pciDev : pcieDevices)
    {
        pciDev.second->pcieInfoUpdate(motherboardPath);
    }
}

void getMotherboardPath(sdbusplus::bus_t& bus, const std::string& inventoryPath,
                        std::string& motherboardPath)
{
    // By default, look for System interface on any system/board/* object
    std::string mapperAncestorPath = inventoryPath;
    std::string matchParentPath = inventoryPath + "/board/";
    bool requireExactMatch = false;

    if (inventoryPath != defaultInventoryPath)
    {
        std::filesystem::path path(inventoryPath);

        // Search under parent to find exact match for self
        mapperAncestorPath = path.parent_path().string();
        matchParentPath = mapperAncestorPath;
        requireExactMatch = true;
    }

    auto method = bus.new_method_call(mapperBusName, mapperPath,
                                      mapperInterface, "GetSubTreePaths");
    method.append(mapperAncestorPath);
    method.append(0);
    method.append(std::vector<std::string>({systemInterface}));

    try
    {
        std::vector<std::string> paths;
        sdbusplus::message_t reply = bus.call(method);
        reply.read(paths);

        size_t pathsCount = paths.size();
        for (size_t i = 0; i < pathsCount; ++i)
        {
            if (requireExactMatch && (paths[i] != inventoryPath))
            {
                continue;
            }

            motherboardPath = std::move(paths[i]);
            break;
        }
        if (motherboardPath.empty())
        {
            phosphor::logging::log<phosphor::logging::level::ERR>(
                "Failed to get system motherboard dbus path. Setting up a "
                "match rule");

            if (!motherboardConfigMatch)
            {
                motherboardConfigMatch =
                    std::make_unique<sdbusplus::bus::match_t>(
                        bus,
                        sdbusplus::bus::match::rules::interfacesAdded() +
                            sdbusplus::bus::match::rules::argNpath(
                                0, matchParentPath),
                        [&](sdbusplus::message_t& msg) {
                    sdbusplus::message::object_path objectName;
                    boost::container::flat_map<
                        std::string,
                        boost::container::flat_map<
                            std::string, std::variant<std::string, uint64_t>>>
                        msgData;
                    msg.read(objectName, msgData);
                    if (msgData.contains(systemInterface))
                    {
                        getMotherboardPath(bus, inventoryPath, motherboardPath);
                    }
                });
            }
        }
        else
        {
            lg2::info(
                "Found Inventory anchor object for PCIe-MDR content {I}: {M}",
                "I", inventoryPath, "M", motherboardPath);
        }
    }
    catch (const sdbusplus::exception_t& e)
    {
        lg2::error(
            "Exception while trying to find Inventory anchor object for PCIe-MDR content {I}: {E}",
            "I", inventoryPath, "E", e.what());
        phosphor::logging::log<phosphor::logging::level::ERR>(
            "Failed to query system motherboard",
            phosphor::logging::entry("ERROR=%s", e.what()));
    }
}

bool updateMappingsFromFile(sdbusplus::bus_t& bus,
                            const std::string& inventoryPath)
{
    std::string motherboardPath;
    getMotherboardPath(bus, inventoryPath, motherboardPath);

    UpdateDBusData infoPcieDevs;
    infoPcieDevs.bus = &bus;

    phosphor::logging::log<phosphor::logging::level::INFO>(
        "updateMappingsFromFile");

    bool status = readDataFromFlash(&infoPcieDevs.mdrHdr,
                                    infoPcieDevs.dataStorage);
    if (!status)
    {
        phosphor::logging::log<phosphor::logging::level::ERR>(
            "agent data sync failed - read data from flash failed");
        return false;
    }

    if (infoPcieDevs.mdrHdr.dataSize < sizeof(PCIHeaderMDRV))
        return false;

    io.post(std::bind(updatePcieInfo, infoPcieDevs, motherboardPath));
    return true;
}

int main(void)
{
    auto connection = std::make_shared<sdbusplus::asio::connection>(io);
    auto objServer = sdbusplus::asio::object_server(connection);

    sdbusplus::bus_t& bus = static_cast<sdbusplus::bus_t&>(*connection);

    bus.request_name(PCIeMdrV2Service);
    std::shared_ptr<sdbusplus::asio::dbus_interface> iface =
        objServer.add_interface(PCIeMdrV2Path, PCIeMdrV2Interface);
    iface->register_method(PCIeMdrV2UpdateFunctionName, [&]() {
        return updateMappingsFromFile(bus, defaultInventoryPath);
    });
    iface->initialize();

    updateMappingsFromFile(bus, defaultInventoryPath);

    io.run();

    return 0;
}
