#include <type_traits>
#include <iostream>

// T Y P E  T R A I T S
/*
Type Traits offers a bunch of helper functions to determine the characteristics of a thing.

Which can be used to perform type checking when using generic types (templates).

This is the pre C++20 way of doing it though. Concepts are the C++20 way to do this.
*/

template <typename T>
struct is_numeric
    : public std::disjunction<std::is_integral<T>, std::is_floating_point<T>> {};

template <typename T>
T max1(const T &a, const T &b) {
    // static_assert is ran at compile time
    // in this case if T is not integral and not floating point, then assert will fail
    static_assert(std::disjunction_v<std::is_integral<T>, std::is_floating_point<T>>, "failed...");

    return (a > b) ? a : b;
}

template <typename T>
T max2(const T &a, const T &b) {
    static_assert(is_numeric<T>::value, "failed...");

    return (a > b) ? a : b;
}

// Setting return type to auto here, to let the compiler deduce the return type (at compile time)
template <typename T, typename U>
auto max3(const T &a, const U &b) {
    // This static assert checks that both T and U are numeric, and fails otherwise
    static_assert(std::conjunction_v<is_numeric<T>, is_numeric<U>>, "failed...");

    return (a > b) ? a : b;
}

int main() {
    std::cout << max1(10, 11) << std::endl;
    std::cout << max1(10.0F, 11.0F) << std::endl;
    std::cout << max1(10.0, 11.0) << std::endl;
    std::cout << max1<short>(10, 11) << std::endl;

    std::cout << max2(10, 11) << std::endl;
    std::cout << max2(10.0F, 11.0F) << std::endl;
    std::cout << max2(10.0, 11.0) << std::endl;
    std::cout << max2<short>(10, 11) << std::endl;

    std::cout << max3(10, 11.0) << std::endl;

    return 0;
}
