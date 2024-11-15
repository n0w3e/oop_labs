#include "../include/Point.h"

template <std::floating_point T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template <std::floating_point T>
T Point<T>::getX() const {
    return x;
}

template <std::floating_point T>
T Point<T>::getY() const {
    return y;
}

template <std::floating_point T>
void Point<T>::setX(T x) {
    this->x = x;
}

template <std::floating_point T>
void Point<T>::setY(T y) {
    this->y = y;
}

template class Point<float>;
template class Point<double>;
