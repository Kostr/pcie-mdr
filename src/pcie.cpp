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

sdbusplus::xyz::openbmc_project::Inventory::Item::server::PCIeSlot::Generations
    linkSpeed(uint32_t speed)
{
    switch (speed)
    {
        case 1:
            return sdbusplus::xyz::openbmc_project::Inventory::Item::server::
                PCIeSlot::Generations::Gen1;
        case 2:
            return sdbusplus::xyz::openbmc_project::Inventory::Item::server::
                PCIeSlot::Generations::Gen2;
        case 3:
            return sdbusplus::xyz::openbmc_project::Inventory::Item::server::
                PCIeSlot::Generations::Gen3;
        case 4:
            return sdbusplus::xyz::openbmc_project::Inventory::Item::server::
                PCIeSlot::Generations::Gen4;
        case 5:
            return sdbusplus::xyz::openbmc_project::Inventory::Item::server::
                PCIeSlot::Generations::Gen5;
        default:
            return sdbusplus::xyz::openbmc_project::Inventory::Item::server::
                PCIeSlot::Generations::Unknown;
    }
}

uint8_t findPCIeCapability(uint8_t* configData)
{
    auto PCIheaderType0 = reinterpret_cast<const PCIHeaderType0*>(configData);
    uint8_t capabilityPtr = PCIheaderType0->capabilityPtr;

    while (capabilityPtr != 0x0)
    {
        uint8_t capabilityId = configData[capabilityPtr];
        if (capabilityId == PCI_CAP_ID_EXP)
            return capabilityPtr;
        else if (capabilityId == PCI_CAP_ID_NULL)
            return 0;
        else
            capabilityPtr = configData[capabilityPtr + PCI_CAP_LIST_NEXT];
    }
    return 0;
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

        uint8_t capabilityPtr = findPCIeCapability(configData.at(i));
        if (capabilityPtr != 0x0)
        {
            uint8_t* config = configData.at(i);
            uint32_t* link_cap = reinterpret_cast<uint32_t*>(
                config + capabilityPtr + PCI_EXP_LNKCAP);
            generationSupported(linkSpeed(*link_cap & PCI_EXP_LNKCAP_SPEED));
            maxLanes((*link_cap & PCI_EXP_LNKCAP_WIDTH) >> 4);
            uint32_t* link_sta = reinterpret_cast<uint32_t*>(
                config + capabilityPtr + PCI_EXP_LNKSTA);
            generationInUse(linkSpeed(*link_sta & PCI_EXP_LNKSTA_SPEED));
            lanesInUse((*link_sta & PCI_EXP_LNKSTA_WIDTH) >> 4);
        }
        else
        {
            // Keep in mind that Unknown is not a possible value for Redfish
            generationInUse(sdbusplus::xyz::openbmc_project::Inventory::Item::
                                server::PCIeSlot::Generations::Unknown);
            generationSupported(
                sdbusplus::xyz::openbmc_project::Inventory::Item::server::
                    PCIeSlot::Generations::Unknown);
            maxLanes(0);
            lanesInUse(0);
        }
        manufacturer(
            pciVendors.try_emplace(PCIheaderType0->vendorId, otherVendor)
                .first->second);
    }
}
