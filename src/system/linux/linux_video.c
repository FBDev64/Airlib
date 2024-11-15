/* NOTE : Linux graphics uses X11 */

#ifdef __linux__

#include "../../../include/video.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h> // API
#include <X11/Xutil.h> // Defs

static Display *d;
static Window w;
static int s;

void createWindow(int width, int height, const char *name) {
    d = XOpenDisplay(NULL);
    if (d == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    s = DefaultScreen(d);
    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                            BlackPixel(d, s), WhitePixel(d, s));
    XStoreName(d, w, name);
    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapWindow(d, w);
}

void displayWindowText(const char *msg) {
    XEvent e;
    while (1) {
        XNextEvent(d, &e);
        if (e.type == Expose) {
            XFillRectangle(d, w, DefaultGC(d, s), 20, 20, 10, 10);
            XDrawString(d, w, DefaultGC(d, s), 10, 50, msg, strlen(msg));
        }
        if (e.type == KeyPress)
            break;
    }
    XCloseDisplay(d);
}

#endif
