cmake_minimum_required(VERSION 3.28)
project(Airlib C)

set(CMAKE_C_STANDARD 23)

add_library(Airlib SHARED
        # Source
        src/audio.c
        src/graphics.c
        src/old.c

        # Headers
        include/graphics.h
        include/old.h
)

# add_executable(Airlib_main src/graphics.c)