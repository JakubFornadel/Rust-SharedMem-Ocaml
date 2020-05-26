# Rust-SharedMem-Ocaml
Rust-SharedMem-Ocaml is POC implementation of two-way IPC communication between multiple independent Rust and Ocaml processes. 
For that purpose, it uses Cpp library with implemented shared memory and synchronized queue inside as core of the solution. Then Rust & Ocaml wrappers(libraries) are created on top of this library, which are later used in applications. 

Use git to clone the repository. 
```Shell 
git clone https://github.com/JakubFornadel/Rust-SharedMem-Ocaml.git 
```

## Prerequisites
Project was developed and tested under Ubuntu.

### Cpp
- cmake v. >= 3.2
- header library from boost: #include <boost/interprocess/ipc/message_queue.hpp>  

### Ocaml & dune
```Shell 
sudo su
apt-get install ocaml
apt-get install opam
opam init
opam install dune 

// These are optional (not used at the moment)
opam install core 
opam install ctypes 
opam install ctypes-foreign
``` 

### Rust
- To intall Rust, follow https://doc.rust-lang.org/cargo/getting-started/installation.html


## Quickstart
Once the environment is properly installed, run following scripts to update C++ library and its wrappers:
```Shell 
cd shareMemCpp/
./install.sh
./setup.sh  // run only one time. It creates symlinks to Cpp library for Ocaml and Rust wrappers

cd ../sharedMemRs/
./install.sh

cd ../sharedMemMl/
./install.sh

cd ../
```

Once the wrappers are succefully built, run following commands to start-up applications:
```Shell 
cd node/          // Node(Rust) must be started first
cargo build 
cargo run

cd ../protocol    // Protocol(Ocaml) second
dune exec ./protocol.exe
```

## SharedMemCpp Build & Install instructions
```Shell 
mkdir -p sharedMemCpp/build
cd sharedMemCpp/build
cmake ../
make
cd ../

// for quick install (also for Rust and Ocaml wrappers) run:
./install.sh

// for one-time setup (creates symlinks to lib for Ocaml and Rust) run:
./setup.sh

```

## SharedMemRs Build instructions
```Shell 
cd sharedMemRs
cargo build

// To run tests
cargo test

// for quick install run
./install.sh
```

## SharedMemMl Build instructions 
SharedMemMl building
```Shell 
cd sharedMemMl
// Creates symlinks to Cpp library. See https://dune.readthedocs.io/en/stable/foreign-code.html  
ln -s $PWD/../sharedMemCpp/build/libSharedMemCpp.so sharedMem/libSharedMemCpp_stubs.a  
ln -s $PWD/../sharedMemCpp/build/libSharedMemCpp.so sharedMem/dllSharedMemCpp_stubs.so
dune build

dune install --prefix .
sudo cp -r lib/sharedMem/ ~/.opam/default/lib/
sudo cp -r lib/sharedMem_c/ ~/.opam/default/lib/
// Check https://github.com/ocaml/dune/blob/master/doc/usage.rst#finding-external-libraries - 2. worked for me, after that dune installed-libraries can see sharedMem package !

// for quick install run:
./install.sh
```

## Node Build instructions
```Shell 
cd node/
cargo build
cargo run
```

## Ocaml Protocol Build instructions
```Shell 
cd protocol/

dune build protocol.exe
./_build/default/protocol.exe

or

dune exec ./protocol.exe
```



