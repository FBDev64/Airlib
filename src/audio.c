#include "../include/audio.h"
#include <windows.h>
#include <mmsystem.h>

// Initialize the sound system (if required, currently no-op)
void InitSoundSystem() {
    // Could initialize things like DirectSound or more complex systems here
    // For now, no setup is needed.
}

// Play a .wav file
void PlayWavFile(const char* filepath) {
    // PlaySound is a simple function that plays a WAV file
    // SND_ASYNC: Play sound asynchronously (non-blocking)
    // SND_FILENAME: The sound is specified by a file name
    if (!PlaySound(filepath, NULL, SND_ASYNC | SND_FILENAME)) {
        MessageBox(NULL, "Failed to play sound!", "Error", MB_ICONERROR | MB_OK);
    }
}

// Stop currently playing sound
void StopSound() {
    PlaySound(NULL, NULL, 0);  // Passing NULL stops any currently playing sound
}
