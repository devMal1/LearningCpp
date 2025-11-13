#include <iostream>
#include <cstdint>
#include <string>
#include <map>


void print_map(const std::map<std::string, std::int32_t> &the_map) {
    for (auto &[name, age]: the_map) {
        std::cout << name << " " << age << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // M A P
    auto my_map = std::map<std::string, std::int32_t>{
        {"me", 32}
    };

    // add
    my_map["wifey"] = 31;
    my_map["son"] = 2;

    print_map(my_map);

    // update
    my_map["son"] = 1;

    print_map(my_map);

    // query (contains [c++20])
    if (!my_map.contains("wifey")) {
        my_map["wifey"] = 31;
    }
    if (!my_map.contains("dad")) {
        my_map["dad"] = 50;
    }

    print_map(my_map);

    // query (find)
    const auto it_find = my_map.find("dad");
    if (it_find != my_map.end()) {
        const auto &[name, age] = *it_find;
        std::cout << name << " found!" << std::endl;
    }

    return 0;
}
