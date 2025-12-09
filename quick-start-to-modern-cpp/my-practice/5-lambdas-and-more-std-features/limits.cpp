#include <limits>
#include <cstdint>
#include <iostream>
#include <cmath>

// N U M E R I C  L I M I T S
/*
Gives information about numeric types.
*/

template <typename T>
void print_type_properties() {
    std::cout << "min=" << std::numeric_limits<T>::min() << std::endl
              << "max=" << std::numeric_limits<T>::max() << std::endl
              << "bits=" << std::numeric_limits<T>::digits << std::endl
              << "decdigits=" << std::numeric_limits<T>::digits10 << std::endl
              << "integral=" << std::boolalpha << std::numeric_limits<T>::is_integer << std::endl
              << "signed=" << std::boolalpha << std::numeric_limits<T>::is_signed << std::endl
              << "exact=" << std::boolalpha << std::numeric_limits<T>::is_exact << std::endl
              << "infinity=" << std::boolalpha << std::numeric_limits<T>::has_infinity << std::endl << std::endl;
}

template <typename T>
bool equal(const T value1, const T value2) {
    return value1 == value2;
}

template <typename T>
bool almost_equal(const T value1, const T value2) {
    return std::abs(value2 - value1) <= std::numeric_limits<T>::epsilon();
}

int main() {
    print_type_properties<std::uint16_t>();
    print_type_properties<std::int32_t>();
    print_type_properties<float>();

    // Case study to show that in programming floats (and doubles) should not be compared with equality
    // because real numbers (in programming) are not exact
    const auto d1 = 0.2;
    const auto d2 = 1.0 / (std::sqrt(5.0) * std::sqrt(5.0)); // == 1 / 5

    // printing, rounds, so d1 and d2 looks like they are equal, but they are not =
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;

    // if we set the precision to be much larger, we will see that they are not equal
    std::cout.precision(17);
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;

    std::cout << "d1 == d2? " << std::boolalpha << equal(d1, d2) << std::endl;

    std::cout << "epsilon = " << std::numeric_limits<float>::epsilon() << std::endl;
    std::cout << "d1 ~= d2? " << std::boolalpha << almost_equal(d1, d2) << std::endl;

    return 0;
}
