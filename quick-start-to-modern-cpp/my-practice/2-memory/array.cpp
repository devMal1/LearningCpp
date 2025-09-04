#include <array>
#include <cstdint>
#include <iostream>

// c-style arrays decay to a pointer
void print_array_c(const std::int32_t *my_array, const std::uint32_t len) {
    for (std::uint32_t i = 0; i < len; i++) {
        std::cout << my_array[i] << std::endl;
    }
}

// c++-style array
template <std::size_t N>
void print_array_cpp(const std::array<std::int32_t, N> my_array) {
    for (std::uint32_t i = 0; i < my_array.size(); i++) {
        std::cout << my_array[i] << std::endl;
    }
}

int main() {
    constexpr auto len = 5u;
    std::int32_t nums[len] = {1, 2, 3, 4, 5}; // c-style array
    print_array_c(nums, len);

    // A R R A Y S
    auto nums2 = std::array<std::int32_t, len>{11, 12, 13, 14, 15}; // c++-style array
    print_array_cpp(nums2);

    return 0;
}
