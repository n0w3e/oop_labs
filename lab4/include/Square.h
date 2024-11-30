#pragma once
#include "Rectangle.h"

template <typename T>
class Square : public Rectangle<T> {
    static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");

public:
    Square(const Point<T>& topLeft, T side)
        : Rectangle<T>(topLeft, side, side) {}
};