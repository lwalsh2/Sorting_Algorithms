#!/bin/bash

# Clear out the bin folder if present before building new binaries
rm -rf bin
mkdir bin
cmake -B bin -S .
cd bin
make
