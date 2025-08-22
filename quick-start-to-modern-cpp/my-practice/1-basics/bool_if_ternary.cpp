#include <cstdint>
#include <iostream>

int main() {
    // B O O L E A N S
    bool b1 = true;
    bool b2 = false;

    // I f
    if (b1) {
        std::cout << "Printing a test phrase\n";
    } else if (!b2) {
        std::cout << "Not printing a test phrase\n";
    } else {
        std::cout << "Doing something else then\n";
    }

    // T E R N A R Y

    // std::int8_t result;
    // if (b1 == true) {
    //     result = 10;
    // } else {
    //     result = -10;
    // }

    std::int32_t result2 = b1 == true ? 10 : -10;
    std::cout << "Result 2: " << result2 << std::endl;

    return 0;
}
