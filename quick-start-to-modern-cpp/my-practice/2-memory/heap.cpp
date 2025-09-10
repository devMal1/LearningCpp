#include <iostream>
#include <cstdint>

// In modern C++ (regular) pointers are not often used (new and delete neither)
// isntead smart pointers are used.

// Nonetheless below is an example of Heap allocation using new and delete and pointers

int main() {
    const auto len = std::size_t{5};
    std::uint32_t stack_arry[len] = {1, 2, 3, 4, 5}; // created on the stack (length needs to be known at compuile time)

    // H E A P
    auto len2 = std::size_t{};
    std::cin >> len2; // read length from user

    // *new* heap allocation
    std::uint32_t *heap_array = new std::uint32_t[len2]; // created on the heap (lenght specified at runtime)
    std::cout << heap_array << std::endl; // prints out memory address

    for (std::size_t i = 0; i < len2; i++) {
        heap_array[i] = static_cast<std::uint32_t>(i);
    }

    for (std::size_t i = 0; i < len2; i++) {
        std::cout << heap_array[i] << std::endl;
    }

    // *delete* heap deallocation
    delete[] heap_array; // frees the heap memory
    heap_array = nullptr; // safety to make sure pointer is not used again

    // can use nullptr as a check, to make sure pointer exists beofore using like:
    // if (heap_array != nullptr) { // or if (heap_array) {
        // use the pointer
    // }

    return 0;
}
