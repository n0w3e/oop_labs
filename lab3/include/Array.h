#pragma once
#include <vector>
#include "Figure.h"

class Array {
public:
    Array();
    ~Array();

    void add(Figure* figure);
    bool remove(size_t index);
    size_t getSize() const;
    Figure* operator[](size_t index) const;
    double totalArea() const;

private:
    void resize();
    Figure** figures;
    size_t size;
    size_t capacity;
};
