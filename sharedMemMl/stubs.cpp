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

CAMLprim value caml_message_create(value id, value val) {
  CAMLparam2(id, val);
  message_t* msg = message_create(Long_val(id), Long_val(val));

  CAMLreturn((value) msg); 
}

CAMLprim value caml_empty_message_create() {
  CAMLparam0();
  message_t* msg = empty_message_create();

  CAMLreturn((value) msg);
}

CAMLprim value caml_message_print(value msg) {
  CAMLparam1(msg);
  message_print((message_t*) msg);

  CAMLreturn(Val_unit);
}

CAMLprim value caml_message_destroy(value msg) {
  CAMLparam1(msg);
  message_t* msgPtr = (message_t*) msg;
  message_destroy(msgPtr);

  CAMLreturn(Val_unit);
}

CAMLprim value caml_push_task(value sharedMem, value msg) {
  CAMLparam2(sharedMem, msg);
  bool result = shared_mem_push_task((shared_mem_t*) sharedMem, (message_t*) msg);

  CAMLreturn(Val_bool(result));
}

CAMLprim value caml_pop_task(value sharedMem, value msg) {
  CAMLparam2(sharedMem, msg);
  bool result = shared_mem_pop_task((shared_mem_t*) sharedMem, (message_t*) msg);

  CAMLreturn(Val_bool(result));
}

CAMLprim value caml_push_result(value sharedMem, value msg) {
  CAMLparam2(sharedMem, msg);
  bool result = shared_mem_push_result((shared_mem_t*) sharedMem, (message_t*) msg);

  CAMLreturn(Val_bool(result));
}

CAMLprim value caml_pop_result(value sharedMem, value msg) {
  CAMLparam2(sharedMem, msg);
  bool result = shared_mem_pop_result((shared_mem_t*) sharedMem, (message_t*) msg);

  CAMLreturn(Val_bool(result));
}