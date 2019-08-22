#ifndef _SHARED_MEM_STUBS_H_
#define _SHARED_MEM_STUBS_H_

extern "C" {
  #include <caml/mlvalues.h>
  #include <caml/memory.h>
  #include <SharedMem.h>

  extern value caml_ext_sum_c(value a, value b);
}

#endif // _SHARED_MEM_STUBS_H_