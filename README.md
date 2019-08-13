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
```

## SharedMemRs Build instructions
```Shell 
cd sharedMemRs
cargo build
```

## Node Build instructions
```Shell 
mkdir -p node/build
cd node/build
rustc ../node.rs
```