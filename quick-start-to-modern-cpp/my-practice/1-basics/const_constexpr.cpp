#include <cstdint>
#include <iostream>

// C O N S T
std::uint64_t faculty(const std::uint8_t n) {
    // n! = n * (n - 1) * (n - 2) * ... * 1

    auto result = std::uint64_t{1};

    for (std::uint8_t i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

// C O N S T E P R
constexpr std::uint64_t faculty_2(const std::uint8_t n) {
    auto result = std::uint64_t{1};

    for (std::uint8_t i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    auto result1 = faculty(5u); // computed at runtime

    constexpr auto restult2 = faculty_2(5u); // computed at compile time
    constexpr auto e = 5 * 4 * 2; // computed at compile time

    return 0;
}
