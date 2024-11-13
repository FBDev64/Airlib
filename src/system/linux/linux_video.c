/* NOTE : Linux graphics uses X11 */

#ifdef __linux__

#include "../../../include/graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h> // API
#include <X11/Xutil.h> // Defs
#include <X11/Xlib.h>  // XPM format

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

void setWindowIcon(const char *iconPath) {
    // Open the XPM file and read it into an image structure
    XpmAttributes attr;
    XpmImage image;
    int status = XpmReadFileToImage(d, iconPath, &image, &attr);
    if (status != XpmSuccess) {
        fprintf(stderr, "Failed to load XPM icon: %s\n", iconPath);
        return;
    }

    // Create the Pixmap for the window icon
    Pixmap iconPixmap;
    iconPixmap = XCreatePixmapFromBitmapData(d, w, (const char *)image.data, image.width, image.height, 0, 0, 1);

    // Set the icon on the window
    XWMHints *hints = XAllocWMHints();
    if (hints) {
        hints->flags = IconPixmapHint;  // Set the IconPixmapHint flag
        hints->icon_pixmap = iconPixmap;
        XSetWMHints(d, w, hints);  // Apply the hints to the window
        XFree(hints);  // Free the allocated memory for hints
    }

    // Free the image resources
    XpmFreeImage(&image);
}

#endif
