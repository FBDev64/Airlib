#include "include/video.h"
#include <GL/gl.h>

int main() {
    Win* window = createWindowInstance();
    window->create(600, 700, "VDL/GL Test");

    unsigned char textColor[3] = {34, 84, 2};

    while (!window->shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glColor3f(1.0f, 0.0f, 0.0f);  // Red color for button
        window->drawButton(250, 300, 100, 40, "Click Me!");
        
        window->drawText(100, 100, "Button clicked not", textColor);
        
        glColor3f(1.0f, 1.0f, 1.0f);

        if (window->isButtonClicked(250, 300, 100, 40)) {
            window->drawText(100, 100, "Button clicked!", textColor);
        }

        window->pollEvents();
        window->swapBuffers();
    }

    window->destroy();
    return 0;
}
