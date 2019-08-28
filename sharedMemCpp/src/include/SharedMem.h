#ifndef SHARED_MEM_H
#define SHARED_MEM_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

struct          shared_mem;
typedef struct  shared_mem shared_mem_t;

struct          message;
typedef struct  message message_t;

message_t*      message_create(int64_t id, int64_t value);
message_t*      empty_message_create();
void            message_print(message_t* msg);
void            message_destroy(message_t* msg);

shared_mem_t*   shared_mem_create(const char* idStr, bool createFlag);
void            shared_mem_destroy(shared_mem_t* sm);

bool            shared_mem_push_task(shared_mem_t* sm, const message_t* msg);
bool            shared_mem_pop_task(shared_mem_t* sm, message_t* msg);
bool            shared_mem_push_result(shared_mem_t* sm, const message_t* msg);
bool            shared_mem_pop_result(shared_mem_t* sm, message_t* msg);

int64_t         shared_mem_sum(shared_mem_t* sm, int64_t a, int64_t b);

#ifdef __cplusplus
}
#endif

#endif //SHARED_MEM_H