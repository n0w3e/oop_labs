#pragma once
#include "Figure.h"

template <Scalar T>
class Square : public Figure<T> {
public:
    Square(Point<T> center, T side)
        : center(std::make_unique<Point<T>>(center)), side(side) {}

    std::vector<std::unique_ptr<Point<T>>> getVertices() const override {
        std::vector<std::unique_ptr<Point<T>>> vertices;
        T halfSide = side / 2;

        vertices.push_back(std::make_unique<Point<T>>(center->getX() - halfSide, center->getY() - halfSide));
        vertices.push_back(std::make_unique<Point<T>>(center->getX() + halfSide, center->getY() - halfSide));
        vertices.push_back(std::make_unique<Point<T>>(center->getX() + halfSide, center->getY() + halfSide));
        vertices.push_back(std::make_unique<Point<T>>(center->getX() - halfSide, center->getY() + halfSide));

        return vertices;
    }

    std::unique_ptr<Point<T>> getGeometricCenter() const override {
        return std::make_unique<Point<T>>(*center);
    }

    double area() const override {
        return static_cast<double>(side * side);
    }

    Square* clone() const override {
        return new Square(*center, side);
    }

private:
    std::unique_ptr<Point<T>> center;
    T side;
};
