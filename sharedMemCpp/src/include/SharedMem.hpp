#ifndef SHARED_MEM_HPP
#define SHARED_MEM_HPP

#include <boost/interprocess/ipc/message_queue.hpp>
#include <string>

class SharedMem {
public:
  class MessageData {
  private:
    int64_t id_;
    int64_t value_;
  public:
    MessageData() = default;
    MessageData(int64_t id, int64_t value) : id_(id), value_(value) {}
    ~MessageData() = default;

    int64_t getId();
    int64_t getValue();
  };
  using Message = MessageData; //int;  

  enum class ShmMode {
    CREATE = 0,
    OPEN
  };


  SharedMem(const std::string& idStr, ShmMode mode);
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
  ShmMode                                             shm_mode_;

  std::string                                         tasks_queue_id_;
  std::unique_ptr<boost::interprocess::message_queue> tasks_queue_;

  std::string                                         results_queue_id_;
  std::unique_ptr<boost::interprocess::message_queue> results_queue_;

  void createQueues();
  void openQueues();
};

#endif //SHARED_MEM_HPP