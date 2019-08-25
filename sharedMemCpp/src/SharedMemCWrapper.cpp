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

shared_mem_t* shared_mem_create(const char* idStr) {
  shared_mem_t* sm;
  SharedMem*    smObj;

  sm = (typeof(sm))malloc(sizeof(*sm));
  try { 
    smObj = new SharedMem(idStr);
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

// bool shared_mem_push_task(shared_mem_t* sm, const message_t* msg) {
//   SharedMem* smObj;
//   SharedMem::Message* msgObj; 

//   if (sm == NULL || msg == NULL) {
//     return false;
//   }
//   smObj = static_cast<SharedMem*>(sm->obj);
//   msgObj = static_cast<SharedMem::Message*>(msg->obj);
  
//   try { 
//     return smObj->pushTask(*msgObj);
//   } catch (...) {
//     std::cerr << "shared_mem_push_task exception thrown" << std::endl; 
//     return false;
//   }
// }

// bool shared_mem_pop_task(shared_mem_t* sm, message_t* msg) {
//   SharedMem* smObj;
//   SharedMem::Message* msgObj; 

//   if (sm == NULL || msg == NULL) {
//     return false;
//   }
//   smObj = static_cast<SharedMem*>(sm->obj);
//   msgObj = static_cast<SharedMem::Message*>(msg->obj);
  
//   try { 
//     return smObj->popTask(*msgObj);
//   } catch (...) {
//     std::cerr << "shared_mem_pop_task exception thrown" << std::endl; 
//     return false;
//   }
// }

// bool shared_mem_push_result(shared_mem_t* sm, const message_t* msg) {
//   SharedMem* smObj;
//   SharedMem::Message* msgObj; 

//   if (sm == NULL || msg == NULL) {
//     return false;
//   }
//   smObj = static_cast<SharedMem*>(sm->obj);
//   msgObj = static_cast<SharedMem::Message*>(msg->obj);
  
//   try { 
//     return smObj->pushResult(*msgObj);
//   } catch (...) {
//     std::cerr << "shared_mem_push_task exception thrown" << std::endl; 
//     return false;
//   }
// }

// bool shared_mem_pop_result(shared_mem_t* sm, message_t* msg) {
//   SharedMem* smObj;
//   SharedMem::Message* msgObj; 

//   if (sm == NULL || msg == NULL) {
//     return false;
//   }
//   smObj = static_cast<SharedMem*>(sm->obj);
//   msgObj = static_cast<SharedMem::Message*>(msg->obj);
  
//   try { 
//     return smObj->popResult(*msgObj);
//   } catch (...) {
//     std::cerr << "shared_mem_pop_result exception thrown" << std::endl; 
//     return false;
//   }
// }


bool shared_mem_push_task(shared_mem_t* sm, const int* msg) {
  SharedMem* smObj;
  const SharedMem::Message* msgObj; 

  if (sm == NULL || msg == NULL) {
    return false;
  }
  smObj = static_cast<SharedMem*>(sm->obj);
  msgObj = static_cast<const SharedMem::Message*>(msg);
  
  try { 
    return smObj->pushTask(*msgObj);
  } catch (...) {
    std::cerr << "shared_mem_push_task exception thrown" << std::endl; 
    return false;
  }
}

bool shared_mem_pop_task(shared_mem_t* sm, int* msg) {
  SharedMem* smObj;
  SharedMem::Message* msgObj; 

  if (sm == NULL || msg == NULL) {
    return false;
  }
  smObj = static_cast<SharedMem*>(sm->obj);
  msgObj = static_cast<SharedMem::Message*>(msg);
  
  try { 
    return smObj->popTask(*msgObj);
  } catch (...) {
    std::cerr << "shared_mem_pop_task exception thrown" << std::endl; 
    return false;
  }
}

bool shared_mem_push_result(shared_mem_t* sm, const int* msg) {
  SharedMem* smObj;
  const SharedMem::Message* msgObj; 

  if (sm == NULL || msg == NULL) {
    return false;
  }
  smObj = static_cast<SharedMem*>(sm->obj);
  msgObj = static_cast<const SharedMem::Message*>(msg);
  
  try { 
    return smObj->pushResult(*msgObj);
  } catch (...) {
    std::cerr << "shared_mem_push_task exception thrown" << std::endl; 
    return false;
  }
}

bool shared_mem_pop_result(shared_mem_t* sm, int* msg) {
  SharedMem* smObj;
  SharedMem::Message* msgObj; 

  if (sm == NULL || msg == NULL) {
    return false;
  }
  smObj = static_cast<SharedMem*>(sm->obj);
  msgObj = static_cast<SharedMem::Message*>(msg);
  
  try { 
    return smObj->popResult(*msgObj);
  } catch (...) {
    std::cerr << "shared_mem_pop_result exception thrown" << std::endl; 
    return false;
  }
}