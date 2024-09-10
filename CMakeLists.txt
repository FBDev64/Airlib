cmake_minimum_required(VERSION 3.28)
project(Airlib C)

set(CMAKE_C_STANDARD 23)

add_library(Airlib SHARED src/library.c
        src/library.h)
