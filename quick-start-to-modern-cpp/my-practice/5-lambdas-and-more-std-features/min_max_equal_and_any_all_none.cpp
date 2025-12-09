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

struct OneTwoData {
    std::int32_t one;
    std::int32_t two;
};

int main() {
    auto num_sequence = std::vector<std::int32_t>(NUM_ELEMENTS, 0);
    std::generate(num_sequence.begin(), num_sequence.end(), gen);
    print_vector(num_sequence);

    // M I N
    const auto min = std::min_element(num_sequence.begin(), num_sequence.end());
    // M A X
    const auto max = std::max_element(num_sequence.begin(), num_sequence.end());
    std::cout << "Min: " << *min << ", Max: " << *max << std::endl;

    // E Q U A L
    const auto datas1 = std::vector<OneTwoData>{{1, 1}, {2, 3}};
    const auto datas2 = std::vector<OneTwoData>{{1, 1}, {2, 2}};
    const auto eq = std::equal(datas1.begin(), datas1.end(), datas2.begin(), [](const auto &d, const auto &e) { return d.one == e.one && d.two == e.two; });
    std::cout << "Equal? " << std::boolalpha << eq << std::endl;

    const auto between_fives = [](const auto num) { return num > -5 && num < 5; };
    // A N Y
    const auto any_found = std::any_of(num_sequence.begin(), num_sequence.end(), between_fives);
    // A L L
    const auto all_found = std::all_of(num_sequence.begin(), num_sequence.end(), between_fives);
    // N O N E
    const auto none_found = std::none_of(num_sequence.begin(), num_sequence.end(), between_fives);

    std::cout << std::boolalpha << any_found << std::endl;
    std::cout << std::boolalpha << all_found << std::endl;
    std::cout << std::boolalpha << none_found << std::endl;

    return 0;
}
