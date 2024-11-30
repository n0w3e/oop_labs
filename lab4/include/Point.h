#pragma once
#include <concepts>
#include <iostream>

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Point {
public:
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    T getX() const { return x; }
    T getY() const { return y; }

    void setX(T value) { x = value; }
    void setY(T value) { y = value; }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    friend bool operator==(const Point& lhs, const Point& rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

private:
    T x, y;
};
