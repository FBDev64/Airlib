#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <windows.h>

// Function to initialize and create the window
HWND InitGraphics(HINSTANCE hInstance, int nCmdShow, const char* title, int width, int height);

// Function to start the message loop
void StartMessageLoop();

// Function to handle window drawing (can be overridden)
void DrawTextOnWindow(HDC hdc);

#endif // GRAPHICS_H
