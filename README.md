# Z-Transform Module

This project implements a C module to calculate the unilateral Z-Transform of a discrete signal.

## Structure

- `include/` - Public headers.
- `src/` - Source code.
- `examples/` - Usage examples.
- `lib/` - Compiled libraries.
- `build/` - Temporary build files.

## Requirements

- GCC with C99 support.
- Standard libraries `complex.h` and `math.h`.

## Compilation

1. `make` - Compiles the library and the example.
2. `make run` - Runs the example.
3. `make clean` - Cleans the generated files.

## Usage

Include `ztransform.h` and link with `libztransform.a` in your project.