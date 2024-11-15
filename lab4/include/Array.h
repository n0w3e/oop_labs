#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <vector>

template <typename T>
class Array {
private:
    std::vector<std::shared_ptr<T>> elements;

public:
    Array() = default;

    void add(const std::shared_ptr<T>& element);
    void remove(size_t index);
    size_t getSize() const;
    std::shared_ptr<T> operator[](size_t index) const;

    double totalArea() const;
    void printAll() const;
};

#endif
