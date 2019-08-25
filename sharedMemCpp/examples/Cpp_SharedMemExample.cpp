#include <SharedMem.hpp>
#include <iostream>
#include <string>

int main(void) {
  SharedMem sharedMem("Hello-World.txt");

  int64_t a = 12;
  int64_t b = 6;

  int64_t sum = sharedMem.sum(a, b);
  std::cout << "Sum of " << a << " + " << b << " = " << sum << std::endl;
}