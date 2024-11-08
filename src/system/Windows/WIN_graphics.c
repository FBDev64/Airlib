#include "../../../include/graphics.h"
#include <windows.h>
#include <string.h>

static HWND hwnd;
static HDC hdc;
static WNDCLASSEX wc;
static const char* currentText = NULL;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
        return 0;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            if (currentText) {
                TextOut(hdc, 10, 10, currentText, strlen(currentText));
            }
            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

__declspec(dllexport) void createWin(int width, int height, const char *name) {
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "AirlibWindow";
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    RegisterClassEx(&wc);

    hwnd = CreateWindowEx(
        0,
        "AirlibWindow",
        name,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);
}

__declspec(dllexport) void displayWinText(const char *msg) {
    currentText = msg;
    InvalidateRect(hwnd, NULL, TRUE);
    UpdateWindow(hwnd);
}

__declspec(dllexport) void setWindowIcon(const char *iconPath) {
    // Load the JPEG image
    HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, iconPath,
                                        IMAGE_BITMAP,
                                        32, 32,
                                        LR_LOADFROMFILE);
    if (hBitmap) {
        // Convert bitmap to icon
        ICONINFO ii = {0};
        ii.fIcon = TRUE;
        ii.hbmColor = hBitmap;
        ii.hbmMask = CreateBitmap(32, 32, 1, 1, NULL);

        HICON hIcon = CreateIconIndirect(&ii);

        // Set both large and small icons
        SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
        SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);

        // Clean up
        DeleteObject(ii.hbmMask);
        DeleteObject(hBitmap);
    }
}
