cmake_minimum_required(VERSION 3.21)
project(Airlib C)

set(CMAKE_C_STANDARD 23)

# Create the shared library target
add_library(Airlib SHARED
        # Source
		  src/system/gnu_linux/linux_audio.c
        src/system/gnu_linux/linux_video.c
        src/system/terminal.c
        src/system/Windows/WIN_audio.c
        src/system/Windows/WIN_video.c

        # Headers
        include/video.h
        include/terminal.h
        include/audio.h
        include/Airlib.h
        include/cute_airlib.h
)

if(UNIX AND NOT APPLE)
	find_package(GLUT REQUIRED)
  find_package(OpenGL REQUIRED)
  target_link_libraries(Airlib PRIVATE X11 OpenGL::GL GLUT::GLUT pulse-simple)
elseif(WIN32)
  target_link_libraries(Airlib winmm)
	target_link_libraries(Airlib opengl32)
	target_link_libraries(Airlib
			gdi32
			freeglut
	)
endif()

# Create the Airlib_test executable
add_executable(Airlib_test main.c)

# Link the Airlib library to the Airlib_test executable
target_link_libraries(Airlib_test PRIVATE Airlib)

if (UNIX AND NOT APPLE)
	  target_link_libraries(Airlib_test PRIVATE OpenGL::GL GLUT::GLUT X11)
endif()

#[[ 
Copyright (C) 2024 Ellouze Adam <elzadam11@tutamail.com>
  
This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:
  
1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required. 
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
]]

