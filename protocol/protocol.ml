 
print_string "Hello world!\n"

let sum = SharedMem.add 1 2;;
Printf.printf "%d\n" (sum);;

let summ = SharedMem.ext_sum 3 5;;
Printf.printf "%d\n" (summ);;
