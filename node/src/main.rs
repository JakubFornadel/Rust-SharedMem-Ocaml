extern crate sharedMemRs;
use std::ffi::CString;

fn main() {
  println!("Hello, world!");

  let sharedMemFile = CString::new("Test-file.txt").expect("CString::new failed");

  unsafe {
    sharedMemRs::shared_mem_create(sharedMemFile.as_ptr());
  }
}
