(* open Ctypes

(* Try to create Ocaml representation of C struct *)
type Task
let Task : Task structure typ = structure "Task"
let id_  = field Task "id_" int64_t 
let value_ = field Task "value_" int64_t 
let () = seal Task *)

type shm
type task
type result

external shared_mem_create: string -> bool -> shm = "caml_shared_mem_create"
external shared_mem_destroy: shm -> unit = "caml_shared_mem_destroy"
external shared_mem_sum: shm -> int -> int -> int = "caml_shared_mem_sum"

external push_task: shm -> task -> bool = "caml_push_task"
external pop_task: shm -> task -> bool = "caml_pop_task"
external push_result: shm -> result -> bool = "caml_push_result"
external pop_result: shm -> result -> bool = "caml_pop_result"


(* TODO: these functions should be replaced by Ocaml representation of C structures, so they dont not need to be created inside lib *)
external task_create: int -> int -> task = "caml_task_create"
external task_destroy: task -> unit = "caml_task_destroy"
external task_print: task -> unit = "caml_task_print"

external result_create: int -> int -> result = "caml_result_create"
external result_destroy: result -> unit = "caml_result_destroy"
external result_print: result -> unit = "caml_task_print"