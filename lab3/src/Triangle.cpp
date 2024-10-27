#include "../include/Triangle.h"
#include <cmath>

std::vector<std::pair<double, double>> Triangle::getVertices() const {
    double height = (std::sqrt(3) / 2) * sideLength;
    return {
        {0.0, 0.0},
        {sideLength / 2, height},
        {sideLength, 0.0}
    };
}

std::pair<double, double> Triangle::getGeometricCenter() const {
    double height = (std::sqrt(3) / 2) * sideLength;
    return {sideLength / 2, height / 3};
}

double Triangle::area() const {
    return (std::sqrt(3) / 4) * sideLength * sideLength;
}

Figure* Triangle::clone() const {
    return new Triangle(*this);
}
