#pragma once
#include <concepts>
#include <iostream>
#include "Point.h"
#include "Rectangle.h"

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Square : public Rectangle<T> {
public:
    Square(const Point<T>& topLeft, T side)
        : Rectangle<T>(topLeft, side, side) {}

    void print(std::ostream& os) const override {
        os << "Square: Area = " << this->getArea();
    }
};
