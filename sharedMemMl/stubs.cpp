#include "stubs.h"

CAMLprim value caml_ext_sum_c(value a, value b) {
    uint64_t a_int = Long_val(a);
    uint64_t b_int = Long_val(b);
    uint64_t sum = a_int + b_int;

    return Val_long(sum);
}