#include <iostream>

// A T T R I B U T E S
/*
Helpful metadata for:
    1.  the reader/user of the code or
    2. the compiler (to better optimize the code)

Since C++17
*/

// nodiscard - requires the return value to be used
[[nodiscard]] int get_value1() {
    return 1;
}

enum class [[nodiscard]] ReturnCodes{OK, NoData, Error};

struct [[nodiscard]] Item {};

// deprecated() - notifies that a function is no longer recommended
[[deprecated("Use func2()")]] void func1() {};

// maybe_used - notifies that the return value does not have to be used
[[maybe_unused]] double run (double d) {
    return 2.0 * d;
}

int main() {
    get_value1();
    func1();
    run(11.0);

    int alternative = get_value1();
    switch (alternative) {
        // likely - notifies that this is a likely case/branch to occur
        // fallthrough - makes explicit that this is supposed to fallthrough to the next
        [[likely]] case 1: [[fallthrough]];
        [[likely]] case 2: {
            std::cout << "Case 1 and Case 2" << std::endl;
            break;
        }
        default: {
            std::cout << "Default" << std::endl;
        }
    }


    return 0;
}
