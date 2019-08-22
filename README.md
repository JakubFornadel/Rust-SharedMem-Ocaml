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
make
// Make symlink so Rust can find this library - TODO: provide Rust directory path ! 
sudo cp libSharedMemCpp.so /usr/lib/libSharedMemCpp.so
```

## SharedMemRs Build instructions
```Shell 
cd sharedMemRs
cargo build

// To run tests
cargo test
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
./instal.sh // installation script, which consists of:

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



