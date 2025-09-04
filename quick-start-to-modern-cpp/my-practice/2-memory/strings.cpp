#include <iostream>
#include <cstdint>
#include <array>
#include <string>

int main() {
    // c-style strings
    char first[] = "Malik"; // the length is alway plus 1 of the content because of the \0 (null terminator)
    char last[] = {'M', 'a', 'l', 'o', 'n', 'e'}; // <- this is not commonly used
    // cpp adaption of the c-style (not commonly used)
    auto word = std::array<char, 4u>{"Yes"};

    // S T R I N G S
    auto text = std::string{"hello"}; // dynamic (c++) string
    std::cout << text << std::endl;
    text.append(" world");
    std::cout << text << std::endl;

    return 0;
}
