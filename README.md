# avr-makefile
A makefile that
* breaks down compilation into the four stages of complation:
    1. preprocess
    2. compile
    3. assemble
    4. link
* debugs code locally or remotely in `gdb`.
* uploads binary to AVR device with `avrdude`, using the programmer of your choice. Arduino programmer is supported and chosen by default.
* simulates all AVR registers using `simavr` and dumps output as GTKWave trace

