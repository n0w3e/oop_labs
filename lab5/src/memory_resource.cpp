#include "../include/memory_resource.h"
#include <new>
#include <iostream>

FixedMemoryResource::FixedMemoryResource(size_t blockSize, size_t blockCount)
    : blockSize(blockSize), blockCount(blockCount) {
    memoryBlock = ::operator new(blockSize * blockCount);
    initializeMemoryPool();
}

FixedMemoryResource::~FixedMemoryResource() {
    ::operator delete(memoryBlock);
}

void FixedMemoryResource::initializeMemoryPool() {
    char* blockPtr = static_cast<char*>(memoryBlock);
    for (size_t i = 0; i < blockCount; ++i) {
        freeBlocks.push_back(blockPtr);
        blockPtr += blockSize;
    }
}

void* FixedMemoryResource::do_allocate(size_t bytes, size_t alignment) {
    if (bytes > blockSize || freeBlocks.empty()) {
        throw std::bad_alloc();
    }

    void* ptr = freeBlocks.front();
    freeBlocks.pop_front();
    return ptr;
}

void FixedMemoryResource::do_deallocate(void* ptr, size_t bytes, size_t alignment) {
    if (ptr != nullptr && bytes <= blockSize) {
        freeBlocks.push_back(ptr);
    }
}

bool FixedMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}