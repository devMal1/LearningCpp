#include <concepts>
#include <iostream>
#include <string>

// C O N C E P T S
/*
Since C++20
*/

template <typename T>
concept Addable = requires(T x) {
    x + x;
};

template <typename T>
concept NonNumeric = !std::integral<T> && !std::floating_point<T>;

template <typename T>
concept Concatenable = Addable<T> && NonNumeric<T>;

template <typename T>
requires Concatenable<T>
T concat(const T &a, const T &b) {
    return a + b;
}

int main() {
    const auto part1 = std::string{"He"};
    const auto part2 = std::string{"llo"};

    std::cout << concat(part1, part2) << std::endl;

    // This errors because does not satisfy Concatenable concept (1 and 2 are both numeric)
    // std::cout << concat(1, 2) << std::endl;

    return 0;
}
