#pragma once
#include <memory>
#include <vector>
#include "Point.h"

template <Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual std::vector<std::unique_ptr<Point<T>>> getVertices() const = 0;
    virtual std::unique_ptr<Point<T>> getGeometricCenter() const = 0;
    virtual double area() const = 0;

    virtual Figure* clone() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        os << "Vertices: ";
        for (const auto& vertex : figure.getVertices()) {
            os << *vertex << " ";
        }
        return os;
    }
};
