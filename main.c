#include "include/vdl.h"
#include <GL/gl.h>

int main() {
    Win* window = createWindowInstance();
    window->create(500, 300, "VDL Test");

    unsigned char textColor[3] = {34, 84, 2};

    while (!window->shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set color for button
        glColor3f(1.0f, 0.0f, 0.0f);  // Red color for button
        window->drawText(10, 10, "ESC to quit", textColor);
        window->drawText(10, 20, "P to play sound", textColor);
        
        // Reset color to white before drawing texture
        glColor3f(1.0f, 1.0f, 1.0f);  // White color

        if (window->vdl_isKeyPressed(VDL_KEY_ESCAPE)) {
            window->destroy();
        }

        if (window->vdl_isKeyPressed(VDL_KEY_P)) {
            window->playSound("C:/Users/Adam/Music/rickroll.wav");
        }

        window->pollEvents();
        window->swapBuffers();
    }

    window->destroy();
    return 0;
}
