#include "../include/Square.h"

std::vector<std::pair<double, double>> Square::getVertices() const {
    return {
        {0.0, 0.0},
        {sideLength, 0.0},
        {sideLength, sideLength},
        {0.0, sideLength}
    };
}

std::pair<double, double> Square::getGeometricCenter() const {
    return {sideLength / 2, sideLength / 2};
}

double Square::area() const {
    return sideLength * sideLength;
}

Figure* Square::clone() const {
    return new Square(*this);
}
