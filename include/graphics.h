/* Copyright (c) 2024 Adam Ellouze. All Rights Reserved. */

#ifndef GRAPHICS_LIBRARY_H
#define GRAPHICS_LIBRARY_H

#ifdef _WIN32
#include <windows.h>
#else
#include <X11/Xlib.h>
#endif

typedef struct {
    int width;
    int height;
    const char* title;
    void* window; // Pointer to the window
} Window;

Window* create_window(int width, int height, const char* title);
void destroy_window(Window* window);
void poll_events();

#endif