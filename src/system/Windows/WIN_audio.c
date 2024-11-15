#ifdef _WIN32

#include "../../../include/audio.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

__declspec(dllexport) extern void playSoundFile(const char *filename) {
    if (!PlaySound(filename, NULL, SND_FILENAME | SND_ASYNC)) {
        printf("Error playing sound file: %s\n", filename);
    }
}

__declspec(dllexport) extern void stopSound() {
    PlaySound(NULL, NULL, 0);
}

#endif
