#include <iostream>
#include <cstdint>
#include <string>

// S T R I N G S
/*
Keep in mind that strings use heap allocation. Allocating on the heap is a **slow** process, so only use if you need to.
*/

int main() {
    const auto s1 = std::string{"Malik"}; // the value used to initialize the string is a char array
    auto s2 = std::string{"Malik Malone"};

    // empty - check for if string is empty
    std::cout << s1.empty() << std::endl;
    // length - get the amount of characters in string
    std::cout << s1.length() << std::endl;

    // find - find position of string
    const auto findpos1 = s1.find("Mal", 0);
    std::cout << findpos1 << std::endl;

    const auto findpos2 = s2.find("lik", 5);
    if (findpos2 == std::string::npos) {
        std::cout << "lik" << " not found in " << s2 << " (starting from position " << "5" << ")" << std::endl;
    }

    // rfind - find position in reverse
    const auto findposr = s2.rfind("lik");
    std::cout << findposr << std::endl;

    // replace - replace with string
    const auto start = s2.find("one");
    s2.replace(start, 3, "1");
    std::cout << s2 << std::endl;

    // compare strings
    const auto s3 = std::string{"Hello!"};
    const auto s4 = std::string{"Hellooo!"};
    std::cout << "s3 == s4: " << std::boolalpha << (s3 == s4) << std::endl;
    const auto compared = s3.compare(s4);
    std::cout << "s3.compare(s4): " << compared << std::endl;

    // substr - get the substring
    const auto subs3 = s3.substr(2, 3);
    std::cout << subs3 << std::endl;

    // string conversion
    const auto si = std::to_string(42);  // "42"
    const auto sl = std::to_string(42l); // "42"
    const auto su = std::to_string(42u); // "42"

    const auto i1 = std::stoi("42");                 // 42
    const auto i2 = std::stoi("101010", nullptr, 2); // 42
    const auto i3 = std::stoi("052", nullptr, 8);    // 42
    const auto i4 = std::stoi("0x2A", nullptr, 16);  // 42

    const auto d1 = std::stod("123.45");       // 123.45000000000000
    const auto d2 = std::stod("1.2345e+2");    // 123.45000000000000
    const auto d3 = std::stod("0xF.6E6666p3"); // 123.44999980926514

    return 0;
}
