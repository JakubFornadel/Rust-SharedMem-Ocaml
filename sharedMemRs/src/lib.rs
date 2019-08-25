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
      let sharedMemFile = CString::new("Test-file.txt").expect("CString::new failed");
      let sharedMem = shared_mem_create(sharedMemFile.as_ptr());
      
      let a: i64 = 2;
      let b: i64 = 3;
      let expectedSum : i64 = a + b;
      let calculatedSum = shared_mem_sum(sharedMem, a, b);
      assert_eq!(expectedSum, calculatedSum);

      shared_mem_destroy(sharedMem)
    }
  }

}