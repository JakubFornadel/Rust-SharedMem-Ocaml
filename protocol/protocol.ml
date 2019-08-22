 
print_string "Example of calling C++ library!\n"

let sharedMem = SharedMem.shared_mem_create "sharedMemIdentifier";;

let sharedMemSum = SharedMem.shared_mem_sum sharedMem 6 7;;
Printf.printf "%d\n" (sharedMemSum);;
