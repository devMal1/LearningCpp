#include <iostream>
#include <vector>
#include <string_view>
#include <ranges>
#include <algorithm>

// R A N G E S
/*
Since C++20
*/

auto print = [](const auto &view) {
    std::cout << "{ ";
    for (const auto el: view) {
        std::cout << el << " ";
    }
    std::cout << "}";
};

int main() {
    // Create a vector to use for example
    const auto numbers1 = std::vector<int>{1, 2, 3, 4, 5, 6};

    // Reverse, Drop, Take, Transform, Filter
    auto ranged_numbers1 = std::views::reverse(numbers1) |
        std::views::drop(2) | std::views::take(3) |
        std::views::transform([](const auto val) { return val * 2; }) |
        std::views::filter([](const auto val) { return val % 2 == 0; });

    // Print out the example array and the ranged (transformed) vector
    for (const auto val: numbers1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    for (const auto val: ranged_numbers1) {
        std::cout << val << "";
    }
    std::cout << std::endl;

    // Create a new vector to use for example
    const auto numbers2 = std::vector<int>{1, 2, 3, 4, 5, 6};
    // Filter and Transform
    auto ranged_numbers2 = numbers2 |
        std::views::filter([](const auto n) { return n % 2 == 0;}) |
        std::views::transform([](const auto n) { return n * 2; });

    // Print out new example vector
    for (const auto val: ranged_numbers2) {
        std::cout << val << "";
    }
    std::cout << std::endl;

    // Split (on a string) and print it out
    constexpr auto hello = std::string_view{"Hello C++20 !"};
    auto res = hello | std::ranges::views::split(' ');
    std::cout << "substrings: ";
    std::ranges::for_each(res, print);

    return 0;
}
