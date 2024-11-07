#ifndef MEMORY_RESOURCE_H
#define MEMORY_RESOURCE_H

#include <memory_resource>
#include <list>
#include <cstddef>
#include <cassert>

class FixedMemoryResource : public std::pmr::memory_resource {
public:
    explicit FixedMemoryResource(size_t blockSize, size_t blockCount);
    ~FixedMemoryResource();

protected:
    void* do_allocate(size_t bytes, size_t alignment) override;
    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

private:
    void* memoryBlock;
    std::list<void*> freeBlocks;
    size_t blockSize;
    size_t blockCount;

    void initializeMemoryPool();
};

#endif
