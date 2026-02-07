#include <array>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <thread>
#include <cassert>
#include <mutex>

// M U T E X
/*
Allow shared resources to be safely used between threads.

NOTE (Performance): try to use the shared variable as little as possible to lower the negative impact on performance.
*/

namespace {
constexpr auto NUM_THREADS = size_t{20u};
constexpr auto NUM_INCREMENTS = std::uint32_t{100'000u};
}; // namespace

auto global_counter = std::int32_t{0};

// Without using the mutex, the shared resource (global_counter) will be impacted by race conditions
void worker1(const std::int32_t input, std::int32_t &output) {
    output = input * 2;

    for (std::uint32_t i = 0; i < NUM_INCREMENTS; ++i) {
        ++global_counter;
    }
}

auto mutex = std::mutex{};

void worker2(const std::int32_t input, std::int32_t &output) {
    output = input * 2;

    // using this local counter instead of directly using global_counter, increases performance
    auto local_counter = std::uint32_t{0u};

    for (std::uint32_t i = 0; i < NUM_INCREMENTS; ++i) {
        ++local_counter; // instead of ++global_counter
    }

    auto guard = std::lock_guard<std::mutex>{mutex};
    global_counter += local_counter;
}

int main() {
    auto inputs = std::array<std::int32_t, NUM_THREADS>{};
    std::iota(inputs.begin(), inputs.end(), 0);
    auto outputs = std::array<std::int32_t, NUM_THREADS>();
    std::fill(outputs.begin(), outputs.end(), 0);

    std::cout << "Main Thread ID: " << std::this_thread::get_id() << std::endl;

    // create the threads (giving them work)
    std::array<std::thread, NUM_THREADS> threads;
    for (std::uint32_t i = 0; i < NUM_THREADS; ++i) {
        // with output references and threads, need to use the std::ref function
        threads[i] = std::thread(worker2, inputs[i], std::ref(outputs[i]));
    }

    // ... do some work while threads do their work

    // wait for all threads to complete their work
    for (std::uint32_t i = 0; i < NUM_THREADS; ++i) {
        threads[i].join();
    }

    // do something with the output of the threads
    for (std::uint32_t i = 0; i < NUM_THREADS; ++i) {
        std::cout << "Outputs[" << i << "] = " << outputs[i] << std::endl;
    }

    std::cout << "Global counter = " << global_counter << std::endl;
    assert(global_counter == NUM_THREADS * NUM_INCREMENTS);

    return 0;
}
