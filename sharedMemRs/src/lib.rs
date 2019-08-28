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

      // let msgPush = message_create(0, 3);
      // let msgPop = empty_message_create();
      // message_print(msgPush);
      // message_print(msgPop);

      // let pushResult = shared_mem_push_task(sharedMem, msgPush);
      // assert_eq!(pushResult, true);
      // let popResult = shared_mem_pop_task(sharedMem, msgPop);
      // assert_eq!(popResult, true);

      // message_print(msgPop);

      // message_destroy(msgPush);
      // message_destroy(msgPop);
      shared_mem_destroy(sharedMem)
    }
  }

}