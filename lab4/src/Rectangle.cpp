#include "../include/Rectangle.h"

template <std::floating_point T>
Rectangle<T>::Rectangle(const Point<T>& bottomLeft, T width, T height) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Width and height must be positive.");
    }

    vertices[0] = std::make_unique<Point<T>>(bottomLeft);
    vertices[1] = std::make_unique<Point<T>>(bottomLeft.getX() + width, bottomLeft.getY());
    vertices[2] = std::make_unique<Point<T>>(bottomLeft.getX() + width, bottomLeft.getY() + height);
    vertices[3] = std::make_unique<Point<T>>(bottomLeft.getX(), bottomLeft.getY() + height);
}

template <std::floating_point T>
T Rectangle<T>::area() const {
    T width = vertices[1]->getX() - vertices[0]->getX();
    T height = vertices[3]->getY() - vertices[0]->getY();
    return width * height;
}

template <std::floating_point T>
Point<T> Rectangle<T>::center() const {
    T x = (vertices[0]->getX() + vertices[2]->getX()) / 2.0;
    T y = (vertices[0]->getY() + vertices[2]->getY()) / 2.0;
    return Point<T>(x, y);
}

template <std::floating_point T>
void Rectangle<T>::print(std::ostream& os) const {
    os << "Rectangle: ";
    for (const auto& vertex : vertices) {
        os << *vertex << " ";
    }
}

template class Rectangle<float>;
template class Rectangle<double>;
