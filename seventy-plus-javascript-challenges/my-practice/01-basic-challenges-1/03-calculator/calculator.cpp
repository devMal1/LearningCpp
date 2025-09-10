#include <cstdint>

#include "calculator.h"

std::int32_t calculator(const std::int32_t num1, const std::int32_t num2, const char operand) {
    switch (operand) {
        case '+': {
            return num1 + num2;
        } case '-': {
            return num1 - num2;
        } case '*': {
            return num1 * num2;
        } case '/': {
            return num1 / num2;
        } default: {
            // TODO: How do you throw errors in C++?
            return 0;
        }
    }
}
