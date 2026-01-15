#include <iostream>
#include <format>


// F O R M A T
/*
Used to format and convert to string.

Since C++20.
*/

int main() {
    // Initial data to work with (name, lastname, age)
    const auto name = "Steph";
    const auto lastname = "Curry";
    const auto age = 37u;

    // Example of using string concatenation
    const auto statement = std::string{name} + std::string{lastname} + std::to_string(age);
    std::cout << statement << std::endl;

    // Example of using format
    // The indices within the brackets specify which argument goes in which spot
    // (you can omit the numbers/indices to have it formatted in the order of the parameters
    const auto statement2 = std::format("{1}, {0} is {2}", name, lastname, age);
    std::cout << statement2 << std::endl;

    // Example of using format with hexadecimal
    std::cout << std::format("{0} hex is {0:08x}", age) << std::endl;

    // Example of using format_to_n with c-style string
    // If you needed to use c-style for some library that only supports c-style strings
    char buff[100]{};
    std::format_to_n(buff, sizeof(buff), "{} is {}", name, age);
    std::cout << buff << std::endl;

    return 0;
}
