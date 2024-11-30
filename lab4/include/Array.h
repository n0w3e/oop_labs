#pragma once
#include <vector>
#include <memory>
#include "Figure.h"

template <typename T>
class Array {
    static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");

public:
    void add(std::shared_ptr<Figure<T>> figure) {
        figures.push_back(figure);
    }

    void remove(size_t index) {
        if (index < figures.size()) {
            figures.erase(figures.begin() + index);
        }
    }

    double getTotalArea() const {
        double totalArea = 0.0;
        for (const auto& figure : figures) {
            totalArea += static_cast<double>(*figure);
        }
        return totalArea;
    }

    void printDetails() const {
        for (size_t i = 0; i < figures.size(); ++i) {
            std::cout << "Figure " << i + 1 << ": " << *figures[i] << "\n";
        }
    }

private:
    std::vector<std::shared_ptr<Figure<T>>> figures;
};