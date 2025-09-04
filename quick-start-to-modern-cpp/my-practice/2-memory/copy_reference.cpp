#include <iostream>
#include <cstdint>
#include <array>

// C O P Y  B Y  R E F E R E N C E S
/*
A pointer is 8 bytes (on 64-bit machines), and so if your data
is less than 8 bytes, it would not be more efficient to copy by reference.
Thus, in general, if your data is less than 8 bytes, just copy by value (unless you want to modify it directly).

Also you can use the `&` in front of a variable to access its memory address
*/

/*
When the parameter is only input (not used as output) then:
  - if greater than 8-bytes, use copy by reference
  - use const (since just read only - not used as output)
*/
template <std::size_t N>
void print_array(const std::array<std::uint32_t, N> &nums) {
    for (uint32_t i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << std::endl;
    }
}

/*
When the parameter is used as input and output then:
  - copy by reference
  - do not use const
*/
template <std::size_t N>
void double_array(std::array<std::uint32_t, N> &nums) {
    for (uint32_t i = 0; i < nums.size(); i++) {
        nums[i] = nums[i] * 2;
    }
}

int main() {
    auto nums = std::array<std::uint32_t, 5u>{1, 2, 3, 4, 5};
    print_array(nums);

    double_array(nums);
    print_array(nums);

    return 0;
}
