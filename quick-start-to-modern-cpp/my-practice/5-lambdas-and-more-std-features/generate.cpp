#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

namespace {
    constexpr auto NUM_ELEMENTS = size_t{1'000'000u};
}

std::int32_t gen() {
    // S T A T I C  L O C A L  V A R I A B L E S
    /*
    These variables are created once at runtime, and then used each time the function is called.

    This is better than putting them in the global space, as global space variables is not a best practice.
    */
    static auto seed = std::random_device{};
    static auto generator = std::mt19937{seed()};
    static auto distributor = std::uniform_int_distribution<std::int32_t>{-10, 10};

    return distributor(generator);
}

int main() {
    auto random_ints = std::vector<std::int32_t>(NUM_ELEMENTS, 0u);
    // G E N E R A T E  F U N C T I O N
    /*
    Used to fill a container with values given the passed in generator function (object)
    */
    std::generate(random_ints.begin(), random_ints.end(), gen);

    return 0;
}
