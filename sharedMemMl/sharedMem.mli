type t
val shared_mem_create : string -> t 
val shared_mem_destroy : t -> unit 
val shared_mem_sum : t -> int -> int -> int

