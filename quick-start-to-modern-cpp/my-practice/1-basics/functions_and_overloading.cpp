#include <cstdint>
#include <iostream>

// F U N C T I O N

// function delcaration
void my_print_function();

// O V E R L O A D I N G

// function definition + declaration
void print_my_number(std::uint32_t number) {
    std::cout << number << std::endl;
}
void print_my_number(double number) {
    std::cout << number << std::endl;
}

int main() {
    my_print_function(); // function call (invocation)

    print_my_number(10u);
    print_my_number(10.5);

    return 0;
}

// function definition
void my_print_function() {
    std::cout << "Hello World!" << std::endl;
}
