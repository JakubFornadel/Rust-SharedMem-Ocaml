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
dune build

// TODO: unable to run sudo dune install and copy library into the /usr/...

// Quick fix:
dune install --prefix .
sudo cp -r lib/sharedMem/ /home/fornadel/.opam/default/lib/
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



