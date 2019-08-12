#include <iostream>

#include <SharedMem.hpp>
#include <SharedMem.h>

struct shared_mem {
	void *obj;
};

shared_mem_t* shared_mem_create(const char* file_name) {
	shared_mem_t* m;
	SharedMem*    obj;

	m = (typeof(m))malloc(sizeof(*m));
  try { 
    obj = new SharedMem(file_name);
  } catch (...) {
      std::cerr << "shared_mem_create exception thrown" << std::endl; 
  }

	m->obj = obj;
	return m;
}

void shared_mem_destroy(shared_mem_t* m) {
  if (m == NULL) {
    return;
  }

  delete static_cast<SharedMem*>(m->obj);
  free(m);
}

int64_t shared_mem_sum(shared_mem_t* m, int64_t a, int64_t b) {
  SharedMem *obj;
  int64_t result = 0;

  if (m == NULL) {
    return 0;
  }

	obj = static_cast<SharedMem*>(m->obj);
	try { 
    result = obj->sum(a, b);
  } catch (...) {
      std::cerr << "shared_mem_sum exception thrown" << std::endl; 
  }
    
  return result;
}

const char* shared_mem_file_name(shared_mem_t *m) {
  SharedMem *obj;

	if (m == NULL) {
    return "";
  }

	obj = static_cast<SharedMem*>(m->obj);
	return obj->getFileName().c_str();
}
