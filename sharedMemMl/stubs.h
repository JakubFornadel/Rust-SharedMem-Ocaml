#ifndef _SHARED_MEM_STUBS_H_
#define _SHARED_MEM_STUBS_H_

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include "../../../sharedMemCpp/src/include/SharedMem.h"

extern "C" {
  extern value caml_shared_mem_create(value idStr, value createFlag);
  extern value caml_shared_mem_destroy(value sharedMem);

  extern value caml_push_task(value sharedMem, value task);
  extern value caml_pop_task(value sharedMem, value task);
  extern value caml_push_result(value sharedMem, value result);
  extern value caml_pop_result(value sharedMem, value result);

  extern value caml_task_create(value id, value val);
  extern value caml_task_print(value task);
  extern value caml_task_destroy(value task);
  extern value caml_result_create(value id, value val);
  extern value caml_result_print(value result);
  extern value caml_result_destroy(value result);

  extern value caml_shared_mem_sum(value sharedMem, value a, value b);
}

#endif // _SHARED_MEM_STUBS_H_