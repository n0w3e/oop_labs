#include <iostream>
#include <memory>
#include "Point.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Array.h"

int main() {
    using ScalarType = double;

    auto triangle = std::make_shared<Triangle<ScalarType>>(
        Point<ScalarType>(0, 0),
        Point<ScalarType>(4, 0),
        Point<ScalarType>(2, 3)
    );

    auto rectangle = std::make_shared<Rectangle<ScalarType>>(
        Point<ScalarType>(1, 5), 4, 3
    );

    auto square = std::make_shared<Square<ScalarType>>(
        Point<ScalarType>(-3, -3), 2
    );

    Array<ScalarType> figures;
    figures.add(triangle);
    figures.add(rectangle);
    figures.add(square);

    std::cout << "Details of figures:\n";
    figures.printDetails();

    std::cout << "\nTotal area of all figures: " << figures.getTotalArea() << "\n";

    std::cout << "\nRemoving the first figure...\n";
    figures.remove(0);

    std::cout << "Updated details of figures:\n";
    figures.printDetails();

    return 0;
}
