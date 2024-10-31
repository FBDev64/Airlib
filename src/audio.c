#include "../include/audio.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#include <mmsystem.h>  // For PlaySound

void PlaySoundFile(const char *filename) {
    PlaySoundA(filename, NULL, SND_FILENAME | SND_ASYNC);
}

void StopSound() {
    PlaySound(NULL, 0, 0);
}

#elif defined(__linux__)
#include <stdlib.h>  // For system()

void PlaySoundFile(const char *filename) {
    // Use `aplay` to play the wav file on Linux (aplay is a simple ALSA player)
    char command[256];
    snprintf(command, sizeof(command), "aplay %s &", filename);
    system(command);
}

void StopSound() {
    // Stop any playing sound by killing aplay (if running)
    system("killall aplay");
}

#endif
