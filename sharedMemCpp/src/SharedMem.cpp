#include <memory>
#include <iostream>
//#include <SharedMem.hpp> // VS Code includes installed header instead of local one
#include "include/SharedMem.hpp"

using namespace boost::interprocess;

SharedMem::SharedMem(const std::string& idStr, ShmMode mode) : 
    shm_mode_(mode),
    tasks_queue_id_(idStr + "_tasks"), 
    tasks_queue_(), 
    results_queue_id_(idStr + "_results"), 
    results_queue_() { 
  switch(shm_mode_) {
    case ShmMode::CREATE:
      createQueues();
      break;
    case ShmMode::OPEN:
      openQueues();
      break;
    default:
      throw std::runtime_error("Invalid SharedMem mode.");
  }
}

SharedMem::~SharedMem() {
  if (shm_mode_ == ShmMode::CREATE) {
    // TODO: handle error when removing fails !!!
    //Erase previous tasks message queue
    message_queue::remove(tasks_queue_id_.c_str());

    //Erase previous results message queue
    message_queue::remove(results_queue_id_.c_str());
  }
}

void SharedMem::createQueues() {
  //Erase previous tasks message queue
  message_queue::remove(tasks_queue_id_.c_str());

  std::cout << "Creating task queue with id: " << tasks_queue_id_.c_str() << std::endl;
  //Create a tasks message_queue.
  tasks_queue_ = std::make_unique<message_queue>
      (create_only                //create
      ,tasks_queue_id_.c_str()    //name
      ,100                        //max message number
      ,sizeof(SharedMem::Message) //max message size
      );

  //Erase previous results message queue
  message_queue::remove(results_queue_id_.c_str());

  std::cout << "Creating result queue with id: " << results_queue_id_.c_str() << std::endl;
  //Create a results message_queue.
  results_queue_ = std::make_unique<message_queue>
      (create_only                //create
      ,results_queue_id_.c_str()  //name
      ,100                        //max message number
      ,sizeof(SharedMem::Message) //max message size
      );
}

void SharedMem::openQueues() {
  std::cout << "Opening task queue with id: " << tasks_queue_id_.c_str() << std::endl;
  //Create a tasks message_queue.
  tasks_queue_ = std::make_unique<message_queue>
      (open_only                  //open 
      ,tasks_queue_id_.c_str()    //name
      );

  std::cout << "Opening result queue with id: " << results_queue_id_.c_str() << std::endl;
  //Create a results message_queue.
  results_queue_ = std::make_unique<message_queue>
      (open_only                  //open
      ,results_queue_id_.c_str()  //name
      );
}

bool SharedMem::pushTask(const Message& value) {
  try {
    tasks_queue_->send(&value, sizeof(value), 0/*priority*/);
  } catch (const interprocess_exception& err) {
    std::cerr << err.what() << std::endl;
    return false;
  }
  
  return true;
}

bool SharedMem::popTask(Message& value) {
  unsigned int priority;
  message_queue::size_type recvd_size;

  try {
    tasks_queue_->receive(&value, sizeof(value), recvd_size, priority);
  } catch (const interprocess_exception& err) {
    std::cerr << err.what() << std::endl;
    return false;
  }

  return true;
}

bool SharedMem::pushResult(const Message& value) {
  try {
    results_queue_->send(&value, sizeof(value), 0/*priority*/);
  } catch (const interprocess_exception& err) {
    std::cerr << err.what() << std::endl;
    return false;
  }
  
  return true;
}
  
bool SharedMem::popResult(Message& value) {
  unsigned int priority;
  message_queue::size_type recvd_size;

  try {
    results_queue_->receive(&value, sizeof(value), recvd_size, priority);
  } catch (const interprocess_exception& err) {
    std::cerr << err.what() << std::endl;
    return false;
  }

  return true;
}

int64_t SharedMem::sum(int64_t a, int64_t b) {
  return a + b;
}

int64_t SharedMem::MessageData::getId() {
  return id_;
}

int64_t SharedMem::MessageData::getValue() {
  return value_;
}