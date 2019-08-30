#include <stdio.h>
#include <inttypes.h>
#include "../src/include/SharedMem.h"

int main(void) {    
  shared_mem_t* sharedMem = shared_mem_create("Hello-World.txt", true);

  int64_t a = 12;
  int64_t b = 6;
  int64_t sum = shared_mem_sum(sharedMem, a, b);
  printf("Sum of %ld + %ld = %ld\n", (long)a, (long)b, (long)sum);
}