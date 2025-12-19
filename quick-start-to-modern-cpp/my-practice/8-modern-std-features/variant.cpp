#include <iostream>
#include <string>

// V A R I A N T S
/*
Variants allow you to store one value for multiple data types (kind of like a union).

Since C++17
*/
int main() {
    auto v = std::variant<int, double, std::string>{42};
    // get the value from a variant
    auto i1 = std::get<int>(v);
    std::cout << i1 << std::endl;

    try {
        // this will not work, because 42 is an int not a double
        auto d1 = std::get<double>(v);
        std::cout << d1 << std::endl;
    } catch (std::bad_variant_access const &e) {
        std::cout << e.what() << std::endl;
    }

    v = 42.0;
    if (std::holds_alternative<double>(v)) {
        std::cout << std::get<double>(v) << std::endl;
    }

    return 0;
}
