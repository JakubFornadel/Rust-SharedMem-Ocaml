# Rust-SharedMem-Ocaml
Use git to clone the repository. 
```Shell 
git clone https://github.com/JakubFornadel/Rust-SharedMem-Ocaml.git 
```

## Node Build instructions
```Shell 
mkdir -p Node/build
cd Node/build
rustc ../node.rs
```

## SharedMemCpp Build instructions
```Shell 
mkdir -p SharedMemCpp/build
cd SharedMemCpp/build
cmake ../
make
```