#include "stubs.h"

CAMLprim value caml_shared_mem_create(value idStr) {
  CAMLparam1(idStr);
  shared_mem_t* sharedMem = shared_mem_create(String_val(idStr));

  CAMLreturn((value) sharedMem); 
}

CAMLprim value caml_shared_mem_destroy(value sharedMem) {
  CAMLparam1(sharedMem);
  shared_mem_t* sharedMemPtr = (shared_mem_t*) sharedMem;
  shared_mem_destroy(sharedMemPtr);

  CAMLreturn(Val_unit);
}

CAMLprim value caml_shared_mem_sum(value sharedMem, value a, value b) {
  CAMLparam3(sharedMem, a, b);
  uint64_t sum = shared_mem_sum((shared_mem_t*)sharedMem, Long_val(a), Long_val(b));

  CAMLreturn(Val_long(sum));
}