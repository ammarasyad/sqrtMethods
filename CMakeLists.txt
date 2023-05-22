cmake_minimum_required(VERSION 3.25)
project(Makalah CXX ASM_MASM)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Ox /arch:AVX2")

# CMake 3.25
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "3c375311-a3c9-4396-a187-3227ef642046")

# CMake 3.26
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

add_library(sqrtmath STATIC assembly_sqrt.asm sqrtmath.ixx)
add_executable(Makalah main.cpp)
target_link_libraries(Makalah PRIVATE sqrtmath)
