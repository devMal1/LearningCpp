#include <chrono>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

// C H R O N O  L I B R A R Y
/*
We can use this library to interact with time.

In this case, it will be used to measure the speed of generating 1,000,000 random numbers.
*/
using ClockType = std::chrono::steady_clock;
using ClockResolution = std::chrono::microseconds;

namespace {
    constexpr auto NUM_ELEMENTS = size_t{1'000'000u};
}

int main() {
    auto seed = std::random_device{};
    auto generator = std::mt19937{seed()};
    auto distributor = std::uniform_int_distribution<std::int32_t>{-10, 10};

    auto random_ints = std::vector<std::int32_t>(NUM_ELEMENTS, 0u);
    // Capture the start time
    const auto start_time = ClockType::now();
    for (auto &random_int : random_ints) {
        random_int = distributor(generator);
    }
    // Capture the end time
    const auto end_time = ClockType::now();

    const auto elapsed_time = std::chrono::duration_cast<ClockResolution>(end_time - start_time).count();
    std::cout << "Elapsed time: " << elapsed_time << " us." << std::endl;

    return 0;
}
