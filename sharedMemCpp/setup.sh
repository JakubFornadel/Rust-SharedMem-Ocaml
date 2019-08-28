# One time setups

# Copy lib for Rust wrapper so Rust can find this library - TODO: provide Rust directory path ! 
sudo ln -s ~/workspace/Tezos/Rust-SharedMem-Ocaml/sharedMemCpp/build/libSharedMemCpp.so /usr/lib/libSharedMemCpp.so

# Copy lib for Ocaml wrapper and rename it to required format so Ocaml can find it
ln -s ~/workspace/Tezos/Rust-SharedMem-Ocaml/sharedMemCpp/build/libSharedMemCpp.so ~/workspace/Tezos/Rust-SharedMem-Ocaml/sharedMemMl/sharedMem/libSharedMemCpp_stubs.a
ln -s ~/workspace/Tezos/Rust-SharedMem-Ocaml/sharedMemCpp/build/libSharedMemCpp.so ~/workspace/Tezos/Rust-SharedMem-Ocaml/sharedMemMl/sharedMem/dllSharedMemCpp_stubs.so

