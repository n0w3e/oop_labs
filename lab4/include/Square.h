#ifndef SQUARE_H
#define SQUARE_H

#include "../include/Figure.h"
#include <array>

template <std::floating_point T>
class Square : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 4> vertices;

public:
    Square(const Point<T>& bottomLeft, T sideLength);

    T area() const override;
    Point<T> center() const override;
    void print(std::ostream& os) const override;
};

#endif
