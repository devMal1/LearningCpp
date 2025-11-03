#include <iostream>
#include <cstdint>
#include <vector>
#include <array>
#include <span>

// S P A N
/*
Spans are a lightweight container that has read access to a sequence of values (Vector or array or etc.)

[Available since C++20]

Span Class:
    - size/lenght of the contiguous memory
    - ponter to the first element
*/

// void print_container(const std::vector<std::int32_t> &my_vector) {
//     for (const auto value : my_vector) {
//         std::cout << value << std::endl;
//     }
// }

// template <size_t N>
// void print_container(const std::array<std::int32_t, N> &my_array) {
//     for (const auto value : my_array) {
//         std::cout << value << std::endl;
//     }
// }

// Instead of having to overload, can use a span instead
void print_span(std::span<std::int32_t> my_span) {
    for (const auto value : my_span) {
        std::cout << value << std::endl;
    }
}

int main() {
    auto vector1 = std::vector<std::int32_t>{1, 2, 3};
    auto array2 = std::array<std::int32_t, 3>{1, 2, 3};

    print_span(vector1);
    print_span(array2);

    return 0;
}
