#pragma once
#include "Figure.h"

template <Scalar T>
class Rectangle : public Figure<T> {
public:
    Rectangle(Point<T> center, T width, T height)
        : center(std::make_unique<Point<T>>(center)), width(width), height(height) {}

    std::vector<std::unique_ptr<Point<T>>> getVertices() const override {
        std::vector<std::unique_ptr<Point<T>>> vertices;
        T halfWidth = width / 2;
        T halfHeight = height / 2;

        vertices.push_back(std::make_unique<Point<T>>(center->getX() - halfWidth, center->getY() - halfHeight));
        vertices.push_back(std::make_unique<Point<T>>(center->getX() + halfWidth, center->getY() - halfHeight));
        vertices.push_back(std::make_unique<Point<T>>(center->getX() + halfWidth, center->getY() + halfHeight));
        vertices.push_back(std::make_unique<Point<T>>(center->getX() - halfWidth, center->getY() + halfHeight));

        return vertices;
    }

    std::unique_ptr<Point<T>> getGeometricCenter() const override {
        return std::make_unique<Point<T>>(*center);
    }

    double area() const override {
        return static_cast<double>(width * height);
    }

    Rectangle* clone() const override {
        return new Rectangle(*center, width, height);
    }

private:
    std::unique_ptr<Point<T>> center;
    T width, height;
};
