# Methods of squaring a number

## Requirements to run:
1. Windows 10/11
2. Any CPU with the AVX instruction set support (can be mitigated by the workaround at the end of this README)

## How to run:
1. Download the `bin` folder
2. Run the .exe file

## Requirements to compile:
1. CLion or Visual Studio 2022
2. CMake 3.25 or higher
3. C++ compiler with C++20 support

## How to compile:
1. Open the project in CLion or Visual Studio 2022
2. Build the project
3. Run the compiled program

If the program fails to run at the part of ASM code, you may not have the supported processor and thus missing the AVX instruction set. To fix, simply replace `vsqrtpd` in [assembly_sqrt.asm](https://github.com/ammarasyad/sqrtMethods/blob/master/assembly_sqrt.asm) with `sqrtpd`.
