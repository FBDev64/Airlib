#include <GL/gl.h>

#include "include/video.h"
#include <GL/gl.h>

int main() {
  Win* window = createWindowInstance();
  window->create(800, 600, "WGL Window");

  while (!window->shouldClose()) {
    glClear(GL_COLOR_BUFFER_BIT);

    window->drawButton(0.2f, 0.2f, 0.3f, 0.2f, "Click Me");
    window->drawText(0.0f, 0.0f, "Button Clicked");


    window->swapBuffers();
    window->pollEvents();
  }

  window->destroy();
  return 0;
}
