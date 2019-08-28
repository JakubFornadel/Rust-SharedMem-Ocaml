#ifndef SHARED_MEM_HPP
#define SHARED_MEM_HPP

#include <boost/interprocess/ipc/message_queue.hpp>
#include <string>

#include "QueueItem.h"

class SharedMem {
public:
  enum class ShmMode {
    CREATE = 0,
    OPEN
  };

  SharedMem(const std::string& idStr, ShmMode mode);
  ~SharedMem();
  
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