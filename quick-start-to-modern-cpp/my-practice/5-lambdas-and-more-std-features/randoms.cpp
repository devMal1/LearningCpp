#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

namespace {
    // constexpr auto NUM_ELEMENTS = size_t{1'000'000u};
    constexpr auto NUM_ELEMENTS = size_t{10u};
}

int main() {
    // R A N D O M  G E N E R A T O R
    /*
    Steps to create a random generator:
        1. create a seed
        2. create a generator (using the seed)
        3. define a distribution
        4. use the distribution to get the next (pseudo) random number
    */
    auto seed = std::random_device{};
    auto generator = std::mt19937{seed()};
    auto distributor = std::uniform_int_distribution<std::int32_t>{-10, 10};

    auto random_ints = std::vector<std::int32_t>(NUM_ELEMENTS, 0u);
    for (auto &random_int : random_ints) {
        random_int = distributor(generator);
    }

    // print out the randomly generated numbers
    for (const auto &num : random_ints) {
        std::cout << num << std::endl;
    }

    return 0;
}
