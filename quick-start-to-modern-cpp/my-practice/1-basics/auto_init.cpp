#include <cstdint>
#include <iostream>

/*
Common Principles:
- AAA (Almost Always Auto) - use it as much as possible without ambiguity
- DRY (Don't Repeat Yourself) - even within a decleration and initialization
- Avoid implicit conversions i.e. only use explicit conversions
*/

int main() {
    float f = 10.5; // implicit conversion (double to float)
    // float f = 10.5f; // (no conversion since specified that it is a float with 'f')

    std::int32_t s = f; // implicit conversion (float to int32)

    // A U T O
    auto a = static_cast<std::int32_t>(f); // explicit conversion (float to int32)
    // std::int32_t a = static_cast<std::int32_t>(f); // this repeats the type which violates DRY (and lends toward AAA)

    auto u = std::int32_t{f}; // uniform init
    auto t = std::int32_t{}; // unfirom init, setting the default value for the type

    return 0;
}
