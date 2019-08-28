Printf.printf "Ocaml Example of calling C++ SharedMem library!\n"

let sharedMem = SharedMem.shared_mem_create "TezosSharedMem" false(* open queues *);;

(* let task = SharedMem.task_create 2 4;;
let pushSuccess = SharedMem.push_task sharedMem task;;
Printf.printf "Push task Success: %B of message\n" (pushSuccess);;
SharedMem.task_print task;;
SharedMem.task_destroy task;; *)

let taskPop = SharedMem.task_create 0 0;;
(* Printf.printf "Default pop task data holder:\n";;
SharedMem.task_print taskPop;; *)

let popSuccess = SharedMem.pop_task sharedMem taskPop;;
Printf.printf "Pop task Success: %B of message\n" (popSuccess);;
Printf.printf "Popped task data:\n";;
SharedMem.task_print taskPop;;
SharedMem.task_destroy taskPop;;

let result = SharedMem.result_create 3 4;;
let pushResultSuccess = SharedMem.push_result sharedMem result;;
Printf.printf "Push result Success: %B of message\n" (pushResultSuccess);;
SharedMem.result_print result;;
SharedMem.result_destroy result;;

SharedMem.shared_mem_destroy sharedMem;;
