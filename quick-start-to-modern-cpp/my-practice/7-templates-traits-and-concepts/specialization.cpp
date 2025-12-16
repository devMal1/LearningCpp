#include <iostream>
#include <vector>
#include <string>

template <typename T>
size_t length(const std::vector<T> &vec) {
    return vec.size();
}

// S P E C I A L I Z A T I O N
/*
This is used to override a template function for a specific type.
*/
template <>
size_t length(const std::vector<std::string> &vec) {
    auto l = size_t{};

    for (const auto &v : vec) {
        l += v.size();
    }

    return l;
}


int main() {
    const auto fs = std::vector<float>{1.0f, 2.0f, 3.0f};
    std::cout << length(fs) << std::endl;

    const auto ss = std::vector<std::string>{"hey", "hi", "hello"};
    std::cout << length(ss) << std::endl;

    return 0;
}
