#include "../include/Square.h"

template <std::floating_point T>
Square<T>::Square(const Point<T>& bottomLeft, T sideLength) {
    if (sideLength <= 0) {
        throw std::invalid_argument("Side length must be positive.");
    }

    vertices[0] = std::make_unique<Point<T>>(bottomLeft);
    vertices[1] = std::make_unique<Point<T>>(bottomLeft.getX() + sideLength, bottomLeft.getY());
    vertices[2] = std::make_unique<Point<T>>(bottomLeft.getX() + sideLength, bottomLeft.getY() + sideLength);
    vertices[3] = std::make_unique<Point<T>>(bottomLeft.getX(), bottomLeft.getY() + sideLength);
}

template <std::floating_point T>
T Square<T>::area() const {
    T sideLength = vertices[1]->getX() - vertices[0]->getX();
    return sideLength * sideLength;
}

template <std::floating_point T>
Point<T> Square<T>::center() const {
    T x = (vertices[0]->getX() + vertices[2]->getX()) / 2.0;
    T y = (vertices[0]->getY() + vertices[2]->getY()) / 2.0;
    return Point<T>(x, y);
}

template <std::floating_point T>
void Square<T>::print(std::ostream& os) const {
    os << "Square: ";
    for (const auto& vertex : vertices) {
        os << *vertex << " ";
    }
}

template class Square<float>;
template class Square<double>;
