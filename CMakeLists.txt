cmake_minimum_required(VERSION 3.28)
project(Airlib C)

set(CMAKE_C_STANDARD 23)

# Create the shared library target
add_library(Airlib SHARED
        # Source
        src/audio.c
        src/graphics.c
        src/old.c

        # Headers
        include/graphics.h
        include/old.h
        include/audio.h
        main.c
)

# Link the winmm library to the Airlib target
target_link_libraries(Airlib PRIVATE winmm)
