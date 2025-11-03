#include <iostream>
#include <cstdint>
#include <span>
#include <vector>
#include <array>

// T E M P L A T E  F U N C T I O N S
/*
To be used when overloading functions, where the bodies of those functions have the
same implementation.
*/

template <typename T>
void print_container(std::span<T> span) {
    for (const auto value : span) {
        std::cout << value << std::endl;
    }
}

int main() {
    auto my_vec = std::vector<std::int32_t>{1, 2, 3, 4, 5};
    auto my_arr = std::array<std::uint16_t, 3u>{7, 8, 9};
    std::uint64_t my_carray[] = {5, 10, 15, 20};

    print_container<std::int32_t>(my_vec);
    print_container<std::uint16_t>(my_arr);
    print_container<std::uint64_t>(my_carray);

    return 0;
}
