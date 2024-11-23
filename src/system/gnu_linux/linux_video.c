#include "../../../include/video.h"
#include <stdio.h>
#include <stdlib.h>

/* X11 */

#ifdef __linux__

#include <X11/Xlib.h>

static Display *d;
static Window w;
static XEvent e;
static int s;
static GC gc;

void axCreateWindow(int width, int height) {
    d = XOpenDisplay(NULL);
    if (d == NULL) {
        printf("Cannot open display\n");
        exit(1);
    }

    s = DefaultScreen(d);
    w = XCreateSimpleWindow(d, RootWindow(d,s), 0, 0, width, height, 1,
        BlackPixel(d,s), WhitePixel(d,s));

    // Enable key press and expose events
    XSelectInput(d, w, KeyPressMask | ExposureMask);

    // Create graphics context
    gc = DefaultGC(d, s);

    XMapWindow(d, w);
    XFlush(d);
}

void axDrawRect(unsigned long color, int x, int y, int width, int height) {
    XSetForeground(d, gc, color);
    XFillRectangle(d, w, gc, x, y, width, height);
    XFlush(d);
}

void axClearWindow() {
    XClearWindow(d, w);
    XFlush(d);
}

int axGetNextEvent(XEvent *event) {
    if (XPending(d)) {
        XNextEvent(d, event);
        return 1;
    }
    return 0;
}

void axCloseWindow() {
    XCloseDisplay(d);
}

#endif

/* FreeGLUT (cross-platform) */



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
