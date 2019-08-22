extern crate sharedMemRs;
use std::ffi::CString;

// Example of calling shared_mem C++ library
fn main() {
  let sharedMemFile = CString::new("Test-file.txt").expect("CString::new failed");

  unsafe {
    // Creates shared memory
    let sharedMem = sharedMemRs::shared_mem_create(sharedMemFile.as_ptr());
    
    // Does some math inside library and check result
    let a: i64 = 2;
    let b: i64 = 3;
    let expectedSum : i64 = a + b;
    let calculatedSum = sharedMemRs::shared_mem_sum(sharedMem, a, b);
    println!("Expected result: {} + {} = {}", a, b, expectedSum);
    println!("Library-calculated result: {} + {} = {}", a, b, calculatedSum);

    let ext_calculatedSum = sharedMemRs::ext_sum_c(a, b);
    println!("Ext Library-calculated result: {} + {} = {}", a, b, ext_calculatedSum);
    
    // Destroys shared memory
    sharedMemRs::shared_mem_destroy(sharedMem)
  }
}
