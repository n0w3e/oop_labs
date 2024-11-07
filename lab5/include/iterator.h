#ifndef ITERATOR_H
#define ITERATOR_H

#include <iterator>
#include <cstddef>

template <typename T>
class ArrayIterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    explicit ArrayIterator(T* ptr) : ptr(ptr) {}

    T& operator*() const { return *ptr; }
    T* operator->() { return ptr; }

    ArrayIterator& operator++() { 
        ++ptr; 
        return *this;
    }

    ArrayIterator operator++(int) { 
        ArrayIterator temp = *this; 
        ++(*this); 
        return temp;
    }

    friend bool operator==(const ArrayIterator& a, const ArrayIterator& b) {
        return a.ptr == b.ptr;
    }

    friend bool operator!=(const ArrayIterator& a, const ArrayIterator& b) {
        return a.ptr != b.ptr;
    }

private:
    T* ptr;
};

#endif
