#ifndef SHARED_MEM_H
#define SHARED_MEM_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

struct          shared_mem;
typedef struct  shared_mem shared_mem_t;

shared_mem_t*   shared_mem_create(const char* file_name);
void            shared_mem_destroy(shared_mem_t* m);

int64_t         shared_mem_sum(shared_mem_t* m, int64_t a, int64_t b);
const char*     shared_mem_file_name(shared_mem_t *m);

#ifdef __cplusplus
}
#endif

#endif //SHARED_MEM_H