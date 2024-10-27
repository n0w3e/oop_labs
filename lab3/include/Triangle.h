#pragma once
#include "Figure.h"

class Triangle : public Figure {
public:
    Triangle(double sideLength) : sideLength(sideLength) {}
    
    std::vector<std::pair<double, double>> getVertices() const override;
    std::pair<double, double> getGeometricCenter() const override;
    double area() const override;
    Figure* clone() const override;

private:
    double sideLength;
};