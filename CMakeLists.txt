# cmake_minimum_required(VERSION <specify CMake version here>)
project(TDA_ABB C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TDA_ABB
        main.c)
