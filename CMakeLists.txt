cmake_minimum_required(VERSION 3.28)
project(Airlib C)

set(CMAKE_C_STANDARD 23)

# Create the shared library target
add_library(Airlib SHARED
        # Source
	# src/system/linux/linux_audio.c
        src/system/linux/linux_graphics.c
        src/old.c
        src/system/Windows/WIN_audio.c
        src/system/Windows/WIN_graphics.c

        # Headers
        include/graphics.h
        include/old.h
        include/audio.h
        include/Airlib.h
        include/cute_airlib.h
)

if(UNIX AND NOT APPLE)
    target_link_libraries(Airlib PRIVATE X11)
elseif(WIN32)
        target_link_libraries(Airlib winmm)
endif()

# Create the Airlib_test executable
add_executable(Airlib_test main.c)

# Link the Airlib library to the Airlib_test executable
target_link_libraries(Airlib_test PRIVATE Airlib)
