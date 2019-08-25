#ifndef SHARED_MEM_H
#define SHARED_MEM_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

struct          shared_mem;
typedef struct  shared_mem shared_mem_t;

// struct          message;
// typedef struct  message message_t;

shared_mem_t*   shared_mem_create(const char* idStr);
void            shared_mem_destroy(shared_mem_t* sm);

int64_t         shared_mem_sum(shared_mem_t* sm, int64_t a, int64_t b);

// bool            shared_mem_push_task(shared_mem_t* sm, const message_t* msg);
// bool            shared_mem_pop_task(shared_mem_t* sm, message_t* msg);

// bool            shared_mem_push_result(shared_mem_t* sm, const message_t* msg);
// bool            shared_mem_pop_result(shared_mem_t* sm, message_t* msg);

bool            shared_mem_push_task(shared_mem_t* sm, const int* msg);
bool            shared_mem_pop_task(shared_mem_t* sm, int* msg);

bool            shared_mem_push_result(shared_mem_t* sm, const int* msg);
bool            shared_mem_pop_result(shared_mem_t* sm, int* msg);

#ifdef __cplusplus
}
#endif

#endif //SHARED_MEM_H