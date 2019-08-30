#include <iostream>
#include <string>
#include "../src/include/SharedMem.hpp"

int main(void) {
  SharedMem sharedMem("Hello-World.txt", true);

  int64_t a = 12;
  int64_t b = 6;

  //int64_t sum = a + b;
  int64_t sum = sharedMem.sum(a, b);
  std::cout << "Sum of " << a << " + " << b << " = " << sum << std::endl;
}