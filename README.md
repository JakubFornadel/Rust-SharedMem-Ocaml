# Rust-SharedMem-Ocaml
Use git to clone the repository. 
```Shell 
git clone https://github.com/JakubFornadel/Rust-SharedMem-Ocaml.git 
```

## Quickstart
Once the environment is properly installed, run following scripts to update C++ library and its wrappers:
```Shell 
cd shareMemCpp/
./install.sh

cd ../sharedMemRs/
./install.sh

cd ../sharedMemMl/
./install.sh
```

## SharedMemCpp Build & Install instructions
```Shell 
mkdir -p sharedMemCpp/build
cd sharedMemCpp/build
cmake ../
make

// for quick install (also for Rust and Ocaml wrappers) run:
./install.sh
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
Ocaml & Dune installation
```Shell 
sudo su
apt-get install ocaml
apt-get install opam
opam init
opam install dune 
```

SharedMemMl building
```Shell 
cd sharedMemMl
// Copy cpp library to be linked. See https://dune.readthedocs.io/en/stable/foreign-code.html  
cp ../sharedMemCpp/build/libSharedMemCpp.a sharedMem/libSharedMemCpp_stubs.a  
cp ../sharedMemCpp/build/libSharedMemCpp.so sharedMem/dllSharedMemCpp_stubs.so
dune build

// TODO: unable to run sudo dune install and copy library into the /usr/...
// Quick fix:
dune install --prefix .
sudo cp -r lib/sharedMem/ /home/fornadel/.opam/default/lib/
sudo cp -r lib/sharedMem_c/ /home/fornadel/.opam/default/lib/
// See for paths https://github.com/ocaml/dune/blob/master/doc/usage.rst#finding-external-libraries - 2. worked for me, after that dune installed-libraries see sharedMem package !

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



