Option 1: use implemented interprocess message queue
- https://www.boost.org/doc/libs/1_71_0/doc/html/interprocess/synchronization_mechanisms.html#interprocess.synchronization_mechanisms.message_queue
Advantages:
- already implemented, very easy to use
Disadvantages:
- might be slow because of prioty feature for messages, which might cause a lot of copying, see
https://stackoverflow.com/questions/6212138/boostinterprocess-message-queue-performance-rather-slow
- must be specified max number of messages and max size of single message  


Option 2: Implement own cyclig buffer in shared memory with interprocess mutexes and conditions / semaphores
- Cycloc buffer: https://www.boost.org/doc/libs/1_71_0/doc/html/interprocess/synchronization_mechanisms.html#interprocess.synchronization_mechanisms.mutexes.mutexes_anonymous_example
- Semaphores: https://www.boost.org/doc/libs/1_71_0/doc/html/interprocess/synchronization_mechanisms.html#interprocess.synchronization_mechanisms.semaphores
Advantages
- might be possibly faster than message_queue with priorities
Disadvantages:
- must be specified max number of messages and max size of single message


Option 3: Implement managed shared memory
Advantages:
- can be used objects of any size ?
- only max size of memory that is allocated is specified ?
- memory allocation inside the memory segment, named object construction...
