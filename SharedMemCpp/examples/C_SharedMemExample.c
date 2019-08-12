#include <stdlib.h>
#include <SharedMem.h>

int main(void) {    
    shared_mem_t* sharedMem = shared_mem_create("Hello-World.txt");
    printf("SharedMem file %s\n", shared_mem_file_name(sharedMem));

    // int64_t a = 12;
    // int64_t b = 6;
    // int64_t sum = shared_mem_file_name(sharedMem, a, b)

    // std::cout << "Sum of " << a << " + " << b << " = " << sum << std::endl;
}