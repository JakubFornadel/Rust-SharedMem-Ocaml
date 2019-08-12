#include <SharedMem.hpp>
#include <iostream>
#include <string>

int main(void) {
    std::cout << "Hello " << SharedMem::hello() << std::endl;

    int64_t a = 12;
    int64_t b = 6;

    int64_t sum = SharedMem::sum(a, b);
    std::cout << "Sum of " << a << " + " << b << " = " << sum << std::endl;
}