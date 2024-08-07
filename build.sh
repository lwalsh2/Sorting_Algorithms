#!/bin/bash

# Clear out the bin folder if present before building new binaries
rm -r bin
mkdir -p bin
cd bin
cmake ..
make -j$(nproc)
cd ..
