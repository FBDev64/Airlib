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
)

# Link the winmm library to the Airlib target (Windows-specific)
target_link_libraries(Airlib PRIVATE winmm)

# Create the Airlib_test executable
add_executable(Airlib_test main.c)

# Link the Airlib library to the Airlib_test executable
target_link_libraries(Airlib_test PRIVATE Airlib)
