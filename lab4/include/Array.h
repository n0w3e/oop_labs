#pragma once
#include "Figure.h"
#include <memory>
#include <stdexcept>

template <Scalar T>
class Array {
public:
    Array(size_t initial_capacity = 4)
        : capacity(initial_capacity), size(0), data(new std::shared_ptr<Figure<T>>[initial_capacity]) {}

    ~Array() {
        delete[] data;
    }

    void add(const std::shared_ptr<Figure<T>>& figure) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = figure;
    }

    void remove(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    std::shared_ptr<Figure<T>>& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const std::shared_ptr<Figure<T>>& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t get_size() const {
        return size;
    }

    size_t get_capacity() const {
        return capacity;
    }

private:
    size_t capacity;
    size_t size;
    std::shared_ptr<Figure<T>>* data;

    void resize(size_t new_capacity) {
        std::shared_ptr<Figure<T>>* new_data = new std::shared_ptr<Figure<T>>[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
};
