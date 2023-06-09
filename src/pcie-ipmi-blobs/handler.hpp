#pragma once

#include <blobs-ipmid/blobs.hpp>
#include <mdrv2.hpp>

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace blobs
{

class PcieBlobHandler : public GenericBlobInterface
{
  public:
    PcieBlobHandler() = default;
    ~PcieBlobHandler() = default;
    PcieBlobHandler(const PcieBlobHandler&) = delete;
    PcieBlobHandler& operator=(const PcieBlobHandler&) = delete;
    PcieBlobHandler(PcieBlobHandler&&) = default;
    PcieBlobHandler& operator=(PcieBlobHandler&&) = default;

    struct PcieBlob
    {
        PcieBlob(uint16_t id, const std::string& path, uint16_t flags) :
            sessionId(id), blobId(path), state(0)
        {
            if (flags & blobs::OpenFlags::write)
            {
                state |= blobs::StateFlags::open_write;
            }

            /* Pre-allocate the buffer.capacity() with maxBufferSize */
            buffer.reserve(maxBufferSize);
        }

        /* The blob handler session id. */
        uint16_t sessionId;

        /* The identifier for the blob */
        std::string blobId;

        /* The current state. */
        uint16_t state;

        /* The staging buffer. */
        std::vector<uint8_t> buffer;
    };

    bool canHandleBlob(const std::string& path) override;
    std::vector<std::string> getBlobIds() override;
    bool deleteBlob(const std::string& path) override;
    bool stat(const std::string& path, struct BlobMeta* meta) override;
    bool open(uint16_t session, uint16_t flags,
              const std::string& path) override;
    std::vector<uint8_t> read(uint16_t session, uint32_t offset,
                              uint32_t requestedSize) override;
    bool write(uint16_t session, uint32_t offset,
               const std::vector<uint8_t>& data) override;
    bool writeMeta(uint16_t session, uint32_t offset,
                   const std::vector<uint8_t>& data) override;
    bool commit(uint16_t session, const std::vector<uint8_t>& data) override;
    bool close(uint16_t session) override;
    bool stat(uint16_t session, struct BlobMeta* meta) override;
    bool expire(uint16_t session) override;

  private:
    static constexpr char blobId[] = "/pcie";

    static constexpr uint32_t maxBufferSize = pcieTableStorageSize;

    /* The handler only allows one open blob. */
    std::unique_ptr<PcieBlob> blobPtr = nullptr;
};

} // namespace blobs
