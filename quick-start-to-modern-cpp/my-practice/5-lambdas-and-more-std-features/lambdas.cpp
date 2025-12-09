#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>

// L A M B D A S
/*
Lambdas in C++ have a Capture List, Parameter List, and Function Body
[capture list](parameter list){function body}
[](){}

The compiler will take the lambda and create a class as the underlying functionality.
*/


template <typename T>
void print_vector(const std::vector<T> &vec) {
    for (const auto &value : vec) {
        std::cout << value << std::endl;
    }
}

template <typename T>
bool check_even(const T num) {
    return num % 2 == 0;
}

int main() {
    auto num_sequence = std::vector<int>(10, 0);
    // iota is a helper function that will populate a container in sequential order starting from a given number
    std::iota(num_sequence.begin(), num_sequence.end(), 0);
    print_vector(num_sequence);

    for (const auto val : num_sequence) {
        std::cout << std::boolalpha << check_even(val) << std::endl;
    }
    std::cout << std::endl;

    // lambda!
    const auto N = 3;
    auto even_filter = [N](const auto value) {return value % N == 0;};

    for (const auto val : num_sequence) {
        std::cout << std::boolalpha << even_filter(val) << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
