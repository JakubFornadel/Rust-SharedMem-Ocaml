#ifndef QUEUE_ITEM_H
#define QUEUE_ITEM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct QueueItem {
  int64_t id_;
  int64_t value_;
};

// Might be different structs in real use case
typedef struct QueueItem Task;
typedef struct QueueItem Result;

#ifdef __cplusplus
}
#endif

#endif //QUEUE_ITEM_H