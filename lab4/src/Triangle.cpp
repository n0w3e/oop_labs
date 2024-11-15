#include "../include/Triangle.h"
#include <cmath>
#include <stdexcept>

template <std::floating_point T>
Triangle<T>::Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    vertices[0] = std::make_unique<Point<T>>(a);
    vertices[1] = std::make_unique<Point<T>>(b);
    vertices[2] = std::make_unique<Point<T>>(c);
}

template <std::floating_point T>
T Triangle<T>::area() const {
    T x1 = vertices[0]->getX(), y1 = vertices[0]->getY();
    T x2 = vertices[1]->getX(), y2 = vertices[1]->getY();
    T x3 = vertices[2]->getX(), y3 = vertices[2]->getY();
    return std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

template <std::floating_point T>
Point<T> Triangle<T>::center() const {
    T x = (vertices[0]->getX() + vertices[1]->getX() + vertices[2]->getX()) / 3.0;
    T y = (vertices[0]->getY() + vertices[1]->getY() + vertices[2]->getY()) / 3.0;
    return Point<T>(x, y);
}

template <std::floating_point T>
void Triangle<T>::print(std::ostream& os) const {
    os << "Triangle: ";
    for (const auto& vertex : vertices) {
        os << *vertex << " ";
    }
}

template class Triangle<float>;
template class Triangle<double>;
