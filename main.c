#include "include/graphics.h"
#include "include/audio.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    // Create a window 800x600 pixels
    createWin(800, 600, "Airlib Demo");

    // Use absolute path and make sure the icon file exists
    setWindowIcon("C:/Path/To/Your/Icon.ico");

    // Display some text in the window
    displayWinText("Welcome to Airlib!");

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
