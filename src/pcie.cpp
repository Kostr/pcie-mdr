#include "pcie.hpp"

#include "pcieDeviceClass.hpp"
#include "pcieVendors.hpp"

#include <cstdint>
#include <iomanip>
#include <map>

std::string getStringFromData(const int& size, const uint32_t& data,
                              bool prefix = true)
{
    std::stringstream dataStream;
    if (prefix)
        dataStream << "0x" << std::hex << std::setfill('0')
                   << std::setw(size * 2) << data;
    else
        dataStream << std::hex << std::setfill('0') << std::setw(size * 2)
                   << data;
    return dataStream.str();
}

void PcieDevice::pcieInfoUpdate()
{

    for (int i = 0; i < pcieFunctionsSize; i++)
    {
        auto PCIheaderType0 =
            reinterpret_cast<const PCIHeaderType0*>(configData.at(i));
        if (PCIheaderType0 == nullptr)
            continue;

        if (PCIheaderType0->headerType & 0x80)
            pcie_device::deviceType("MultiFunction");
        else
            pcie_device::deviceType("SingleFunction");
        setPropertyByName("Function" + std::to_string(i) + "DeviceId",
                          getStringFromData(sizeof(PCIheaderType0->deviceId),
                                            PCIheaderType0->deviceId));
        setPropertyByName("Function" + std::to_string(i) + "VendorId",
                          getStringFromData(sizeof(PCIheaderType0->vendorId),
                                            PCIheaderType0->vendorId));
        setPropertyByName("Function" + std::to_string(i) + "ClassCode",
                          getStringFromData(3, PCIheaderType0->classCode));
        setPropertyByName(
            "Function" + std::to_string(i) + "DeviceClass",
            pciDeviceClasses
                .try_emplace((PCIheaderType0->classCode) >> 16, otherClass)
                .first->second);
        // Set the function type always to physical for now
        setPropertyByName("Function" + std::to_string(i) + "FunctionType",
                          "Physical");
        setPropertyByName("Function" + std::to_string(i) + "RevisionId",
                          getStringFromData(1, PCIheaderType0->revisionId));
        setPropertyByName("Function" + std::to_string(i) + "SubsystemId",
                          getStringFromData(sizeof(PCIheaderType0->subsystemId),
                                            PCIheaderType0->subsystemId));
        setPropertyByName(
            "Function" + std::to_string(i) + "SubsystemVendorId",
            getStringFromData(sizeof(PCIheaderType0->subsystemVendorId),
                              PCIheaderType0->subsystemVendorId));

        generationInUse(sdbusplus::xyz::openbmc_project::Inventory::Item::
                            server::PCIeSlot::Generations::Gen1);
        generationSupported(sdbusplus::xyz::openbmc_project::Inventory::Item::
                                server::PCIeSlot::Generations::Gen1);
        manufacturer(
            pciVendors.try_emplace(PCIheaderType0->vendorId, otherVendor)
                .first->second);
    }
}
