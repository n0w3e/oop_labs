#include <iostream>
#include <memory>
#include "Point.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Array.h"

int main() {
    auto triangle = std::make_shared<Triangle<double>>(
        Point<double>(0.0, 0.0),
        Point<double>(1.0, 0.0),
        Point<double>(0.0, 1.0)
    );

    auto rectangle = std::make_shared<Rectangle<double>>(
        Point<double>(0.0, 0.0),
        2.0,
        3.0
    );

    auto square = std::make_shared<Square<double>>(
        Point<double>(0.0, 0.0),
        2.0
    );

    Array<double> figureArray;
    figureArray.add(triangle);
    figureArray.add(rectangle);
    figureArray.add(square);

    std::cout << "Details of figures:\n";
    figureArray.printDetails();

    std::cout << "\nTotal Area of Figures: " << figureArray.getTotalArea() << "\n";

    figureArray.remove(0);
    std::cout << "\nAfter removing the first figure:\n";
    figureArray.printDetails();

    return 0;
}
