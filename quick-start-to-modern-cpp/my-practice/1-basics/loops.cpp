#include <cstdint>
#include <iostream>

int main() {
    // F O R
    for (std::uint32_t i = 0u; i < 3u; i++) { // post increment
        std::cout << i << std::endl;
    }

    for (std::uint32_t i = 0u; i < 3u; ++i) { // pre increment
        std::cout << i << std::endl;
    }

    for (std::uint32_t i = 3u; i > 0u; i--) {
        std::cout << i << std::endl;
    }

    for (std::uint32_t i = 3u; i > 0u; --i) {
        std::cout << i << std::endl;
    }

    // * Typically you are going to want to use pre increment/decrement
    std::int32_t i = 1;
    std::int32_t result = ++i;
    std::cout << std::endl << result << std::endl;

    // W H I L E
    while (true) {
        if (i > 3) {
            break;
        }
        ++i;
    }

    // D O  W H I L E
    do {
        if (i > 3) {
            break;
        }
        ++i;
    } while (true);

    return 0;
}
