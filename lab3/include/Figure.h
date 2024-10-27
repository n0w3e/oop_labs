#pragma once
#include <iostream>
#include <vector>
#include <utility>

class Figure {
public:
    virtual ~Figure() = default;

    virtual std::vector<std::pair<double, double>> getVertices() const = 0;
    virtual std::pair<double, double> getGeometricCenter() const = 0;
    virtual double area() const = 0;
    virtual Figure* clone() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        auto vertices = figure.getVertices();
        os << "Vertices: ";
        for (const auto& vertex : vertices) {
            os << "(" << vertex.first << ", " << vertex.second << ") ";
        }
        return os;
    }
};
