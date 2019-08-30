# One time setup

# Create link for Rust wrapper so Rust can find this library - TODO: provide Rust directory path ! 
sudo ln -s $PWD/build/libSharedMemCpp.so /usr/lib/libSharedMemCpp.so

# Create link for Ocaml wrapper and rename it to required format so Ocaml can find it
ln -s $PWD/build/libSharedMemCpp.so ../sharedMemMl/sharedMem/libSharedMemCpp_stubs.a
ln -s $PWD/build/libSharedMemCpp.so ../sharedMemMl/sharedMem/dllSharedMemCpp_stubs.so

