#include <GL/glut.h>
#include <stdio.h>
#include "include/video.h"

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize FreeGLUT

    CustomWindow *win = createWindowInstance();
    win->create(800, 600, "Linux GLX Window");

    while (!win->shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        win->drawText(-0.5f, 0.0f, "Hello, Linux with GLX!");
        win->drawButton(-0.5f, -0.5f, 0.3f, 0.2f, "Click Me");

        if (win->isButtonClicked(-0.5f, -0.5f, 0.3f, 0.2f)) {
            printf("Button was clicked!\n");
        }

        win->swapBuffers();
        win->pollEvents();
    }

    win->destroy();
    return 0;
}

