#pragma once
#include <concepts>
#include <iostream>
#include "Point.h"
#include "Figure.h"

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Triangle : public Figure<T> {
public:
    Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c)
        : a(a), b(b), c(c) {}

    T getArea() const override {
        return std::abs((a.getX() * (b.getY() - c.getY()) +
                         b.getX() * (c.getY() - a.getY()) +
                         c.getX() * (a.getY() - b.getY())) /
                        2);
    }

    std::shared_ptr<Point<T>> getCenter() const override {
        T x = (a.getX() + b.getX() + c.getX()) / 3;
        T y = (a.getY() + b.getY() + c.getY()) / 3;
        return std::make_shared<Point<T>>(x, y);
    }

    void print(std::ostream& os) const override {
        os << "Triangle: Area = " << getArea();
    }

private:
    Point<T> a, b, c;
};
