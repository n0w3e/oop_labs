#include "../include/Rectangle.h"

std::vector<std::pair<double, double>> Rectangle::getVertices() const {
    return {
        {0.0, 0.0},
        {width, 0.0},
        {width, height},
        {0.0, height}
    };
}

std::pair<double, double> Rectangle::getGeometricCenter() const {
    return {width / 2, height / 2};
}

double Rectangle::area() const {
    return width * height;
}

Figure* Rectangle::clone() const {
    return new Rectangle(*this);
}
