#include "../../../include/audio.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void PlaySoundFile(const char *filename) {
    if (!PlaySound(filename, NULL, SND_FILENAME | SND_ASYNC)) {
        printf("Error playing sound file: %s\n", filename);
    }
}

void StopSound() {
    PlaySound(NULL, NULL, 0);
}
