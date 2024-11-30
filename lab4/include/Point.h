#pragma once
#include <iostream>
#include <type_traits>

template <typename T>
class Point {
    static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");

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