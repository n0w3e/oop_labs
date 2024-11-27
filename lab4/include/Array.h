#pragma once
#include <memory>
#include <iostream>
#include <stdexcept>

template <class T>
class Array {
public:
    Array() : size(0), capacity(10), data(new std::shared_ptr<T>[capacity]) {}

    void add(const std::shared_ptr<T>& element) {
        if (size == capacity) resize();
        data[size++] = element;
    }

    bool remove(size_t index) {
        if (index >= size) return false;
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        --size;
        return true;
    }

    size_t getSize() const { return size; }

    std::shared_ptr<T>& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    const std::shared_ptr<T>& operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    double totalArea() const {
        double total = 0;
        for (size_t i = 0; i < size; ++i) {
            total += static_cast<double>(*data[i]);
        }
        return total;
    }

private:
    void resize() {
        capacity *= 2;
        auto newData = std::make_unique<std::shared_ptr<T>[]>(capacity);
        for (size_t i = 0; i < size; ++i) {
            newData[i] = std::move(data[i]);
        }
        data = std::move(newData);
    }

    size_t size;
    size_t capacity;
    std::unique_ptr<std::shared_ptr<T>[]> data;
};
