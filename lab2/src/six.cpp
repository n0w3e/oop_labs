#include "../include/six.h"
#include <algorithm>

Six::Six() : digits(new unsigned char[1]{0}), size(1), capacity(1) {}

Six::Six(const unsigned char* input_digits, unsigned long size) {
    if (size == 0 || input_digits == nullptr) {
        throw std::invalid_argument("Invalid input for Six number");
    }

    digits = new unsigned char[size];
    this->size = size;
    capacity = size;

    for (unsigned long i = 0; i < size; ++i) {
        if (input_digits[i] > 5) {
            delete[] digits;
            throw std::invalid_argument("Invalid digit in six-base number");
        }
        digits[i] = input_digits[i];
    }
}


Six::Six(const Six& other) {
    size = other.size;
    capacity = other.capacity;
    digits = new unsigned char[capacity];
    std::copy(other.digits, other.digits + size, digits);
}

Six& Six::operator=(const Six& other) {
    if (this != &other) {
        delete[] digits;
        size = other.size;
        capacity = other.capacity;
        digits = new unsigned char[capacity];
        std::copy(other.digits, other.digits + size, digits);
    }
    return *this;
}

Six::~Six() {
    delete[] digits;
}

void Six::resize(size_t newCapacity) {
    if (newCapacity <= capacity) return;
    unsigned char* newDigits = new unsigned char[newCapacity];
    std::copy(digits, digits + size, newDigits);
    delete[] digits;
    digits = newDigits;
    capacity = newCapacity;
}

Six& Six::operator+=(const Six& other) {
    int carry = 0;
    size_t maxSize = std::max(size, other.size);
    if (capacity < maxSize) {
        resize(maxSize + 1);
    }

    for (size_t i = 0; i < maxSize; ++i) {
        int digit1 = (i < size) ? digits[i] : 0;
        int digit2 = (i < other.size) ? other.digits[i] : 0;

        int sum = digit1 + digit2 + carry;

        if (sum >= 6) {
            carry = sum / 6;
            sum = sum % 6;
        } else {
            carry = 0;
        }

        if (i < size) {
            digits[i] = sum;
        } else {
            digits[size++] = sum;
        }
    }

    if (carry > 0) {
        if (size >= capacity) {
            resize(capacity + 1);
        }
        digits[size++] = carry;
    }

    return *this;
}

Six& Six::operator-=(const Six& other) {
    int borrow = 0;
    for (size_t i = 0; i < size; ++i) {
        int digit1 = digits[i];
        int digit2 = (i < other.size) ? other.digits[i] : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 6;
            borrow = 1;
        } else {
            borrow = 0;
        }

        digits[i] = diff;
    }

    while (size > 1 && digits[size - 1] == 0) {
        --size;
    }

    return *this;
}

bool Six::operator==(const Six& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; ++i) {
        if (digits[i] != other.digits[i]) return false;
    }
    return true;
}

bool Six::operator!=(const Six& other) const {
    return !(*this == other);
}

bool Six::operator<(const Six& other) const {
    if (size != other.size) return size < other.size;
    for (unsigned long i = 0; i < size; ++i) {
        if (digits[i] != other.digits[i]) return digits[i] < other.digits[i];
    }
    return false;
}

bool Six::operator>(const Six& other) const {
    return other < *this;
}
