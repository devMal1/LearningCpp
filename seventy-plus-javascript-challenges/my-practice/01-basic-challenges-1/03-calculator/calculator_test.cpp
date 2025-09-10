#include <cstdint>
#include <iostream>
#include <string>

#include "calculator.h"

void expect(const std::int32_t expected, const std::int32_t actual, const std::string test_name) {
  if (expected == actual) {
    std::cout << "Passed! (" << test_name << ")" << std::endl;
  } else {
    std::cout << "Failed! (" << test_name << ")" << std::endl;
  }
}

void test_calculator() {
  std::cout << "Performing arithmetic operations using the calculator function" << std::endl;

  const auto num1 = std::int32_t{5};
  const auto num2 = std::int32_t{7};

  expect(calculator(num1, num2, '+'), 12, "Addition");
  expect(calculator(num1, num2, '-'), -2, "Subtraction");
  expect(calculator(num1, num2, '*'), 35, "Multiplcation");
  expect(calculator(num1, num2, '/'), 0, "Division");

  // TODO: try catch in C++?
}

int main() {
  test_calculator();

  return 0;
}

// ----- J A V A S C R I P T -----
/*
const calculator = require('./calculator');

test('Performing arithmetic operations using the calculator function', () => {
  // Test case inputs
  const num1 = 5;
  const num2 = 7;

  // Addition
  expect(calculator(num1, num2, '+')).toBe(12);

  // Subtraction
  expect(calculator(num1, num2, '-')).toBe(-2);

  // Multiplication
  expect(calculator(num1, num2, '*')).toBe(35);

  // Division
  expect(calculator(num1, num2, '/')).toBeCloseTo(0.7143, 4);
});
*/
