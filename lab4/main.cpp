#include "../include/Triangle.h"
#include "../include/Square.h"
#include "../include/Rectangle.h"
#include "../include/Array.h"

#include <iostream>
#include <memory>

template <typename T>
void printMenu() {
    std::cout << "Menu:\n"
              << "1. Add a Triangle\n"
              << "2. Add a Square\n"
              << "3. Add a Rectangle\n"
              << "4. Display all Figures\n"
              << "5. Calculate Total Area\n"
              << "6. Remove a Figure by Index\n"
              << "7. Exit\n"
              << "Enter your choice: ";
}

int main() {
    Array<std::shared_ptr<Figure<double>>> figures;
    bool running = true;

    while (running) {
        printMenu<double>();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double x1, y1, x2, y2, x3, y3;
                std::cout << "Enter coordinates of the three vertices (x1 y1 x2 y2 x3 y3): ";
                std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                auto triangle = std::make_shared<Triangle<double>>(
                    Point<double>(x1, y1), Point<double>(x2, y2), Point<double>(x3, y3));
                figures.add(triangle);
                break;
            }
            case 2: {
                double x, y, side;
                std::cout << "Enter bottom-left corner (x y) and side length: ";
                std::cin >> x >> y >> side;
                auto square = std::make_shared<Square<double>>(Point<double>(x, y), side);
                figures.add(square);
                break;
            }
            case 3: {
                double x, y, width, height;
                std::cout << "Enter bottom-left corner (x y), width, and height: ";
                std::cin >> x >> y >> width >> height;
                auto rectangle = std::make_shared<Rectangle<double>>(
                    Point<double>(x, y), width, height);
                figures.add(rectangle);
                break;
            }
            case 4: {
                std::cout << "Figures in Array:\n";
                figures.printAll();
                break;
            }
            case 5: {
                std::cout << "Total Area of all Figures: " << figures.totalArea() << "\n";
                break;
            }
            case 6: {
                size_t index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                try {
                    figures.remove(index);
                    std::cout << "Figure removed successfully.\n";
                } catch (const std::out_of_range& e) {
                    std::cerr << e.what() << "\n";
                }
                break;
            }
            case 7:
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
