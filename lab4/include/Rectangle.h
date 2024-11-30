#pragma once
#include <concepts>
#include <iostream>
#include "Point.h"
#include "Figure.h"

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Rectangle : public Figure<T> {
public:
    Rectangle(const Point<T>& topLeft, T width, T height)
        : topLeft(topLeft), width(width), height(height) {}

    T getArea() const override {
        return width * height;
    }

    std::shared_ptr<Point<T>> getCenter() const override {
        T x = topLeft.getX() + width / 2;
        T y = topLeft.getY() - height / 2;
        return std::make_shared<Point<T>>(x, y);
    }

    void print(std::ostream& os) const override {
        os << "Rectangle: Area = " << getArea();
    }

private:
    Point<T> topLeft;
    T width, height;
};
