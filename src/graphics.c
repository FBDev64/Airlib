/* Copyright (c) 2024 Adam Ellouze. All Rights Reserved. */

#include "../include/graphics.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Window* create_window(int width, int height, const char* title) {
    Window* win = (Window*)malloc(sizeof(Window));
    win->width = width;
    win->height = height;
    win->title = title;

    HINSTANCE hInstance = GetModuleHandle(NULL);
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "WindowClass";
    RegisterClass(&wc);

    win->window = CreateWindowEx(0, "WindowClass", title, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, hInstance, NULL);

    ShowWindow(win->window, SW_SHOW);
    return win;
}

void destroy_window(Window* win) {
    DestroyWindow((HWND)win->window);
    free(win);
}

void poll_events() {
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

#else
Window* create_window(int width, int height, const char* title) {
    Window* win = (Window*)malloc(sizeof(Window));
    win->width = width;
    win->height = height;
    win->title = title;

    win->window = XOpenDisplay(NULL);
    if (!win->window) {
        fprintf(stderr, "Could not open X display\n");
        exit(1);
    }

    Window root = DefaultRootWindow((Display*)win->window);
    win->window = XCreateSimpleWindow((Display*)win->window, root, 10, 10, width, height, 1,
        BlackPixel((Display*)win->window, 0), WhitePixel((Display*)win->window, 0));

    XSetStandardProperties((Display*)win->window, win->window, title, title, None, NULL, 0, NULL);
    XMapRaised((Display*)win->window);
    return win;
}

void destroy_window(Window* win) {
    XDestroyWindow((Display*)win->window, (Window)win->window);
    XCloseDisplay((Display*)win->window);
    free(win);
}

void poll_events() {
    // Gérer les événements X11 ici
}

#endif
