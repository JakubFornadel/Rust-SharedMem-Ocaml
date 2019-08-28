rm -rf _build/
rm -rf lib/

dune build --profile release
dune install --prefix .

sudo cp -r ../sharedMemMl/lib/sharedMem/ ~/.opam/default/lib/
sudo cp -r ../sharedMemMl/lib/sharedMem_c/ ~/.opam/default/lib/
