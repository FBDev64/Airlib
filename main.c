#include <GL/gl.h>
#include <GL/glut.h>
#include "include/video.h"

static const char* display_text = "yOU ARE A KING !";

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    Window* window = createWindowInstance();
    window->create(800, 600, "Best game ever");

    glClearColor(0.0f, 1.0f, 1.0f, 0.0f);

    while (!window->shouldClose()) {
        window->pollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw button background
        glColor3f(0.0,0.0,0.0);
        window->drawButton(-0.5f, -0.5f, 1.0f, 0.3f, "BUD");

        // Text
        glColor3f(0.0f, 0.0f, 1.0f);
        window->drawText(-0.2f, -0.4f, "Click Me");

        // Draw header text in white
        glColor3f(0.0f, 0.0f, 1.0f);
        window->drawText(-0.8f, 0.8f, display_text);

        if (window->isButtonClicked(-0.5f, -0.5f, 1.0f, 0.3f)) {
            display_text = "Hello GLUT!";
        }

        window->swapBuffers();
    }

    window->destroy();
    return 0;
}
