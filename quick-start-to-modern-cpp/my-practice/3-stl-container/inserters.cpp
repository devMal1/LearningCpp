#include <iostream>
#include <cstdint>
#include <vector>
#include <iterator>

int main() {
    auto original_vector = std::vector<std::int32_t>{1, 2, 3, 4, 5};
    auto new_vector_1 = std::vector<std::int32_t>{-1, -2};
    auto new_vector_2 = std::vector<std::int32_t>{10, 11};

    // I N S E R T E R
    std::copy(original_vector.begin(),
        original_vector.end(),
        std::inserter(new_vector_1, std::next(new_vector_1.begin())));
    for (auto value : new_vector_1) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // container must implement "push_back" to use back_inserter
    std::copy(original_vector.begin(),
        original_vector.end(),
        std::back_inserter(new_vector_2));
    for (auto value : new_vector_2) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
