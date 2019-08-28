 
Printf.printf "Ocaml Example of calling C++ SharedMem library!\n"

let sharedMem = SharedMem.shared_mem_create "TezosSharedMem" false(* open queues *);;

let msgPush = SharedMem.message_create 7 9;;
let pushSuccess = SharedMem.push_task sharedMem msgPush;;
Printf.printf "Push task Success: %B of message\n" (pushSuccess);;
SharedMem.message_print msgPush;;
SharedMem.message_destroy msgPush;;

let msgPop = SharedMem.empty_message_create ();;
SharedMem.message_print msgPop;;
let popSuccess = SharedMem.pop_task sharedMem msgPop;;
Printf.printf "Pop task Success: %B of message\n" (popSuccess);;
SharedMem.message_print msgPop;;
SharedMem.message_destroy msgPop;;

let sharedMemSum = SharedMem.shared_mem_sum sharedMem 6 7;;
Printf.printf "%d\n" (sharedMemSum);;

SharedMem.shared_mem_destroy sharedMem;;
