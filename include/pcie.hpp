#pragma once
#include "mdrv2.hpp"

#include <xyz/openbmc_project/Association/Definitions/server.hpp>
#include <xyz/openbmc_project/Inventory/Decorator/Asset/server.hpp>
#include <xyz/openbmc_project/Inventory/Item/PCIeDevice/server.hpp>
#include <xyz/openbmc_project/Inventory/Item/PCIeSlot/server.hpp>
#include <xyz/openbmc_project/Inventory/Item/server.hpp>
#include <xyz/openbmc_project/State/Decorator/OperationalStatus/server.hpp>

#include <cstdint>
#include <map>
#include <unordered_set>

std::string getStringFromData(const int& size, const uint32_t& data,
                              bool prefix);

typedef struct
{
    uint32_t header;
    uint8_t bus;
    uint8_t device;
    uint8_t function;
    uint8_t reserved;
} PCIHeaderMDRV;

typedef struct
{
    uint16_t vendorId;
    uint16_t deviceId;
    uint16_t command;
    uint16_t status;
    uint32_t revisionId:8;
    uint32_t classCode:24;
    uint8_t cacheLineSize;
    uint8_t latencyTimer;
    uint8_t headerType;
    uint8_t bist;
    uint8_t padding[28];
    uint16_t subsystemVendorId;
    uint16_t subsystemId;
    uint32_t expROMaddr;
    uint32_t capabilityPtr:8;
    uint32_t reserved:24;
} PCIHeaderType0;

// Some defines from Linux pci.h
#define PCI_CAP_ID_NULL 0x00         /* Null Capability */
#define PCI_CAP_ID_EXP 0x10          /* PCI Express */
#define PCI_CAP_LIST_NEXT 1          /* Next capability in the list */

#define PCI_EXP_LNKCAP 0xc           /* Link Capabilities */
#define PCI_EXP_LNKCAP_SPEED 0x0000f /* Maximum Link Speed */
#define PCI_EXP_LNKCAP_WIDTH 0x003f0 /* Maximum Link Width */
#define PCI_EXP_LNKSTA 0x12          /* Link Status */
#define PCI_EXP_LNKSTA_SPEED 0x000f  /* Negotiated Link Speed */
#define PCI_EXP_LNKSTA_WIDTH 0x03f0  /* Negotiated Link Width */

constexpr int configSpaceSize = 256;

constexpr int pcieFunctionsSize = 8;

using pcie_device =
    sdbusplus::server::xyz::openbmc_project::inventory::item::PCIeDevice;
using asset =
    sdbusplus::server::xyz::openbmc_project::inventory::decorator::Asset;
using state = sdbusplus::server::xyz::openbmc_project::state::decorator::
    OperationalStatus;
using item = sdbusplus::server::xyz::openbmc_project::inventory::Item;
using association =
    sdbusplus::server::xyz::openbmc_project::association::Definitions;

class PcieDevice :
    sdbusplus::server::object_t<pcie_device>,
    sdbusplus::server::object_t<asset>,
    sdbusplus::server::object_t<state>,
    sdbusplus::server::object_t<item>,
    sdbusplus::server::object_t<association>
{
  public:
    PcieDevice() = delete;
    PcieDevice(const PcieDevice&) = delete;
    PcieDevice& operator=(const PcieDevice&) = delete;
    PcieDevice(PcieDevice&&) = delete;
    PcieDevice& operator=(PcieDevice&&) = delete;
    ~PcieDevice() = default;

    PcieDevice(sdbusplus::bus_t& bus, const std::string& objPath) :
        sdbusplus::server::object_t<pcie_device>(bus, objPath.c_str()),
        sdbusplus::server::object_t<asset>(bus, objPath.c_str()),
        sdbusplus::server::object_t<state>(bus, objPath.c_str()),
        sdbusplus::server::object_t<item>(bus, objPath.c_str()),
        sdbusplus::server::object_t<association>(bus, objPath.c_str())
    {
        for (int i = 0; i < pcieFunctionsSize; i++)
            configData[i] = nullptr;
    }

    void pcieInfoUpdate(const std::string& motherboard);

    std::array<uint8_t*, pcieFunctionsSize> configData;
};
