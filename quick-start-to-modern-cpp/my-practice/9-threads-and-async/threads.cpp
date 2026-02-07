#include <array>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <thread>
#include <chrono>

// T H R E A D S
/*
*/

namespace {
constexpr auto NUM_THREADS = size_t{3u};
};

void worker(const std::int32_t input, std::int32_t &output) {
    std::cout << "Called worker from Thread: " << std::this_thread::get_id() << std::endl;

    output = input * 2;

    std::this_thread::sleep_for(std::chrono::seconds(2));
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
        threads[i] = std::thread(worker, inputs[i], std::ref(outputs[i]));
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

    return 0;
}
