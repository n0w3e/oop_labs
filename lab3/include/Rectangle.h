#pragma once
#include "Figure.h"

class Rectangle : public Figure {
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    std::vector<std::pair<double, double>> getVertices() const override;
    std::pair<double, double> getGeometricCenter() const override;
    double area() const override;
    Figure* clone() const override;

private:
    double width;
    double height;
};
