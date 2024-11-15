#ifndef FIGURE_H
#define FIGURE_H

#include "../include/Point.h"
#include <memory>
#include <iostream>
#include <vector>

template <std::floating_point T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual T area() const = 0;
    virtual Point<T> center() const = 0;
    virtual void print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        figure.print(os);
        return os;
    }
};

#endif
