#ifdef __linux__

#include "../../../include/video.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glx.h>

static Display *display;
static Window xWindow;
static GLXContext glContext;
static int shouldCloseFlag = 0;

static void create(int width, int height, const char* title) {
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Cannot open X display\n");
        exit(1);
    }

    static int visual_attribs[] = {
        GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None
    };
    int screen = DefaultScreen(display);
    XVisualInfo *vi = glXChooseVisual(display, screen, visual_attribs);
    if (vi == NULL) {
        fprintf(stderr, "No appropriate visual found\n");
        exit(1);
    }

    Colormap cmap = XCreateColormap(display, RootWindow(display, screen), vi->visual, AllocNone);
    XSetWindowAttributes swa;
    swa.colormap = cmap;
    swa.event_mask = ExposureMask | KeyPressMask | ButtonPressMask;

    xWindow = XCreateWindow(display, RootWindow(display, screen), 0, 0, width, height, 0, vi->depth, InputOutput, vi->visual,
                           CWColormap | CWEventMask, &swa);
    XMapWindow(display, xWindow);
    XStoreName(display, xWindow, title);

    glContext = glXCreateContext(display, vi, NULL, GL_TRUE);
    glXMakeCurrent(display, xWindow, glContext);

    glEnable(GL_DEPTH_TEST);
}

static void pollEvents(void) {
    XEvent xev;
    while (XPending(display) > 0) {
        XNextEvent(display, &xev);
        if (xev.type == ClientMessage || xev.type == KeyPress) {
            shouldCloseFlag = 1;
        } else if (xev.type == ButtonPress) {
            // Add button click logic here
        }
    }
}

static void swapBuffers(void) {
    glXSwapBuffers(display, xWindow);
}

static int shouldClose(void) {
    return shouldCloseFlag;
}

static void drawText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    while (*text) {
        // glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        text++;
    }
}

static void drawButton(float x, float y, float width, float height, const char* label) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
    drawText(x + width / 10.0f, y + height / 2.0f, label);
}

static int isButtonClicked(float x, float y, float width, float height) {
    XEvent xev;
    if (XPending(display) > 0) {
        XNextEvent(display, &xev);
        if (xev.type == ButtonPress) {
            int mouseX = xev.xbutton.x;
            int mouseY = xev.xbutton.y;
            if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height) {
                return 1;
            }
        }
    }
    return 0;
}

static void destroy(void) {
    glXMakeCurrent(display, None, NULL);
    glXDestroyContext(display, glContext);
    XDestroyWindow(display, xWindow);
    XCloseDisplay(display);
}

Win* createWindowInstance(void) {
    static Win win = {
        .create = create,
        .pollEvents = pollEvents,
        .swapBuffers = swapBuffers,
        .shouldClose = shouldClose,
        .drawText = drawText,
        .drawButton = drawButton,
        .destroy = destroy,
        .isButtonClicked = isButtonClicked
    };
    return &win;
}

#endif

/*
Copyright (C) 2024 Ellouze Adam <elzadam11@tutamail.com>

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software. If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
