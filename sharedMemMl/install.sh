cp ../sharedMemCpp/build/libSharedMemCpp.a sharedMem/libSharedMemCpp_stubs.a  
cp ../sharedMemCpp/build/libSharedMemCpp.so sharedMem/dllSharedMemCpp_stubs.so

dune install --prefix .
sudo cp -r ../sharedMemMl/lib/sharedMem/ /home/fornadel/.opam/default/lib/
sudo cp -r ../sharedMemMl/lib/sharedMem_c/ /home/fornadel/.opam/default/lib/
