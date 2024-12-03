#ifdef _WIN32

#include "../../../include/video.h"
#include <windows.h>
#include <GL/gl.h>

// Global variables for window and OpenGL
static HWND hwnd;
static HDC hdc;
static HGLRC hglrc;
static int should_close = 0;

// WindowProc function definition goes here:
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CLOSE:
            should_close = 1;
            PostQuitMessage(0);
            return 0;

        case WM_LBUTTONDOWN:
            return 0;

        case WM_SETCURSOR:
            // Prevent the cursor from changing to resizing
            SetCursor(LoadCursor(NULL, IDC_ARROW));  // Default arrow cursor
            return TRUE;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

__declspec(dllexport) void create(int width, int height, const char* title) {
    WNDCLASS wc = {0};
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WindowProc;  // Assign WindowProc to handle messages
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "WGL_Window";

    RegisterClass(&wc);

    hwnd = CreateWindowEx(
        0, wc.lpszClassName, title, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, width, height,
        NULL, NULL, wc.hInstance, NULL
    );

    hdc = GetDC(hwnd);

    // Set up the pixel format descriptor
    PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        32,
        0, 0, 0, 0, 0, 0,
        0, 0,
        0, 0, 0, 0, 0,
        24,
        8,
        0,
        PFD_MAIN_PLANE,
        0, 0, 0, 0
    };

    int pixel_format = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, pixel_format, &pfd);

    hglrc = wglCreateContext(hdc);
    wglMakeCurrent(hdc, hglrc);
}

__declspec(dllexport) void pollEvents(void) {
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

__declspec(dllexport) void swapBuffers(void) {
    SwapBuffers(hdc);
}

__declspec(dllexport) int shouldClose(void) {
    return should_close;
}

__declspec(dllexport) void drawText(float x, float y, const char* text) {
    // Simple placeholder for text rendering, not using GLUT
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        for (int i = 0; i < 8; i++) { // Basic "blocky" character rendering
            glBegin(GL_POINTS);
            glVertex2f(x + (i % 4) * 0.01, y + (i / 4) * 0.02);
            glEnd();
        }
        x += 0.05f; // Advance position (placeholder spacing)
    }
}

__declspec(dllexport) void drawButton(float x, float y, float width, float height, const char* label) {
    // Draw a simple rectangle button
    glColor3f(0.3f, 0.3f, 0.3f); // Button color
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    // Draw button label
    drawText(x + 0.1f * width, y + 0.4f * height, label);
}

__declspec(dllexport) void destroy(void) {
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hglrc);
    ReleaseDC(hwnd, hdc);
    DestroyWindow(hwnd);
}

__declspec(dllexport) int isButtonClicked(float x, float y, float width, float height) {
    POINT pt;
    GetCursorPos(&pt);
    ScreenToClient(hwnd, &pt);

    if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) &&
        pt.x >= x && pt.x <= x + width &&
        pt.y >= y && pt.y <= y + height) {
        return 1;
    }
    return 0;
}

__declspec(dllexport) void setBackgroundColor(float red, float green, float blue, float alpha) {
    glClearColor(red, green, blue, alpha);
}

__declspec(dllexport) Win* createWindowInstance(void) {
    static Win window = {
        .create = create,
        .pollEvents = pollEvents,
        .swapBuffers = swapBuffers,
        .shouldClose = shouldClose,
        .drawText = drawText,
        .drawButton = drawButton,
        .destroy = destroy,
        .isButtonClicked = isButtonClicked,
        .setBackgroundColor = setBackgroundColor
    };
    return &window;
}

#endif
