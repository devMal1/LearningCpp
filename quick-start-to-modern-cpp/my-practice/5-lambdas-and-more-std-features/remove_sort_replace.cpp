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

    // R E P L A C E
    /*
    Used to loop through a container and replace a value with another value.
    */
    std::replace(num_sequence.begin(), num_sequence.end(), 10, 5);
    print_vector(num_sequence);

    std::replace_if(num_sequence.begin(), num_sequence.end(), [](const auto num) { return num == 10; }, 5);
    print_vector(num_sequence);

    // S O R T
    /*
    Used to sort in place (by default in ascending order).

    Can pass a Comparator (function object) to define how to sort.
    */
    std::sort(num_sequence.begin(), num_sequence.end());
    print_vector(num_sequence);

    std::sort(num_sequence.begin(), num_sequence.end(), [](const auto num1, const auto num2) {return num1 > num2; });
    print_vector(num_sequence);

    // R E M O V E
    /*
    Used to remove elements from a container when it matches the specified value.
    */
    // Pre C++20
    // auto remove_it = std::remove(num_sequence.begin(), num_sequence.end(), -1);
    // num_sequence.erase(remove_it, num_sequence.end());
    // print_vector(num_sequence);

    // auto remove_it2 = std::remove_if(num_sequence.begin(), num_sequence.end(), [](const auto num) { return num < -1; });
    // num_sequence.erase(remove_it2, num_sequence.end());
    // print_vector(num_sequence);

    // Post C++20
    std::erase(num_sequence, 3);
    print_vector(num_sequence);

    std::erase_if(num_sequence, [](const auto num) {return num < 0;});
    print_vector(num_sequence);

    return 0;
}
