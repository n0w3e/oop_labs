#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <memory_resource>
#include <stdexcept>

template <typename T>
class DynamicArray {
public:
    explicit DynamicArray(std::pmr::memory_resource* mem_resource = std::pmr::get_default_resource())
        : allocator(mem_resource), data(nullptr), size_(0), capacity(0) {}

    ~DynamicArray() {
        if (data) {
            allocator.deallocate(data, capacity);
        }
    }

    void push_back(const T& value) {
        if (size_ == capacity) {
            size_t new_capacity = capacity ? capacity * 2 : 1;
            T* new_data = allocator.allocate(new_capacity);
            for (size_t i = 0; i < size_; ++i) {
                new (new_data + i) T(std::move(data[i]));
                data[i].~T();
            }
            if (data) {
                allocator.deallocate(data, capacity);
            }
            data = new_data;
            capacity = new_capacity;
        }
        new (data + size_) T(value);
        ++size_;
    }

    size_t size() const {
        return size_;
    }

    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    T* begin() { return data; }
    T* end() { return data + size_; }

private:
    T* data;
    size_t size_;
    size_t capacity;
    std::pmr::polymorphic_allocator<T> allocator;
};

#endif
