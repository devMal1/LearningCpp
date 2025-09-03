#include <cstdint>
#include <iostream>

// A N O N Y M O U S  N A M E S P A C E
namespace {
    // This is a private gloabl variable (only accessible within this source file)
    constexpr auto VALUE = 5;

    // This is a private function (only accessible within this source file)
    std::int32_t get_a_num() {
        return 7;
    }
}

// The 'C' way to do this, would be to use `static` isntead of using an anonymous namespace
// using the anonymous namespace is the 'C++' way

int main() {
    std::cout << VALUE << std::endl;

    std::cout << get_a_num() << std::endl;

    return 0;
}
