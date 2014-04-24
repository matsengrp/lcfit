# `lcfit`

Likelihood curve fitting by nonlinear least squares.

# Building

## Dependencies

Building the library requires [cmake][1]

The lcfit C-library requires the [GNU Scientific Library][2] (`libgsl0-dev` on debian).

The `lcfit-compare` tool requires a C++11-compatible compiler, and the `bpp-core`, `bpp-seq`, and `bpp-phyl` libraries from the [Bio++ suite version 2.0.3 or 2.1.0][3] (`libbpp-{core,seq,phyl}-dev` on debian).

Running the unit tests requires python.

## Compiling

Run `make` to obtain static and dynamic libraries.

Run `make doc` to build documentation.

## Running unit tests

To run the test suite, run `make test`

[1]: http://www.cmake.org
[2]: http://www.gnu.org/s/gsl
[3]: http://biopp.univ-montp2.fr
