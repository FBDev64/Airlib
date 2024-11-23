#ifdef _WIN32

#include "../../../include/video.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

static HWND hwnd;
static HDC hdc;
static HGLRC hglrc;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_CLOSE) PostQuitMessage(0);
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

__declspec(dllexport) void create(int width, int height, const char* title) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "OpenGLWindowClass";

    RegisterClass(&wc);
    hwnd = CreateWindowEx(0, "OpenGLWindowClass", title, WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT, width, height,
                          NULL, NULL, wc.hInstance, NULL);
    hdc = GetDC(hwnd);

    PIXELFORMATDESCRIPTOR pfd = { sizeof(PIXELFORMATDESCRIPTOR), 1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, PFD_TYPE_RGBA,
        32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 8, 0,
        PFD_MAIN_PLANE, 0, 0, 0, 0 };

    int pf = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, pf, &pfd);
    hglrc = wglCreateContext(hdc);
    wglMakeCurrent(hdc, hglrc);

    ShowWindow(hwnd, SW_SHOW);
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
    return 0; // Modify to track window close requests
}

__declspec(dllexport) void destroy(void) {
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hglrc);
    ReleaseDC(hwnd, hdc);
    DestroyWindow(hwnd);
}

__declspec(dllexport) void drawText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c); // Requires GLUT for fonts
    }
}

__declspec(dllexport) void drawButton(float x, float y, float width, float height, const char* label) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    drawText(x + width / 2, y + height / 2, label);
}

__declspec(dllexport) int isButtonClicked(float x, float y, float width, float height) {
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    ScreenToClient(hwnd, &cursorPos);

    // Convert window coordinates to OpenGL coordinates
    RECT rect;
    GetClientRect(hwnd, &rect);
    float oglX = (2.0f * cursorPos.x) / rect.right - 1.0f;
    float oglY = 1.0f - (2.0f * cursorPos.y) / rect.bottom;

    // Check if mouse is within button bounds
    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
        if (oglX >= x && oglX <= x + width &&
            oglY >= y && oglY <= y + height) {
            return 1;
            }
    }
    return 0;
}

__declspec(dllexport) Window* createWindowInstance(void) {
    static Window window = {
        .create = create,
        .pollEvents = pollEvents,
        .swapBuffers = swapBuffers,
        .shouldClose = shouldClose,
        .drawText = drawText,
        .drawButton = drawButton,
        .destroy = destroy,
        .isButtonClicked = isButtonClicked
    };
    return &window;
}

#endif
