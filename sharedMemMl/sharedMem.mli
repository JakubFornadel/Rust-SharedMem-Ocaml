type t
val shared_mem_create : string -> bool -> t 
val shared_mem_destroy : t -> unit 
val shared_mem_sum : t -> int -> int -> int

type d
val message_create : int -> int -> d
val empty_message_create : unit -> d
val message_destroy : d -> unit
val message_print : d -> unit

val push_task : t -> d -> bool
val pop_task : t -> d -> bool
val push_result : t -> d -> bool
val pop_result : t -> d -> bool