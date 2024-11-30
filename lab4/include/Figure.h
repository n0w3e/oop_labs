#pragma once
#include <iostream>
#include <memory>
#include "Point.h"

template <typename T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual std::shared_ptr<Point<T>> getCenter() const = 0;
    virtual operator double() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        os << "Figure at center: " << *figure.getCenter() << ", Area: " << static_cast<double>(figure);
        return os;
    }
};