#include "include/graphics.h"
#include "include/audio.h"

// Main entry point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char* windowTitle = "Airlib Example - Basic Window with Sound";
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Initialize the window
    HWND hwnd = InitGraphics(hInstance, nCmdShow, windowTitle, screenWidth, screenHeight);
    if (!hwnd) {
        return 1; // Exit if window creation fails
    }

    // Initialize the sound system
    InitSoundSystem();

    // Play a sound file
    PlayWavFile("rickroll.mp3");  // Make sure the sound file path is correct

    // Start the message loop
    StartMessageLoop();

    // Stop the sound when the program exits
    StopSound();

    return 0;
}
