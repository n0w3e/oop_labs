#ifndef POINT_H
#define POINT_H

#include <concepts>
#include <memory>
#include <iostream>

template <std::floating_point T>
class Point {
private:
    T x, y;

public:
    Point(T x = 0, T y = 0);

    T getX() const;
    T getY() const;

    void setX(T x);
    void setY(T y);

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

#endif
