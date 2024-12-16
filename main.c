#include "include/vdl.h"
#include <GL/gl.h>

int main() {
    Win* window = createWindowInstance();
    window->create(500, 300, "VDL Test");

    unsigned char textColor[3] = {34, 84, 2};
    int isPlaying = 0;

    while (!window->shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        window->drawText(10, 10, "ESC to quit", textColor);
        window->drawText(10, 20, "A to play sound", textColor);

        glColor3f(1.0f, 1.0f, 1.0f);

        if (window->keyboard->isKeyPressed(KB_KEY_ESCAPE)) {
            window->destroy();
        }

        if (window->keyboard->isKeyPressed(KB_KEY_A) && !isPlaying) {
            window->playSound("C:/Users/Adam/Music/rickroll.wav");
            isPlaying = 1;
        }

        if (!window->keyboard->isKeyPressed(KB_KEY_A)) {
            isPlaying = 0;
        }

        window->pollEvents();
        window->swapBuffers();
    }

    window->destroy();
    return 0;
}
