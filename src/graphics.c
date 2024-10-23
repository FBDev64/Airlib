#include "../include/graphics.h"

#ifdef _WIN32
#include <windows.h>

static HWND hwnd;

void InitGraphics(int width, int height, const char *title) {
    // Windows-specific window creation
    WNDCLASS wc = {0};
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "MyWindowClass";
    RegisterClass(&wc);

    hwnd = CreateWindow("MyWindowClass", title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                        width, height, NULL, NULL, GetModuleHandle(NULL), NULL);
    ShowWindow(hwnd, SW_SHOW);
}

void CloseGraphics() {
    // Windows-specific cleanup
    DestroyWindow(hwnd);
}

#elif defined(__linux__)
#include <X11/Xlib.h>

static Display *display;
static Window window;

void InitGraphics(int width, int height, const char *title) {
    // Linux X11-specific window creation
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        return;
    }

    int screen = DefaultScreen(display);
    window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, width, height, 1,
                                 BlackPixel(display, screen), WhitePixel(display, screen));

    XStoreName(display, window, title);
    XMapWindow(display, window);
}

void CloseGraphics() {
    // Linux X11-specific cleanup
    XDestroyWindow(display, window);
    XCloseDisplay(display);
}

#endif
