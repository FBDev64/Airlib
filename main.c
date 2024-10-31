#include "include/audio.h"
#include "include/graphics.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize window
    InitGraphics(800, 600, "Cross-Platform Audio Example");

#ifdef _WIN32
    #include <windows.h>
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
#elif defined(__linux__)
  getchar();  // Wait for user input before exiting
#endif

    // Cleanup
    CloseGraphics();

    return 0;
}
