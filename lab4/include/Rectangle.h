#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../include/Figure.h"
#include <array>

template <std::floating_point T>
class Rectangle : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 4> vertices;

public:
    Rectangle(const Point<T>& bottomLeft, T width, T height);

    T area() const override;
    Point<T> center() const override;
    void print(std::ostream& os) const override;
};

#endif
