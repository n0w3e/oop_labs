#include "../include/Array.h"
#include <stdexcept>
#include <iostream>

Array::Array() : size(0), capacity(10) {
    figures = new Figure*[capacity];
}

Array::~Array() {
    for (size_t i = 0; i < size; ++i) {
        delete figures[i];
    }
    delete[] figures;
}

void Array::add(Figure* figure) {
    if (size >= capacity) {
        resize();
    }
    figures[size++] = figure;
}

bool Array::remove(size_t index) {
    if (index >= size) return false;
    delete figures[index];
    for (size_t i = index; i < size - 1; ++i) {
        figures[i] = figures[i + 1];
    }
    --size;
    return true;
}

size_t Array::getSize() const {
    return size;
}

Figure* Array::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return figures[index];
}

double Array::totalArea() const {
    double total = 0;
    for (size_t i = 0; i < size; ++i) {
        total += figures[i]->area();
    }
    return total;
}

void Array::resize() {
    capacity *= 2;
    Figure** newFigures = new Figure*[capacity];
    for (size_t i = 0; i < size; ++i) {
        newFigures[i] = figures[i];
    }
    delete[] figures;
    figures = newFigures;
}
