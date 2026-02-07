#include <future>
#include <iostream>

// A S Y N C
/*
This can be used for I/O bound operations.

Use threads for compute bound (intensive) operations.
*/

int func(const int input) {
    std::cout << input << std::endl;

    return input * 2;
}

int main() {
    int input = 1;
    auto handle = std::async(std::launch::async, func, input);

    // ... do some other stuff while the async func runs

    // will wait for the async func to complete and then return the result
    auto result = handle.get();
    std::cout << result << std::endl;

    return 0;
}
