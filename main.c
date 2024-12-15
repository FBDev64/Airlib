#include "include/vdl.h"
#include <GL/gl.h>

int main() {
    Win* window = createWindowInstance();
    window->create(800, 600, "VDL testing");
    unsigned char textColor[] = { 1, 3, 4 }; // BECAUSE WAS WHITE

    while (!window->shouldClose()) { // the () is very important
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1.0f, 0.0f, 0.0f); // red color
        window->drawButton(250, 300, 100, 40, "Click Me");

        if (window->isButtonClicked(250, 300, 100, 40)) {
            window->drawText(100, 100, "Clicked Nn Rr Ll Tt!", textColor);
        }

        window->pollEvents(); // Needed to update window
        window->swapBuffers();
    }

    window->destroy();
    return 0;
}