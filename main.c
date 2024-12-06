#include "include/video.h"
#include <GL/gl.h>

int main() {
    Win* window = createWindowInstance();
    window->create(600, 700, "Test");

    // Load texture once before the main loop
    GLuint textureId = window->loadTexture("C:/Users/Adam/Pictures/ness.png");

    // Example text color (white)
    unsigned char textColor[3] = {255, 255, 255};

    while (!window->shouldClose()) {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw texture
        window->drawTexture(textureId, 100, 100, 200, 200);

        // Draw some text
        window->drawText(250, 50, "Hello VDL!", textColor);

        // Draw a button
        window->drawButton(250, 300, 100, 40, "Click Me!");

        // Check if button is clicked
        if (window->isButtonClicked(250, 300, 100, 40)) {
            window->drawText(250, 50, "Hello VL!", textColor);
        }

        // Handle events and swap buffers
        window->pollEvents();
        window->swapBuffers();
    }

    // Cleanup
    window->destroy();
    return 0;
}
