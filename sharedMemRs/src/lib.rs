#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
  use super::*;
  use std::ffi::CString;

  #[test]
  fn shared_mem_create_test() {
    unsafe {
      let sharedMemFile = CString::new("TestSharedMemId").expect("CString::new failed");
      let sharedMem = shared_mem_create(sharedMemFile.as_ptr(), true /* create queues */);
      
      let a: i64 = 2;
      let b: i64 = 3;
      let expectedSum : i64 = a + b;
      let calculatedSum = shared_mem_sum(sharedMem, a, b);
      assert_eq!(expectedSum, calculatedSum);

      let task = Task {id_ : 1, value_ : 2};
      let taskPushSuccess = shared_mem_push_task(sharedMem, &task);

      let result = Result {id_ : 0, value_ : 0};
      assert_ne!(task.id_, result.id_);

      let resultPopSuccess = shared_mem_pop_task(sharedMem, &result as *const Result as *mut Result);
      assert_eq!(task.id_, result.id_);

      shared_mem_destroy(sharedMem)
    }
  }

}