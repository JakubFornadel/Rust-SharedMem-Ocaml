Printf.printf "Ocaml Example of calling C++ SharedMem library!\n"

let sharedMem = SharedMem.shared_mem_create "TezosSharedMem" false(* open queues *);;

(* TODO: create Ocaml representation of C Task strucute and use it directly instead of creating it inside lib *)
let taskPop = SharedMem.task_create 0 0;;

(* Pop task from the task queue inside shared memory *)
let popSuccess = SharedMem.pop_task sharedMem taskPop;;
Printf.printf "Pop task Success: %B\n" (popSuccess);;
Printf.printf "Popped task data:\n";;
SharedMem.task_print taskPop;;
SharedMem.task_destroy taskPop;;

let result = SharedMem.result_create 1 4;;
(* Push result into the result queue inside shared memory *)
let pushResultSuccess = SharedMem.push_result sharedMem result;;
Printf.printf "Push result Success: %B\n" (pushResultSuccess);;
SharedMem.result_print result;;
SharedMem.result_destroy result;;

SharedMem.shared_mem_destroy sharedMem;;
