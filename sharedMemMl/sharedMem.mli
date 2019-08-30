type shm
type task
type result

val shared_mem_create : string -> bool -> shm
val shared_mem_destroy : shm -> unit
val shared_mem_sum : shm -> int -> int -> int

val push_task : shm -> task -> bool
val pop_task : shm -> task -> bool
val push_result : shm -> result -> bool
val pop_result : shm -> result -> bool


(* TODO: these functions should be replaced by Ocaml representation of C structures, so they dont not need to be created inside lib *)
val task_create : int -> int -> task
val task_destroy : task -> unit
val task_print : task -> unit

val result_create : int -> int -> result
val result_destroy : result -> unit
val result_print : result -> unit
