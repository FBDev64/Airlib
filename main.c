#include "include/graphics.h"
#include <windows.h>
#include "include/audio.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    // Create a window 800x600 pixels
    createWin(800, 600, "Airlib Demo");

    // Use absolute path and make sure the icon file exists
    setWindowIcon("C:/Users/Adam/Downloads/ness.ico");
    playSoundFile("C:/Users/Adam/Downloads/Rick Astley Never Gonna Give You Up Official Music Video.wav");

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
