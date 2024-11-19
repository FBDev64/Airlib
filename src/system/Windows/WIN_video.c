#include <stdio.h>
#ifdef _WIN32

#include <windows.h>
#include <GL/gl.h>
#include "../../../include/video.h"

// Global variables
HDC hdc;
HGLRC hglrc;
HWND hwnd;

// Window procedure callback
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Set up and create an OpenGL window
__declspec(dllexport) extern void avGLCreateWindow(int width, int height, const char* title) {
    WNDCLASS wc = {};
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "OpenGLWindowClass";

    RegisterClass(&wc);

    hwnd = CreateWindowEx(
        0,
        wc.lpszClassName,
        title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        NULL, NULL, wc.hInstance, NULL
    );

    hdc = GetDC(hwnd);

    // Set pixel format for OpenGL
    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int pixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, pixelFormat, &pfd);

    // Create and set the OpenGL rendering context
    hglrc = wglCreateContext(hdc);
    wglMakeCurrent(hdc, hglrc);

    ShowWindow(hwnd, SW_SHOW);
}

// Render function
__declspec(dllexport) extern void avGLRender() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Set background color to black
    glClear(GL_COLOR_BUFFER_BIT);

    // Simple triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.5f, -0.5f);  // Red vertex
    glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.5f, -0.5f);   // Green vertex
    glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.0f, 0.5f);    // Blue vertex
    glEnd();

    SwapBuffers(hdc);
}

// Cleanup function
__declspec(dllexport) extern void avGLCleanup() {
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hglrc);
    ReleaseDC(hwnd, hdc);
}

#endif // _WIN32

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
