extern crate sharedMemRs;
use std::ffi::CString;

// Example of calling shared_mem C++ library
fn main() {
  let sharedMemFile = CString::new("Test-file.txt").expect("CString::new failed");

  unsafe {
    // Creates shared memory
    let sharedMem: *mut sharedMemRs::shared_mem_t;
    sharedMem = sharedMemRs::shared_mem_create(sharedMemFile.as_ptr());
    
    // Does some math inside library and check result
    let a: i64 = 2;
    let b: i64 = 3;
    let expectedSum : i64 = a + b;
    let calculatedSum = sharedMemRs::shared_mem_sum(sharedMem, a, b);
    println!("Expected result: {} + {} = {}", a, b, expectedSum);
    println!("Library-calculated result: {} + {} = {}", a, b, calculatedSum);

    // Creates shared memory
    let pushValue: i32 = 10;
    let pushData: *const i32 = &pushValue;
    let taskPushSuccess = sharedMemRs::shared_mem_push_task(sharedMem, pushData);
    println!("Task push of {}. Success: {}", *pushData, taskPushSuccess);

    let mut popValue: i32 = 0;
    let popData: *mut i32 = &mut popValue;
    println!("Task pop of default value: {}", *popData);
    let taskPopSuccess = sharedMemRs::shared_mem_pop_task(sharedMem, popData);
    println!("Task pop of {}. Success: {}", *popData, taskPopSuccess);
    
    // Destroys shared memory
    sharedMemRs::shared_mem_destroy(sharedMem)
  }
}
