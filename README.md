# Methods of squaring a number

---
## Requirements to compile:
1. CLion or Visual Studio 2022
2. CMake 3.25 or higher
3. C++ compiler with C++20 support

---
## How to compile:
1. Open the project in CLion or Visual Studio 2022
2. Build the project
3. Run the compiled program

If the program fails to run at the part of ASM code, you may not have the supported processor and thus missing the AVX instruction set. To fix, simply replace `vsqrtpd` in [assembly_sqrt.asm](https://github.com/ammarasyad/sqrtMethods/blob/master/assembly_sqrt.asm) with `sqrtpd`.