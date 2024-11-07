#ifndef DYNAMIC_ARRAY_IMPL_H
#define DYNAMIC_ARRAY_IMPL_H

#include "../include/dynamic_array.h"
#include <algorithm>

template <typename T>
DynamicArray<T>::DynamicArray(std::pmr::memory_resource* memoryResource)
    : allocator(memoryResource), data(nullptr), capacity(0), currentSize(0) {}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    for (size_t i = 0; i < currentSize; ++i) {
        allocator.destroy(data + i);
    }
    allocator.deallocate(data, capacity);
}

template <typename T>
void DynamicArray<T>::push_back(const T& value) {
    if (currentSize == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    allocator.construct(data + currentSize, value);
    ++currentSize;
}

template <typename T>
void DynamicArray<T>::pop_back() {
    if (currentSize > 0) {
        --currentSize;
        allocator.destroy(data + currentSize);
    }
}

template <typename T>
size_t DynamicArray<T>::size() const {
    return currentSize;
}

template <typename T>
T& DynamicArray<T>::operator[](size_t index) {
    if (index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
    if (index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
typename DynamicArray<T>::Iterator DynamicArray<T>::begin() {
    return Iterator(data);
}

template <typename T>
typename DynamicArray<T>::Iterator DynamicArray<T>::end() {
    return Iterator(data + currentSize);
}

template <typename T>
void DynamicArray<T>::resize(size_t newCapacity) {
    T* newData = allocator.allocate(newCapacity);

    for (size_t i = 0; i < currentSize; ++i) {
        allocator.construct(newData + i, std::move(data[i]));
        allocator.destroy(data + i);
    }


    allocator.deallocate(data, capacity);
    data = newData;
    capacity = newCapacity;
}

#endif
