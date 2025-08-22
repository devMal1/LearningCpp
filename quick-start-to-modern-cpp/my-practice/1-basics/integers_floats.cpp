#include <cstdint>
#include <iostream>

int main() {
    // I N T E G E R S
    std::int8_t i1 = 0;
    std::uint8_t ui1 = 0u; // * the 'u' after the value signifies unsigned (can by uppercase or lowercase)

    std::int16_t i1 = 0;
    std::uint16_t ui1 = 0u;

    std::int32_t i1 = 0;
    std::uint32_t ui1 = 0u;

    std::int64_t i1 = 0;
    std::uint64_t ui1 = 0u;

    // F L O A T S
    float f1 = 12.0f; // * 32bit (the 'f' signifies the value is a float and not a double)
    double d1 = 12.0; // 64bit

    // B O O L E A N S
    bool b1 = false;
    bool b1 = true;

    // C H A R A C T E R S (integer)
    char c1 = 'A'; // * single quotes for a character, double quotes for a string
    char c1 = 'z';

    return 0;
}
