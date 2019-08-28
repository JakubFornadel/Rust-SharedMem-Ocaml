#include <iostream>

//#include <SharedMem.hpp> // VS Code includes installed header instead of local one
//#include <SharedMem.h>   // VS Code includes installed header instead of local one

#include "include/SharedMem.hpp"
#include "include/SharedMem.h"

struct shared_mem {
  void *obj;
};

struct message {
  void *obj;
};

shared_mem_t* shared_mem_create(const char* idStr, bool createFlag) {
  shared_mem_t* sm;
  SharedMem*    smObj;

  sm = (typeof(sm))malloc(sizeof(*sm));
  try {
    SharedMem::ShmMode shmMode = (createFlag == true) ? SharedMem::ShmMode::CREATE : SharedMem::ShmMode::OPEN; 
    smObj = new SharedMem(idStr, shmMode);
  } catch (...) {
    std::cerr << "shared_mem_create exception thrown" << std::endl; 
  }

  sm->obj = smObj;
  return sm;
}

void shared_mem_destroy(shared_mem_t* sm) {
  if (sm == NULL) {
    return;
  }

  delete static_cast<SharedMem*>(sm->obj);
  free(sm);
}

int64_t shared_mem_sum(shared_mem_t* sm, int64_t a, int64_t b) {
  SharedMem *smObj;
  int64_t result = 0;

  if (sm == NULL) {
    return 0;
  }

  smObj = static_cast<SharedMem*>(sm->obj);
  try { 
    result = smObj->sum(a, b);
  } catch (...) {
    std::cerr << "shared_mem_sum exception thrown" << std::endl; 
  }
    
  return result;
}

message_t* message_create(int64_t id, int64_t value) {
  message_t*          msg;
  SharedMem::Message* msgObj;

  msg = (typeof(msg))malloc(sizeof(*msg));
  try { 
      msgObj = new SharedMem::Message(id, value);
  } catch (...) {
    std::cerr << "shared_mem_create exception thrown" << std::endl; 
  }

  msg->obj = msgObj;
  return msg;
}

message_t* empty_message_create() {
  message_t*          msg;
  SharedMem::Message* msgObj;

  msg = (typeof(msg))malloc(sizeof(*msg));
  try { 
      msgObj = new SharedMem::Message();
  } catch (...) {
    std::cerr << "shared_mem_create exception thrown" << std::endl; 
  }

  msg->obj = msgObj;
  return msg;
}

void message_print(message_t* msg) {
  SharedMem::Message *msgObj;
  if (msg == NULL) {
    return;
  }

  msgObj = static_cast<SharedMem::Message*>(msg->obj);
  try { 
    std::cout << "Msg <id, value>: <" << msgObj->getId() << ", " << msgObj->getValue() << ">" << std::endl;
  } catch (...) {
    std::cerr << "message_print exception thrown" << std::endl; 
  }
}

void message_destroy(message_t* msg) {
  if (msg == NULL) {
    return;
  }

  delete static_cast<SharedMem::Message*>(msg->obj);
  free(msg);
}

bool shared_mem_push_task(shared_mem_t* sm, const message_t* msg) {
  SharedMem* smObj;
  SharedMem::Message* msgObj; 

  if (sm == NULL || msg == NULL) {
    return false;
  }
  smObj = static_cast<SharedMem*>(sm->obj);
  msgObj = static_cast<SharedMem::Message*>(msg->obj);
  
  try { 
    return smObj->pushTask(*msgObj);
  } catch (...) {
    std::cerr << "shared_mem_push_task exception thrown" << std::endl; 
    return false;
  }
}

bool shared_mem_pop_task(shared_mem_t* sm, message_t* msg) {
  SharedMem* smObj;
  SharedMem::Message* msgObj; 

  if (sm == NULL || msg == NULL) {
    return false;
  }
  smObj = static_cast<SharedMem*>(sm->obj);
  msgObj = static_cast<SharedMem::Message*>(msg->obj);
  
  try { 
    return smObj->popTask(*msgObj);
  } catch (...) {
    std::cerr << "shared_mem_pop_task exception thrown" << std::endl; 
    return false;
  }
}

bool shared_mem_push_result(shared_mem_t* sm, const message_t* msg) {
  SharedMem* smObj;
  SharedMem::Message* msgObj; 

  if (sm == NULL || msg == NULL) {
    return false;
  }
  smObj = static_cast<SharedMem*>(sm->obj);
  msgObj = static_cast<SharedMem::Message*>(msg->obj);
  
  try { 
    return smObj->pushResult(*msgObj);
  } catch (...) {
    std::cerr << "shared_mem_push_task exception thrown" << std::endl; 
    return false;
  }
}

bool shared_mem_pop_result(shared_mem_t* sm, message_t* msg) {
  SharedMem* smObj;
  SharedMem::Message* msgObj; 

  if (sm == NULL || msg == NULL) {
    return false;
  }
  smObj = static_cast<SharedMem*>(sm->obj);
  msgObj = static_cast<SharedMem::Message*>(msg->obj);
  
  try { 
    return smObj->popResult(*msgObj);
  } catch (...) {
    std::cerr << "shared_mem_pop_result exception thrown" << std::endl; 
    return false;
  }
}