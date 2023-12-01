#include "handler.hpp"

#include <sys/stat.h>
#include <unistd.h>

#include <ipmid/api.hpp>
#include <phosphor-logging/elog-errors.hpp>
#include <phosphor-logging/log.hpp>
#include <sdbusplus/bus.hpp>
#include <sdbusplus/exception.hpp>
#include <sdbusplus/message.hpp>

#include <algorithm>
#include <cstdint>
#include <ctime>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

namespace blobs
{

namespace pcie
{

bool syncPCIeData()
{
    bool status = false;
    sdbusplus::bus_t bus = sdbusplus::bus_t(ipmid_get_sd_bus_connection());
    sdbusplus::message_t method =
        bus.new_method_call(PCIeMdrV2Service, PCIeMdrV2Path, PCIeMdrV2Interface,
                            PCIeMdrV2UpdateFunctionName);

    try
    {
        sdbusplus::message_t reply = bus.call(method);
        reply.read(status);
    }
    catch (const sdbusplus::exception_t& e)
    {
        phosphor::logging::log<phosphor::logging::level::ERR>(
            "Error Sync data with service",
            phosphor::logging::entry("ERROR=%s", e.what()),
            phosphor::logging::entry("SERVICE=%s", PCIeMdrV2Service),
            phosphor::logging::entry("PATH=%s", PCIeMdrV2Path),
            phosphor::logging::entry("INTERFACE=%s", PCIeMdrV2Interface),
            phosphor::logging::entry("FUNCTION=%s",
                                     PCIeMdrV2UpdateFunctionName));
        return false;
    }

    if (!status)
    {
        phosphor::logging::log<phosphor::logging::level::ERR>(
            "Sync data with service failure");
        return false;
    }

    return true;
}

} // namespace pcie

bool PcieBlobHandler::canHandleBlob(const std::string& path)
{
    return path == blobId;
}

std::vector<std::string> PcieBlobHandler::getBlobIds()
{
    return std::vector<std::string>(1, blobId);
}

bool PcieBlobHandler::deleteBlob(const std::string& /* path */)
{
    return false;
}

bool PcieBlobHandler::stat(const std::string& path, struct BlobMeta* meta)
{
    if (!blobPtr || blobPtr->blobId != path)
    {
        return false;
    }

    meta->size = blobPtr->buffer.size();
    meta->blobState = blobPtr->state;
    return true;
}

bool PcieBlobHandler::open(uint16_t session, uint16_t flags,
                           const std::string& path)
{
    if (flags & blobs::OpenFlags::read)
    {
        /* Disable the read operation. */
        return false;
    }

    /* The handler only allows one session. If an open blob exists, return
     * false directly.
     */
    if (blobPtr)
    {
        return false;
    }
    blobPtr = std::make_unique<PcieBlob>(session, path, flags);
    return true;
}

std::vector<uint8_t> PcieBlobHandler::read(uint16_t /* session */,
                                           uint32_t /* offset */,
                                           uint32_t /* requestedSize */)
{
    /* PCIe blob handler does not support read. */
    return std::vector<uint8_t>();
}

bool PcieBlobHandler::write(uint16_t session, uint32_t offset,
                            const std::vector<uint8_t>& data)
{
    if (!blobPtr || blobPtr->sessionId != session)
    {
        return false;
    }

    if (!(blobPtr->state & blobs::StateFlags::open_write))
    {
        phosphor::logging::log<phosphor::logging::level::ERR>(
            "No open blob to write");
        return false;
    }

    /* Is the offset beyond the array? */
    if (offset >= maxBufferSize)
    {
        return false;
    }

    /* Determine whether all their bytes will fit. */
    uint32_t remain = maxBufferSize - offset;
    if (data.size() > remain)
    {
        return false;
    }

    /* Resize the buffer if what we're writing will go over the size */
    uint32_t newBufferSize = data.size() + offset;
    if (newBufferSize > blobPtr->buffer.size())
    {
        blobPtr->buffer.resize(newBufferSize);
    }

    std::memcpy(blobPtr->buffer.data() + offset, data.data(), data.size());
    return true;
}

bool PcieBlobHandler::writeMeta(uint16_t /* session */, uint32_t /* offset */,
                                const std::vector<uint8_t>& /* data */)
{
    return false;
}

bool PcieBlobHandler::commit(uint16_t session, const std::vector<uint8_t>& data)
{
    if (!data.empty())
    {
        phosphor::logging::log<phosphor::logging::level::ERR>(
            "Unexpected data provided to commit call");
        return false;
    }

    if (!blobPtr || blobPtr->sessionId != session)
    {
        return false;
    }

    /* If a blob is committing or commited, return true directly. But if last
     * commit fails, may try to commit again.
     */
    if (blobPtr->state &
        (blobs::StateFlags::committing | blobs::StateFlags::committed))
    {
        return true;
    }

    /* Clear the commit_error bit. */
    blobPtr->state &= ~blobs::StateFlags::commit_error;

    MDRPCIeHeader mdrHdr;
    mdrHdr.mdrType = mdrTypeII;
    mdrHdr.timestamp = std::time(nullptr);
    mdrHdr.dataSize = blobPtr->buffer.size();
    if (access(pciePath, F_OK) == -1)
    {
        int flag = mkdir(pciePath, S_IRWXU);
        if (flag != 0)
        {
            phosphor::logging::log<phosphor::logging::level::ERR>(
                "create folder failed for writting pcie file");
            blobPtr->state |= blobs::StateFlags::commit_error;
            return false;
        }
    }

    std::ofstream pcieFile(mdrType2File,
                           std::ios_base::binary | std::ios_base::trunc);
    if (!pcieFile.good())
    {
        phosphor::logging::log<phosphor::logging::level::ERR>(
            "Write data from flash error - Open PCIe table file failure");
        blobPtr->state |= blobs::StateFlags::commit_error;
        return false;
    }

    pcieFile.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try
    {
        pcieFile.write(reinterpret_cast<char*>(&mdrHdr), sizeof(MDRPCIeHeader));
        pcieFile.write(reinterpret_cast<char*>(blobPtr->buffer.data()),
                       blobPtr->buffer.size());
        pcieFile.close();
        blobPtr->state |= blobs::StateFlags::committing;
    }
    catch (const std::ofstream::failure& e)
    {
        phosphor::logging::log<phosphor::logging::level::ERR>(
            "Write data from flash error - write data error",
            phosphor::logging::entry("ERROR=%s", e.what()));
        blobPtr->state |= blobs::StateFlags::commit_error;
        return false;
    }

    if (!pcie::syncPCIeData())
    {
        blobPtr->state &= ~blobs::StateFlags::committing;
        blobPtr->state |= blobs::StateFlags::commit_error;
        return false;
    }

    // Unset committing state and set committed state
    blobPtr->state &= ~blobs::StateFlags::committing;
    blobPtr->state |= blobs::StateFlags::committed;

    return true;
}

bool PcieBlobHandler::close(uint16_t session)
{
    if (!blobPtr || blobPtr->sessionId != session)
    {
        return false;
    }

    blobPtr = nullptr;
    return true;
}

bool PcieBlobHandler::stat(uint16_t session, struct BlobMeta* meta)
{
    if (!blobPtr || blobPtr->sessionId != session)
    {
        return false;
    }

    meta->size = blobPtr->buffer.size();
    meta->blobState = blobPtr->state;
    return true;
}

bool PcieBlobHandler::expire(uint16_t session)
{
    return close(session);
}

} // namespace blobs
