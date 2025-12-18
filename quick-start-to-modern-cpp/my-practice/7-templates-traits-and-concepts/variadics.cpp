#include <iostream>
#include <string>

template <typename T>
T concat1(const T &first) {
    return first;
}

// V A R I A D I C S
/*
Variable length arguments.
*/
template <typename T, typename... Args>
T concat1(const T &first, Args... args) {
    return first + concat1(args...);
}

// F O L D  E X P R E S S I O N S
/*
Folding expressions bypass the need for a recursive setup with a base case.
These can be used to handle operations on variadic arguments (argument packs).

Since C++17
*/
template <typename T, typename... Args>
T concat2(Args... args) {
    return (... - args);

    // The order matters. "..." is the first argument, and "args" is the pack of remaining arguments
    // return (args - ...) // this is different than (... - args)
}

int main() {
    const auto part1 = std::string{"He"};
    const auto part2 = std::string{"ll"};
    const auto part3 = std::string{"o"};

    // first=part1 ; args=[part2, part3]
    // first=part2 ; args=[part3]
    // first=part3 ; args=[]
    std::cout << concat1(part1, part2, part3) << std::endl;
    std::cout << concat1(1, 2, 3) << std::endl;

    // With folding expressions, the type needs to be declared
    std::cout << concat2<int>(2, 3, 4) << std::endl;

    return 0;
}
