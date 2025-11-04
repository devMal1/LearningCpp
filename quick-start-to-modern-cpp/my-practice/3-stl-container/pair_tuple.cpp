#include <iostream>
#include <cstdint>
#include <tuple>
#include <string>

// P A I R
/*
Holds two values.
Values are accessed by the `first` and `second` members.
*/

// T U P L E
/*
Holds at least one value.
Value are accessed using the std::get<>() function.
*/

// S T R U C T U R E D  B I N D I N G
/*
This is like destructuring in JavaScript.
It is used to grab the individual values from a pair or tuple or array or etc.

[Available since C++17]
*/

std::tuple<std::int32_t, float, std::string> ifs(std::int32_t some_num) {
    return std::make_tuple(some_num, static_cast<float>(some_num), std::to_string(some_num));
}

std::pair<std::int32_t, float> ifspair(std::int32_t some_num) {
    return std::pair{some_num, static_cast<float>(some_num)};
}

int main() {
    // P A I R
    auto my_pair = std::pair<std::int32_t, float>{13, 50.4f};
    std::cout << my_pair.first << std::endl;
    std::cout << my_pair.second << std::endl;

    // T U P L E
    auto my_tuple = std::tuple<std::int32_t, float, std::string>{20, 55.5f, "hello"};
    std::cout << std::get<0>(my_tuple) << std::endl;
    std::cout << std::get<1>(my_tuple) << std::endl;
    std::cout << std::get<2>(my_tuple) << std::endl;

    const auto result_tuple = ifs(42);
    std::cout << std::get<0>(result_tuple) << std::endl;
    std::cout << std::get<1>(result_tuple) << std::endl;
    std::cout << std::get<2>(result_tuple) << std::endl;

    // S T R U C T U R E D  B I N D I N G
    const auto &[numint, numfloat, numstring] = ifs(55);
    std::cout << numint << std::endl;
    std::cout << numfloat << std::endl;
    std::cout << numstring << std::endl;

    const auto &[numfirst, numsecond] = ifspair(22);
    std::cout << numfirst << std::endl;
    std::cout << numsecond << std::endl;

    return 0;
}
