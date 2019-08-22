#ifndef _SHARED_MEM_STUBS_H_
#define _SHARED_MEM_STUBS_H_

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <SharedMem.h>

extern "C" {
  extern value caml_shared_mem_create(value idStr);
  extern value caml_shared_mem_destroy(value sharedMem);
  extern value caml_shared_mem_sum(value sharedMem, value a, value b);
}

#endif // _SHARED_MEM_STUBS_H_