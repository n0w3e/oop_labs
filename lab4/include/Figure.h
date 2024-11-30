#pragma once
#include <concepts>
#include <iostream>
#include "Point.h"

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual T getArea() const = 0;
    virtual std::shared_ptr<Point<T>> getCenter() const = 0;
    virtual void print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        figure.print(os);
        return os;
    }
};
