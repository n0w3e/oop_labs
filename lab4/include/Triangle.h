#pragma once
#include "Figure.h"

template <Scalar T>
class Triangle : public Figure<T> {
public:
    Triangle(Point<T> a, Point<T> b, Point<T> c)
        : vertices{std::make_unique<Point<T>>(a),
                   std::make_unique<Point<T>>(b),
                   std::make_unique<Point<T>>(c)} {}

    std::vector<std::unique_ptr<Point<T>>> getVertices() const override {
        std::vector<std::unique_ptr<Point<T>>> copy;
        for (const auto& vertex : vertices) {
            copy.push_back(std::make_unique<Point<T>>(*vertex));
        }
        return copy;
    }

    std::unique_ptr<Point<T>> getGeometricCenter() const override {
        T x = 0, y = 0;
        for (const auto& vertex : vertices) {
            x += vertex->getX();
            y += vertex->getY();
        }
        return std::make_unique<Point<T>>(x / 3, y / 3);
    }

    double area() const override {
        T x1 = vertices[0]->getX(), y1 = vertices[0]->getY();
        T x2 = vertices[1]->getX(), y2 = vertices[1]->getY();
        T x3 = vertices[2]->getX(), y3 = vertices[2]->getY();
        return std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
    }

    Triangle* clone() const override {
        return new Triangle(*vertices[0], *vertices[1], *vertices[2]);
    }

private:
    std::vector<std::unique_ptr<Point<T>>> vertices;
};
