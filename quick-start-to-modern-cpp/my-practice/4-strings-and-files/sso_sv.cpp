#include <iostream>
#include <cstdint>
#include <string>
#include <string_view>

// S M A L L  S T R I N G  O P T I M I Z A T I O N  (SSO)
/*
Because heap allocation is expensive (slow performance), compilers introduced
a std::string optimization (when the string is small).

Implementation | SSO Capacity | sizeof
---------------------------------------
MSVC           | 15           | 32
GCC            | 15           | 32
Clang (mac)    | 22           | 24

^^ Given the compiler implementation, if the size of the std::string is equal to or less than the SSO capacity
then the compiler will not use heap allocation, but instead will use a stack c-style array.
*/

// Overriding to show when allocation is happening
void *operator new(std::size_t count) {
    if (count > 32) {
        std::cout << "allocating" << std::endl;
    } else {
        // this is dead code
        std::cout << "not allocating" << std::endl;
    }
    return malloc(count);
}

void handle_string(const std::string &str) {
    std::cout << str << std::endl;
}

/*
When creating a function that takes in a constant reference to a string (const &string),
use the std::string_view instead.

It is already immutable, so no need to add a const.
*/
void handle_stringv(std::string_view strv) {
    std::cout << strv << std::endl;
}


int main() {
    // S S O
    std::cout << "SSO stuffs" << std::endl << std::endl;

    // Empty string
    {
        auto str = std::string{""};
        auto size = sizeof(str);
        auto capacity = str.capacity();
        std::cout << "sizeof: " << size << std::endl;
        std::cout << "capacity: " << capacity << std::endl;
    }
    // "Small" string
    {
        auto str = std::string(15, '*');
        auto size = sizeof(str);
        auto capacity = str.capacity();
        std::cout << "sizeof: " << size << std::endl;
        std::cout << "capacity: " << capacity << std::endl;
    }
    // not "Small" string
    {
        auto str = std::string(32, '*');
        auto size = sizeof(str);
        auto capacity = str.capacity();
        std::cout << "sizeof: " << size << std::endl;
        std::cout << "capacity: " << capacity << std::endl;
    }

    // V I E W  S T R I N G S
    std::cout << "View Strings stuffs" << std::endl << std::endl;

    // auto somestring = std::string{"Hello, this is a string that is larger than the SSO minium!!!"};

    // the char[] argument, gets converted to a std::string before being passed to the function
    handle_string("Hello, this is a string that is larger than the SSO minium!!!");
    // with a string view (as the param type), no (heap) allocation occurs!
    handle_stringv("Hello, this is a string that is larger than the SSO minium!!!");

    return 0;
}
