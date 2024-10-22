#include "../include/graphics.h"

// Forward declaration for the window procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Initialize and create the window
HWND InitGraphics(HINSTANCE hInstance, int nCmdShow, const char* title, int width, int height) {
    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WindowProc;   // Set window procedure
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = "GraphicsWindowClass";

    // Register the window class
    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window class registration failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return NULL;
    }

    // Create the window
    HWND hwnd = CreateWindowEx(0,
                               wc.lpszClassName,
                               title,
                               WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT,
                               width, height,
                               NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window creation failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return NULL;
    }

    // Show the window
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    return hwnd;
}

// Start the message loop
void StartMessageLoop() {
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

// Window procedure to handle events
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Draw text on the window
            DrawTextOnWindow(hdc);

            EndPaint(hwnd, &ps);
        }
        break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

// Function to draw text on the window
void DrawTextOnWindow(HDC hdc) {
    const char* text = "Congrats! You created your first window!";
    RECT rect = {190, 200, 600, 250};

    SetTextColor(hdc, RGB(169, 169, 169));   // Light Gray color
    SetBkMode(hdc, TRANSPARENT);             // Transparent background

    // Draw the text in the specified rectangle
    DrawText(hdc, text, -1, &rect, DT_SINGLELINE | DT_NOCLIP);
}
