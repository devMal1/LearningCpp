#include <iostream>
#include <cstdint>

// P O I N T E R S
/*
Pointers and references are very similar, but they have a slight difference.
They both hold memory addresses as their value.
References though, do not change as they are a reference to a specific vairable.
Pointers can change, as they are a variable that points to a given memory address (i.e. a reference of another variable)

In general: Only use pointers when you have to, otherwise use references!
*/

int main() {
    auto my_age = std::uint32_t{32u};
    std::cout << &my_age << std::endl; // referncing my age (revealing its memory address)
    std::cout << my_age << std::endl;

    std::uint32_t* pointer_to_my_age = &my_age; // stores the memory addredss of my_age
    std::cout << &pointer_to_my_age << std::endl; // the address of the pointer is different than my_age
    std::cout << pointer_to_my_age << std::endl;

    // dereferencing (accessing the value that the pointer points to--not the address)
    *pointer_to_my_age = 33u;
    std::cout << my_age << std::endl;
    std::cout << *pointer_to_my_age << std::endl; // this is the same as my_age (because it is pointing to it)

    return 0;
}
