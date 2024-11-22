#include <GL/gl.h>
#include "include/video.h"

int main(void) {
    // Create an instance of the Window interface
    Window* window = createWindowInstance();

    // Create a window with OpenGL context
    window->create(800, 600, "Custom OpenGL Window");

    // Main loop
    while (!window->shouldClose()) {
        // Poll for events
        window->pollEvents();

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw a button and text
        window->drawButton(-0.5f, -0.5f, 1.0f, 0.3f, "Click Me");
        window->drawText(-0.8f, 0.8f, "Hello, OpenGL!");

        // Swap buffers
        window->swapBuffers();
    }

    // Clean up and destroy the window
    window->destroy();
    return 0;
}


/*
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
*/
