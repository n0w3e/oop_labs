#ifndef FIXED_MEMORY_RESOURCE_H
#define FIXED_MEMORY_RESOURCE_H

#include <memory_resource>
#include <list>
#include <cstddef>
#include <stdexcept>

class FixedMemoryResource : public std::pmr::memory_resource {
public:
    FixedMemoryResource(std::size_t blockSize, std::size_t blockCount)
        : blockSize(blockSize), blockCount(blockCount), memoryPool(blockSize * blockCount) {
        for (std::size_t i = 0; i < blockCount; ++i) {
            freeBlocks.push_back(memoryPool.data() + i * blockSize);
        }
    }

protected:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override {
        if (bytes > blockSize || freeBlocks.empty()) {
            throw std::bad_alloc();
        }
        void* ptr = freeBlocks.front();
        freeBlocks.pop_front();
        return ptr;
    }

    void do_deallocate(void* ptr, std::size_t bytes, std::size_t alignment) override {
        if (ptr != nullptr && bytes <= blockSize) {
            freeBlocks.push_back(ptr);
        }
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }

private:
    std::size_t blockSize;
    std::size_t blockCount;
    std::vector<std::byte> memoryPool;
    std::list<void*> freeBlocks;
};

#endif
