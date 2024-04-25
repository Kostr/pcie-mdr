#pragma once

#include <sdbusplus/bus.hpp>

#include <cstdint>

static constexpr const char* mdrType2File = "/var/lib/pcie/pcie";
static constexpr const char* pciePath = "/var/lib/pcie";
constexpr uint8_t mdrTypeII = 2;

constexpr uint32_t pcieTableStorageSize = 128 * 1024;

struct MDRPCIeHeader
{
    uint8_t dirVer;
    uint8_t mdrType;
    uint32_t timestamp;
    uint32_t dataSize;
} __attribute__((packed));

struct UpdateDBusData
{
    sdbusplus::bus_t* bus;
    MDRPCIeHeader mdrHdr;
    uint8_t dataStorage[pcieTableStorageSize];
};

constexpr const char* PCIeMdrV2Service = "xyz.openbmc_project.PCIe.MDRV2";
constexpr const char* PCIeMdrV2Path = "/xyz/openbmc_project/PCIe_MDRV2";
constexpr const char* PCIeMdrV2Interface = "xyz.openbmc_project.PCIe_MDRV2";
constexpr const char* PCIeMdrV2UpdateFunctionName = "UpdateMappingsFromFile";
constexpr const char* PCIeDevicesPath = "/xyz/openbmc_project/inventory/pcie";

constexpr const char* mapperBusName = "xyz.openbmc_project.ObjectMapper";
constexpr const char* mapperPath = "/xyz/openbmc_project/object_mapper";
constexpr const char* mapperInterface = "xyz.openbmc_project.ObjectMapper";

constexpr const char* defaultInventoryPath =
    "/xyz/openbmc_project/inventory/system";
constexpr const char* systemInterface =
    "xyz.openbmc_project.Inventory.Item.System";
