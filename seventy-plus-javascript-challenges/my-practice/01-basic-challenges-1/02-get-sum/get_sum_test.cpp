#include <iostream>
#include <cstdint>

#include "get_sum.h"

void test_get_sum() {
  std::cout << "Calculating the sum of two numbers" << std::endl;

  const auto num1 = std::int32_t{5};
  const auto num2 = std::int32_t{7};
  const auto expected = std::int32_t{12};

  const auto result = get_sum(num1, num2);

  if (result == expected) {
    std::cout << "Passed!" << std::endl;
    exit(0);
  } else {
    std::cout << "Failed!" << std::endl;
    exit(1);
  }
}

int main () {
  test_get_sum();

  return 0;
}

// ----- J A V A S C R I P T ----- //
/*

const getSum = require('./get-sum');

test('Calculating the sum of two numbers', () => {
  // Test case inputs
  const num1 = 5;
  const num2 = 7;

  // Call the function
  const result = getSum(num1, num2);

  // Check if the result is equal to the expected sum
  expect(result).toBe(12);
});

*/
