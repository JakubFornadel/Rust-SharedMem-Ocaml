#ifndef SHARED_MEM_HPP
#define SHARED_MEM_HPP

#include <boost/interprocess/ipc/message_queue.hpp>
#include <string>

class SharedMem {
public:
  struct MessageData {
    int id_;
    int value_;
  };
  using Message = int; // TODO: use MessageData  

  SharedMem(const std::string& idStr);
  ~SharedMem();
  
  bool pushTask(const Message& value);
  bool popTask(Message& value);

  bool pushResult(const Message& value);
  bool popResult(Message& value);

  /**
   * @brief Returns a + b
   **/
  int64_t sum(int64_t a, int64_t b);

private:
  std::string                                         tasks_queue_id_;
  std::unique_ptr<boost::interprocess::message_queue> tasks_queue_;

  std::string                                         results_queue_id_;
  std::unique_ptr<boost::interprocess::message_queue> results_queue_;
};

#endif //SHARED_MEM_HPP