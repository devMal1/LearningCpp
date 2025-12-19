#include <iostream>
#include <string>

// Allows appending 's' to a literal string
using namespace std::string_literals;

// O P T I O N A L
/*
Since C++17
*/
std::optional<std::string> check(const bool flag) {
    if (flag) {
        return "good to go"s;
    }

    return {}; // std::nullopt
}


int main() {
    auto v1 = std::optional<int>{34};

    // Can use dereferencing to get the value (this is not a pointer)
    std::cout << *v1 << std::endl;

    auto v2 = std::optional<std::string>{"testing"s};
    // Can use the value method to get the value
    std::cout << v2.value() << std::endl;

    auto v3 = std::optional<std::string>{};
    // Can use value_or to return a default value if no value exists
    std::cout << v3.value_or("Default"s) << std::endl;
    // Can check if value exists
    std::cout << std::boolalpha << v3.has_value() << std::endl;

    return 0;
}
