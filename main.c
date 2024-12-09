#include "include/video.h"
#include <GL/gl.h>

int main() {
    Win* window = createWindowInstance();
    window->create(600, 700, "WGL Test");

    GLuint textureId = window->loadTexture("C:/Users/Adam/Pictures/ness.png");
    unsigned char textColor[3] = {34, 84, 2};

    while (!window->shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set color for button
        glColor3f(1.0f, 0.0f, 0.0f);  // Red color for button
        window->drawButton(250, 300, 100, 40, "Click Me!");

        // Reset color to white before drawing texture
        glColor3f(1.0f, 1.0f, 1.0f);  // White color

        window->drawTexture(textureId, 100, 200, 200, 100);

        if (window->isButtonClicked(250, 300, 100, 40)) {
            window->drawText(100, 100, "Button clicked!", textColor);
        }

        window->pollEvents();
        window->swapBuffers();
    }

    window->destroy();
    return 0;
}
