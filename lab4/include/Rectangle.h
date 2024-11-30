#pragma once
#include "Figure.h"

template <typename T>
class Rectangle : public Figure<T> {
    static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");

public:
    Rectangle(const Point<T>& topLeft, T width, T height)
        : topLeft(topLeft), width(width), height(height) {}

    std::shared_ptr<Point<T>> getCenter() const override {
        T centerX = topLeft.getX() + width / 2;
        T centerY = topLeft.getY() - height / 2;
        return std::make_shared<Point<T>>(centerX, centerY);
    }

    operator double() const override {
        return static_cast<double>(width * height);
    }

private:
    Point<T> topLeft;
    T width, height;
};