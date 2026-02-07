#include <iostream>
#include <exception>
#include <string>
#include <string_view>

// E X C E P T I O N S
/*
There are standard exceptions (from exception header), but you can also create
custom exceptions.
*/

class DivisionByZero : public std::exception {
public:
    DivisionByZero(std::string_view _message) : message(_message) {};

    std::string message;

    [[nodiscard]] const char *what() const noexcept override {
        return message.c_str();
    }
};

double div(double x, double y) {
    if (y == 0.0) {
        throw DivisionByZero("Dividing by 0...");
    }

    return x / y;
}

int main() {
    try {
        div(5.0, 0.0);
    } catch (const std::exception &exc) {
        std::cerr << exc.what() << std::endl;
    }

    return 0;
}
