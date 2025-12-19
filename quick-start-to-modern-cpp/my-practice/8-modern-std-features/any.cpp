#include <iostream>
#include <string>
#include <any>

using namespace std::string_literals;

// A N Y

bool is_integer(const std::any &a) {
    return a.type() == typeid(int);
}

bool is_string(const std::any &a) {
    return a.type() == typeid(std::string);
}

int main() {
    auto a = std::any{42}; // int 42
    std::cout << sizeof(a) << std::endl;
    a = 42.0; // double 42.0
    std::cout << sizeof(a) << std::endl;
    a = "42"s;
    std::cout << sizeof(a) << std::endl;

    try {
        // This will not work casting the string to double
        auto d = std::any_cast<double>(a);
        std::cout << d << std::endl;
    } catch (std::bad_any_cast const &e) {
        std::cout << e.what() << std::endl;
    }

    // Can check any is of a certain type with the type method
    std::cout << std::boolalpha << is_integer(a) << std::endl;
    std::cout << std::boolalpha << is_string(a) << std::endl;

    // Can check any has a value with the has_value method
    auto ltest = [](const std::any &val) { return val.has_value(); };
    std::cout << std::boolalpha << ltest(a) << std::endl;

    // Can use any_cast to cast to the value type and get actual value
    auto s = std::any_cast<std::string>(a);
    std::cout << s << std::endl;

    return 0;
}
