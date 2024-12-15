#include "include/vdl.h"
#include <GL/gl.h>

int main() {
    Win* window = createWindowInstance();
    window->create(600, 700, "VDL/GL Test");

    unsigned char textColor[3] = {34, 84, 2};

    while (!window->shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set color for button
        glColor3f(1.0f, 0.0f, 0.0f);  // Red color for button
        window->drawButton(250, 300, 100, 40, "Click Me!");
        
        window->drawText(100, 100, "Button clicked not", textColor);
        
        // Reset color to white before drawing texture
        glColor3f(1.0f, 1.0f, 1.0f);  // White color

        if (window->vdl_isKeyPressed(VDL_KEY_ESCAPE)) {
            window->destroy();
        }

        window->pollEvents();
        window->swapBuffers();
    }

    window->destroy();
    return 0;
}
