#pragma once
#include "Figure.h"

template <typename T>
class Triangle : public Figure<T> {
    static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");

public:
    Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c)
        : a(a), b(b), c(c) {}

    std::shared_ptr<Point<T>> getCenter() const override {
        T centerX = (a.getX() + b.getX() + c.getX()) / 3;
        T centerY = (a.getY() + b.getY() + c.getY()) / 3;
        return std::make_shared<Point<T>>(centerX, centerY);
    }

    operator double() const override {
        T area = std::abs((a.getX() * (b.getY() - c.getY()) +
                           b.getX() * (c.getY() - a.getY()) +
                           c.getX() * (a.getY() - b.getY())) /
                          2.0);
        return static_cast<double>(area);
    }

private:
    Point<T> a, b, c;
};
