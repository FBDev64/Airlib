#include "include/audio.h"
#include "include/graphics.h"
#include <windows.h>

int main() {
    // Initialize window
    InitGraphics(800, 600, "Cross-Platform Audio Example");

    // Play sound (replace with the path to your .wav file)
    PlaySoundFile("sound.wav");

    // Main loop (for simplicity, waits for input and then exits)
#ifdef _WIN32
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
#elif defined(__linux__)
    getchar();  // Wait for user input before exiting
#endif

    // Stop the sound before closing
    StopSound();

    // Cleanup
    CloseGraphics();

    return 0;
}
