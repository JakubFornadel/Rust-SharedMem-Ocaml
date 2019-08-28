#ifndef SHARED_MEM_H
#define SHARED_MEM_H

#include <stdbool.h>
#include <stdint.h>
#include "QueueItem.h"

#ifdef __cplusplus
extern "C" {
#endif

struct          shared_mem;
typedef struct  shared_mem shared_mem_t;

shared_mem_t*   shared_mem_create(const char* idStr, bool createFlag);
void            shared_mem_destroy(shared_mem_t* sm);

bool            shared_mem_push_task(shared_mem_t* sm, const Task* task);
bool            shared_mem_pop_task(shared_mem_t* sm, Task* task);
bool            shared_mem_push_result(shared_mem_t* sm, const Result* result);
bool            shared_mem_pop_result(shared_mem_t* sm, Result* result);


// For Ocaml. 
// TODO: is there any way how to directly create Ocaml wrapper fot C struct like in Rust???
Task*           task_create(int64_t id, int64_t value);
void            task_print(Task* task);
void            task_destroy(Task* task);
Result*         result_create(int64_t id, int64_t value);
void            result_print(Result* result);
void            result_destroy(Result* result);

int64_t         shared_mem_sum(shared_mem_t* sm, int64_t a, int64_t b);

#ifdef __cplusplus
}
#endif

#endif //SHARED_MEM_H