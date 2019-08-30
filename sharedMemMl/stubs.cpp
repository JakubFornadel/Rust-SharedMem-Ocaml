#include "stubs.h"

CAMLprim value caml_shared_mem_create(value idStr, value createFlag) {
  CAMLparam1(idStr);
  shared_mem_t* sharedMem = shared_mem_create(String_val(idStr), Bool_val(createFlag));

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

CAMLprim value caml_push_task(value sharedMem, value task) {
  CAMLparam2(sharedMem, task);
  bool success = shared_mem_push_task((shared_mem_t*) sharedMem, (Task*) task);

  CAMLreturn(Val_bool(success));
}

CAMLprim value caml_pop_task(value sharedMem, value task) {
  CAMLparam2(sharedMem, task);
  bool success = shared_mem_pop_task((shared_mem_t*) sharedMem, (Task*) task);

  CAMLreturn(Val_bool(success));
}

CAMLprim value caml_push_result(value sharedMem, value result) {
  CAMLparam2(sharedMem, result);
  bool success = shared_mem_push_result((shared_mem_t*) sharedMem, (Result*) result);

  CAMLreturn(Val_bool(success));
}

CAMLprim value caml_pop_result(value sharedMem, value result) {
  CAMLparam2(sharedMem, result);
  bool success = shared_mem_pop_result((shared_mem_t*) sharedMem, (Result*) result);

  CAMLreturn(Val_bool(success));
}

// TODO: these functions should be replaced by Ocaml representation of C structures, so they dont not need to be created inside lib
CAMLprim value caml_task_create(value id, value val) {
  CAMLparam2(id, val);
  Task* task = task_create(Long_val(id), Long_val(val));

  CAMLreturn((value) task); 
}

CAMLprim value caml_task_print(value task) {
  CAMLparam1(task);
  task_print((Task*) task);

  CAMLreturn(Val_unit);
}

CAMLprim value caml_task_destroy(value task) {
  CAMLparam1(task);
  Task* taskPtr = (Task*) task;
  task_destroy(taskPtr);

  CAMLreturn(Val_unit);
}

CAMLprim value caml_result_create(value id, value val) {
  CAMLparam2(id, val);
  Result* result = result_create(Long_val(id), Long_val(val));

  CAMLreturn((value) result); 
}

CAMLprim value caml_result_print(value result) {
  CAMLparam1(result);
  result_print((Result*) result);

  CAMLreturn(Val_unit);
}

CAMLprim value caml_result_destroy(value result) {
  CAMLparam1(result);
  Result* resultPtr = (Result*) result;
  result_destroy(resultPtr);

  CAMLreturn(Val_unit);
}