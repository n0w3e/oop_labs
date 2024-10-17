#include "../include/six.h"

Six::Six() : digits(1, 0) {}

Six::Six(const std::vector<unsigned char>& digits) : digits(digits) {
    for (auto digit : digits) {
        if (digit > 5) {
            throw std::invalid_argument("Invalid digit in six-base number");
        }
    }
}

Six::Six(const Six& other) : digits(other.digits) {}

Six::Six(Six&& other) noexcept : digits(std::move(other.digits)) {}

Six::~Six() {}

Six& Six::operator+=(const Six& other) {
    int carry = 0;
    size_t maxSize = std::max(digits.size(), other.digits.size());

    for (size_t i = 0; i < maxSize; ++i) {
        int digit1 = (i < digits.size()) ? digits[i] : 0;
        int digit2 = (i < other.digits.size()) ? other.digits[i] : 0;

        int sum = digit1 + digit2 + carry;

        if (sum >= 6) {
            carry = sum / 6;
            sum = sum % 6;
        } else {
            carry = 0;
        }

        if (i < digits.size()) {
            digits[i] = sum;
        } else {
            digits.push_back(sum);
        }
    }

    if (carry > 0) {
        digits.push_back(carry);
    }

    return *this;
}


Six& Six::operator-=(const Six& other) {
    int borrow = 0;
    for (int i = 0; i < digits.size(); ++i) {
        int digit1 = digits[i];
        int digit2 = i < other.digits.size() ? other.digits[i] : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 6;
            borrow = 1;
        } else {
            borrow = 0;
        }

        digits[i] = diff;
    }

    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }

    return *this;
}   

bool Six::operator==(const Six& other) const {
    if (digits.size() != other.digits.size()) return false;
    for (size_t i = 0; i < digits.size(); ++i) {
        if (digits[i] != other.digits[i]) return false;
    }
    return true;
}


bool Six::operator!=(const Six& other) const {
    return !(*this == other);
}

bool Six::operator<(const Six& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    return false;
}

bool Six::operator>(const Six& other) const {
    return other < *this;
}