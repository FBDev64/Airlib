#include <GL/gl.h>
#include "include/video.h"
#include "include/audio.h"

int main() {
  Win* window = createWindowInstance();
  window->create(800, 600, "WGL Window");

  // Set OpenGL clear color (background color)
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Black background

  while (!window->shouldClose()) {
    // Clear the screen with the current clear color
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a button (example)
    window->drawButton(0.2f, 0.2f, 0.3f, 0.2f, "Click Me");

    // Check if the button is clicked
    if (window->isButtonClicked(0.2f, 0.2f, 0.3f, 0.2f)) {
      // Set a different background color (e.g., red)
      window->setBackgroundColor(1.0f, 0.0f, 0.0f, 1.0f);  // Red background
    }

    // Draw some text
    window->drawText(0.0f, 0.0f, "Button Clicked");

    // Swap buffers to display the changes
    window->swapBuffers();
    window->pollEvents();
  }

  window->destroy();
  return 0;
}
