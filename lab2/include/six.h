#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

class Six {
public:
    Six();
    Six(const std::vector<unsigned char>& digits); 
    Six(const Six& other);
    Six(Six&& other) noexcept;
    ~Six();

    Six& operator+=(const Six& other);
    Six& operator-=(const Six& other);

    bool operator==(const Six& other) const;
    bool operator!=(const Six& other) const;
    bool operator<(const Six& other) const;
    bool operator>(const Six& other) const;

private:
    std::vector<unsigned char> digits;
};
