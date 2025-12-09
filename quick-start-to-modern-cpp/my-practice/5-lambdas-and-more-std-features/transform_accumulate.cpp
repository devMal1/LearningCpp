#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

namespace {
    constexpr auto NUM_ELEMENTS = size_t{3u};
}


std::int32_t gen() {
    static auto seed = std::random_device{};
    static auto generator = std::mt19937{seed()};
    static auto distributor = std::uniform_int_distribution<std::int32_t>{-10 , 10};

    return distributor(generator);
}

template <typename T>
void print_vector(const std::vector<T> &vec) {
    for (const auto val : vec) {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    auto num_sequence = std::vector<std::int32_t>(NUM_ELEMENTS, 0);
    std::generate(num_sequence.begin(), num_sequence.end(), gen);
    print_vector(num_sequence);

    // T R A N S F O R M  F U N C T I O N
    /*
    Applies a operation (function) to each value of the container and stores it in the 3rd parameter.
    */
    std::transform(num_sequence.begin(),
                   num_sequence.end(),
                   num_sequence.begin(),
                   [](const auto num) { return num * 2; });
    print_vector(num_sequence);

    std::transform(num_sequence.begin(),
                   num_sequence.end(),
                   num_sequence.begin(),
                   [](const auto num) { return num / 2; });
    print_vector(num_sequence);

    // A C C U M U L A T E  F U N C T I O N
    /*
    Used to some the values of a container.
    */
    const auto sum = std::accumulate(num_sequence.begin(), num_sequence.end(), 0);
    std::cout << sum << std::endl;

    return 0;
}
