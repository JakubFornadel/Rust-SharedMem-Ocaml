type t
external shared_mem_create: string -> t = "caml_shared_mem_create"
external shared_mem_destroy: t -> unit = "caml_shared_mem_destroy"
external shared_mem_sum: t -> int -> int -> int = "caml_shared_mem_sum"