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
__declspec(dllexport) extern void agGLCreateWindow(int width, int height, const char* title) {
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
__declspec(dllexport) extern void agGLRender() {
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
__declspec(dllexport) extern void agGLCleanup() {
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hglrc);
    ReleaseDC(hwnd, hdc);
}

#endif // _WIN32