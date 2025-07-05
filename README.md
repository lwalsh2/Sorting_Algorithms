# Sorting Algorithms
This is a Sorting Algorithm project that utilizes `c` to build different algorithms as examples.

## Dependencies:
    cmake
    invoke

## Building with Invoke
This project can be built with Python's Invoke module. Using `invoke build` will build the libraries and tests. The libraries will be within `build/src`, and the test binaries will be in `bin/`.

## Testing with Invoke
After running `invoke build`, the test binaries can be run directly from the `bin/` folder. Alternatively, you can build and run tests with `invoke test <algorithm>` with `all` running all the tests.
