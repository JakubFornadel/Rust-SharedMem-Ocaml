cd build/
cmake ../
make

# Copy lib for Rust wrapper so Rust can find this library - TODO: provide Rust directory path ! 
sudo cp libSharedMemCpp.so /usr/lib/libSharedMemCpp.so

# Copy lib for Ocaml wrapper and rename it to required format so Ocaml can find it
cp libSharedMemCpp.a  ../../sharedMemMl/sharedMem/libSharedMemCpp_stubs.a  
cp libSharedMemCpp.so ../../sharedMemMl/sharedMem/dllSharedMemCpp_stubs.so

cd ../..

