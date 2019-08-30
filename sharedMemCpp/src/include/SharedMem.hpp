#ifndef SHARED_MEM_HPP
#define SHARED_MEM_HPP

#include <boost/interprocess/ipc/message_queue.hpp>
#include <string>

#include "QueueItem.h"

/**
 * @brief Shared Memory implemented through boost interprocess header library. Currently, it uses predefined 
 *        concurrent queues, but can be changed for almost anything:
 *        - manually synchronized cyclic buffer,
 *        - managed shared memory,
 *        - ...
 *        - see sharedMemCpp/readme.txt to see more options
 **/
class SharedMem {
public:
  enum class ShmMode {
    CREATE = 0,
    OPEN
  };

  SharedMem(const std::string& idStr, ShmMode mode);
  ~SharedMem();
  
  /**
   * Push & Pop methods are blocking - push waits until there is space in queue and pop until there is some data inside
   * Timeouts or immediate return can be used also
   **/
  bool pushTask(const Task& value);
  bool popTask(Task& value);

  bool pushResult(const Result& value);
  bool popResult(Result& value);

  /**
   * @brief Returns a + b
   **/
  int64_t sum(int64_t a, int64_t b);

private:
  ShmMode                                             shm_mode_;

  std::string                                         tasks_queue_id_;
  std::unique_ptr<boost::interprocess::message_queue> tasks_queue_;

  std::string                                         results_queue_id_;
  std::unique_ptr<boost::interprocess::message_queue> results_queue_;

  void createQueues();
  void openQueues();
};

#endif //SHARED_MEM_HPP