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

    // Creates task
    let task = sharedMemRs::Task { id_ : 1, value_ : 2};
    let taskPushSuccess = sharedMemRs::shared_mem_push_task(sharedMem, &task);
    println!("Task push Success: {}, data pushed: {:?}", taskPushSuccess, task);
    
    let mut result = sharedMemRs::Result { id_ : 0, value_ : 0};
    let resultPopSuccess = sharedMemRs::shared_mem_pop_result(sharedMem, &result as *const sharedMemRs::Result as *mut sharedMemRs::Result);
    println!("Result pop Success: {}, data popped: {:?}", resultPopSuccess, result);
    
    
    println!("Waiting for Ctrl-C...");
    while running.load(Ordering::SeqCst) {}
    println!("Got it! Destroy shared_mem and exit...");

    // Destroys shared memory
    sharedMemRs::shared_mem_destroy(sharedMem)
  }
}
