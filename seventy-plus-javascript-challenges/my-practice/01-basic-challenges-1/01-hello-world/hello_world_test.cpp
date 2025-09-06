#include <iostream>
#include <string>

#include "hello_world.h"

void test_hello_world() {
  std::cout << "Returning 'Hello, World!' as a string" << std::endl;
  const auto expected = std::string{"Hello World!"};

  const auto result = hello_world();

  if (expected == result) {
    std::cout << "Passed!" << std::endl;
    exit(0);
  } else {
    std::cout << "Failed!" << std::endl;
    exit(1);
  }
}

int main() {
  test_hello_world();
  return 0;
}

// ---- J A V A S C R I P T -----
/*

const helloWorld = require('./hello-world');

test("Returning 'Hello, World!' as a string", () => {
  const result = helloWorld();
  expect(result).toBe('Hello World!');
});

 */
