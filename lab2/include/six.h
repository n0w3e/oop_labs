#pragma once
#include <stdexcept>
#include <iostream>

class Six {
public:
    Six();
    Six(const unsigned char* input_digits, unsigned long input_size);
    Six(const Six& other);
    ~Six();

    Six& operator+=(const Six& other);
    Six& operator-=(const Six& other);
    Six& operator=(const Six& other);

    bool operator==(const Six& other) const;
    bool operator!=(const Six& other) const;
    bool operator<(const Six& other) const;
    bool operator>(const Six& other) const;

private:
    unsigned char* digits;
    unsigned long size; 
    unsigned long capacity;

    void resize(size_t newCapacity);
};
