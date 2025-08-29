#include <cstdint>
#include <iostream>

std::uint64_t faculty(const std::uint8_t n) {
    // S T A T I C
    static auto result = std::uint64_t{1}; // only initialized once throughout the program execution

    for (std::uint8_t i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    const auto value1 = faculty(5);
    std::cout << value1 << std::endl;
    const auto value2 = faculty(5); // this ends up being faculty(5) * faculty(5) because result is not re-initialized
    std::cout << value2 << std::endl;

    return 0;
}
