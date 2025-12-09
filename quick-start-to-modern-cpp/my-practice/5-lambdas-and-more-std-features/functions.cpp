#include <iostream>
#include <cstdint>
#include <vector>

// F U N C T I O N
/*
The standard function function allows us to store functions in variables and pass them in functions calls.
*/

int f(float num) {
    std::cout << num << std::endl;

    return static_cast<int>(num);
}

int new_approach2(std::function<int(float)> func) {
    return func(2.0f);
}

int main() {
    // Old C-style approach
    // int (*old_way)(float); // <- function pointer
    // old_way = f;
    // old_way(2.0f);

    // C++ approach
    auto new_approach = std::function{f};
    auto param = float{2.0f};
    auto result = new_approach(param);

    new_approach2(f);

    const int threshold = 2;
    auto fns = std::vector<std::function<bool(const int)>>{
        [&threshold](const int v) { return v > threshold; },
        [&threshold](const int v) { return v < threshold; },
        [&threshold](const int v) { return v == threshold; },
        [&threshold](const int v) { return v != threshold; },
        [&threshold](const int v) { return v >= threshold; },
        [&threshold](const int v) { return v <= threshold; }
    };

    // To do ^^ this in C-style (NOTE: you can't use the capture list)
    // auto fns = std::vector<bool (*)(const int)>{
    //     [](const int v) { return v > 2; },
    //     [](const int v) { return v < 2; },
    //     [](const int v) { return v == 2; },
    //     [](const int v) { return v != 2; },
    //     [](const int v) { return v >= 2; },
    //     [](const int v) { return v <= 2; },
    // };

    for (const auto &fn : fns) {
        std::cout << std::boolalpha << fn(5) << std::endl;
    }

    return 0;
}
