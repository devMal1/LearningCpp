#include <cstdint>
#include <iostream>


enum Shape {
    Rectangle,
    Square,
    Triangle,
    Circle
};

// S T R U C T S
/* Structs vs. Classes
- Structs and classes are virtually the same in C++
- As a best practice/convention Structs are used when only representing data (not methods) - i.e. Plain Old Data (POD)
- And classes are used when data + methods are needed
*/
struct Icon {
    Shape shape;
    std::uint32_t size;
};

int main() {
    Icon basketball = {Shape::Circle, 50u};

    // C++20 adds a named way of creating structs
    Icon box = {.shape=Shape::Square, .size=30u};

    // Enums are implicitly casted to a std::uint32_t
    // An explicit cast in C++ looks like: static_cast<std::uint32_t>(basketball.shape)
    std::cout << basketball.shape << std::endl;
    std::cout << box.size << std::endl;

    return 0;
}
