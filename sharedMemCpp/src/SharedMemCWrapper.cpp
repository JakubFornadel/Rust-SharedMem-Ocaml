#include <iostream>
#include "include/SharedMem.hpp"
#include "include/SharedMem.h"

struct shared_mem {
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

bool shared_mem_push_task(shared_mem_t* sm, const Task* task) {
  SharedMem* smObj;

  if (sm == NULL || task == NULL) {
    return false;
  }
  smObj = static_cast<SharedMem*>(sm->obj);
  
  try { 
    return smObj->pushTask(*task);
  } catch (...) {
    std::cerr << "shared_mem_push_task exception thrown" << std::endl; 
    return false;
  }
}

bool shared_mem_pop_task(shared_mem_t* sm, Task* task) {
  SharedMem* smObj;

  if (sm == NULL || task == NULL) {
    return false;
  }
  smObj = static_cast<SharedMem*>(sm->obj);
  
  try { 
    return smObj->popTask(*task);
  } catch (...) {
    std::cerr << "shared_mem_pop_task exception thrown" << std::endl; 
    return false;
  }
}

bool shared_mem_push_result(shared_mem_t* sm, const Result* result) {
  SharedMem* smObj;

  if (sm == NULL || result == NULL) {
    return false;
  }
  smObj = static_cast<SharedMem*>(sm->obj);
  
  try { 
    return smObj->pushResult(*result);
  } catch (...) {
    std::cerr << "shared_mem_push_task exception thrown" << std::endl; 
    return false;
  }
}

bool shared_mem_pop_result(shared_mem_t* sm, Result* result) {
  SharedMem* smObj;

  if (sm == NULL || result == NULL) {
    return false;
  }
  smObj = static_cast<SharedMem*>(sm->obj);
  
  try { 
    return smObj->popResult(*result);
  } catch (...) {
    std::cerr << "shared_mem_pop_result exception thrown" << std::endl; 
    return false;
  }
}


// For Ocaml
Task* task_create(int64_t id, int64_t value) {
  Task* task;

  try { 
      task = new Task{id, value};
  } catch (...) {
    std::cerr << "task_create exception thrown" << std::endl; 
  }

  return task;
}
Result* result_create(int64_t id, int64_t value) {
  return task_create(id, value);
}

void task_print(Task* task) {
  if (task == NULL) {
    return;
  }

  try { 
    std::cout << "Msg <id, value>: <" << task->id_ << ", " << task->value_ << ">" << std::endl;
  } catch (...) {
    std::cerr << "task_print exception thrown" << std::endl; 
  }
}
void result_print(Result* result) {
  task_print(result);
}

void task_destroy(Task* task) {
  if (task == NULL) {
    return;
  }

  delete task;
}
void result_destroy(Result* result) {
  task_destroy(result);
}