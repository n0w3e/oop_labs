#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../include/Figure.h"
#include <array>

template <std::floating_point T>
class Triangle : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 3> vertices;

public:
    Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c);

    T area() const override;
    Point<T> center() const override;
    void print(std::ostream& os) const override;
};

#endif
