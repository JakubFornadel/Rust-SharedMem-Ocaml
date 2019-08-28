type t
external shared_mem_create: string -> bool -> t = "caml_shared_mem_create"
external shared_mem_destroy: t -> unit = "caml_shared_mem_destroy"
external shared_mem_sum: t -> int -> int -> int = "caml_shared_mem_sum"

type d
external message_create: int -> int -> d = "caml_message_create"
external empty_message_create: unit -> d = "caml_empty_message_create"
external message_destroy: d -> unit = "caml_message_destroy"
external message_print: d -> unit = "caml_message_print"

external push_task: t -> d -> bool = "caml_push_task"
external pop_task: t -> d -> bool = "caml_pop_task"
external push_result: t -> d -> bool = "caml_push_result"
external pop_result: t -> d -> bool = "caml_pop_result"