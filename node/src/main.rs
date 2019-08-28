extern crate sharedMemRs;
use std::ffi::CString;

extern crate ctrlc;
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::Arc;

// Example of calling shared_mem C++ library
fn main() {
  let running = Arc::new(AtomicBool::new(true));
  let r = running.clone();
  ctrlc::set_handler(move || {
      r.store(false, Ordering::SeqCst);
  }).expect("Error setting Ctrl-C handler");
  
  let sharedMemFile = CString::new("TezosSharedMem").expect("CString::new failed");

  unsafe {
    // Creates shared memory
    let sharedMem: *mut sharedMemRs::shared_mem_t = sharedMemRs::shared_mem_create(sharedMemFile.as_ptr(), true /* create queues */);
    
    // Does some math inside library and check result
    let a: i64 = 2;
    let b: i64 = 3;
    let expectedSum : i64 = a + b;
    let calculatedSum = sharedMemRs::shared_mem_sum(sharedMem, a, b);
    println!("Expected result: {} + {} = {}", a, b, expectedSum);
    println!("Library-calculated result: {} + {} = {}", a, b, calculatedSum);

    // Creates message
    let msg: *mut sharedMemRs::message_t = sharedMemRs::message_create(0, 3);
    let taskPushSuccess = sharedMemRs::shared_mem_push_task(sharedMem, msg);
    println!("Task push Success: {} of message: ", taskPushSuccess);
    sharedMemRs::message_print(msg);
    sharedMemRs::message_destroy(msg);
    

    
    
    println!("Waiting for Ctrl-C...");
    while running.load(Ordering::SeqCst) {}
    println!("Got it! Destroy shared_mem and exit...");

    // Destroys shared memory
    sharedMemRs::shared_mem_destroy(sharedMem)
  }
}
