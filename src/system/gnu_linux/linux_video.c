#if defined(__linux__)

#define STBI_NO_SIMD
#define STB_IMAGE_IMPLEMENTATION
#include "../../../include/stb_image.h"
#include "../../../include/stb_easy_font.h"

#include "../../../include/video.h"

#include <X11/Xlib.h>
#include <GL/glx.h>
#include <GL/gl.h>

#include <stdio.h>
#include <stdlib.h>

#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE 0x812F
#endif

// Global variables for window and OpenGL
static Display* display;
static Window window;
static GLXContext glxContext;
static Atom wmDeleteMessage;
static int should_close = 0;

void create(int width, int height, const char* title) {
    display = XOpenDisplay(NULL);
    if (!display) {
        fprintf(stderr, "Failed to open X display\n");
        exit(EXIT_FAILURE);
    }

    int screen = DefaultScreen(display);
    Window root = RootWindow(display, screen);

    int visualAttribs[] = {
        GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None
    };

    XVisualInfo* visual = glXChooseVisual(display, screen, visualAttribs);
    if (!visual) {
        fprintf(stderr, "No suitable visual found\n");
        exit(EXIT_FAILURE);
    }

    Colormap colormap = XCreateColormap(display, root, visual->visual, AllocNone);

    XSetWindowAttributes swa;
    swa.colormap = colormap;
    swa.event_mask = ExposureMask | KeyPressMask | KeyReleaseMask | StructureNotifyMask;

    window = XCreateWindow(
        display, root, 0, 0, width, height, 0, visual->depth, InputOutput,
        visual->visual, CWColormap | CWEventMask, &swa
    );

    XStoreName(display, window, title);

    wmDeleteMessage = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, &wmDeleteMessage, 1);

    XMapWindow(display, window);

    glxContext = glXCreateContext(display, visual, NULL, GL_TRUE);
    glXMakeCurrent(display, window, glxContext);

    // OpenGL initialization
    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

__attribute__((visibility("default"))) void pollEvents(void) {
    while (XPending(display)) {
        XEvent event;
        XNextEvent(display, &event);
        if (event.type == ClientMessage && (Atom)event.xclient.data.l[0] == wmDeleteMessage) {
            should_close = 1;
        }
    }
}

__attribute__((visibility("default"))) int shouldClose(void) {
    return should_close;
}

__attribute__((visibility("default"))) void swapBuffers(void) {
    glXSwapBuffers(display, window);
}

__attribute__((visibility("default"))) GLuint loadTexture(const char* filename) {
    int width, height, channels;
    unsigned char* imageData = stbi_load(filename, &width, &height, &channels, STBI_rgb_alpha);
    if (!imageData) {
        printf("Failed to load texture: %s\n", filename);
        return 0;
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

    stbi_image_free(imageData);

    return textureID;
}

__attribute__((visibility("default"))) void drawTexture(GLuint textureID, float x, float y, float width, float height) {
    glPushAttrib(GL_CURRENT_BIT | GL_TEXTURE_BIT);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBindTexture(GL_TEXTURE_2D, textureID);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(x, y);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(x + width, y);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(x + width, y + height);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(x, y + height);
    glEnd();

    glPopAttrib();
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
}

__attribute__((visibility("default"))) void drawText(float x, float y, const char* text, unsigned char* color) {
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glColor3ub(color[0], color[1], color[2]);

    static char vertex_buffer[99999];
    stb_easy_font_spacing(0.6f);
    float scale = 1.2f;

    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1.0f);

    int num_quads = stb_easy_font_print(0, 0, (char*)text, NULL, vertex_buffer, sizeof(vertex_buffer));
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 16, vertex_buffer);
    glDrawArrays(GL_QUADS, 0, num_quads * 4);
    glDisableClientState(GL_VERTEX_ARRAY);

    glPopAttrib();
    glPopMatrix();
}

__attribute__((visibility("default"))) void destroy(void) {
    glXMakeCurrent(display, None, NULL);
    glXDestroyContext(display, glxContext);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
}

__attribute__((visibility("default"))) void drawButton(float x, float y, float width, float height, const char* label) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    float textX = x + (width - strlen(label) * 8) / 2;
    float textY = y + (height - 12) / 2;
    unsigned char textColor[3] = {0, 0, 0};
    drawText(textX, textY, label, textColor);
}

__attribute__((visibility("default"))) int isButtonClicked(float x, float y, float width, float height) {
    // Button click functionality is not implemented for X11 here.
    return 0;
}

__attribute__((visibility("default"))) Win* createWindowInstance(void) {
    static Win window = {
        .create = create,
        .pollEvents = pollEvents,
        .swapBuffers = swapBuffers,
        .shouldClose = shouldClose,
        .destroy = destroy,
        .drawButton = drawButton,
        .isButtonClicked = isButtonClicked,
        .loadTexture = loadTexture,
        .drawTexture = drawTexture,
        .drawText = drawText
    };
    return &window;
}

#endif
