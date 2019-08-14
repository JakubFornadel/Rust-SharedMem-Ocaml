# Rust-SharedMem-Ocaml
Use git to clone the repository. 
```Shell 
git clone https://github.com/JakubFornadel/Rust-SharedMem-Ocaml.git 
```

## SharedMemCpp Build & Install instructions
```Shell 
mkdir -p sharedMemCpp/build
cd sharedMemCpp/build
cmake ../
sudo make install
// Make symlink so Rust can find this library - TODO: provide Rust directory path ! 
sudo ln -s /usr/local/lib/libSharedMemCpp.so /usr/lib/libSharedMemCpp.so
```

## SharedMemRs Build instructions
```Shell 
cd sharedMemRs
cargo build

// To run tests
cargo test
```

## Node Build instructions
```Shell 
cd node/
cargo build
cargo run
```