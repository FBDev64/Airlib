#ifndef AUDIO_H
#define AUDIO_H

#ifdef __cplusplus
extern "C" {
#endif

// Function declarations
void playSoundFile(const char *filename);
void stopSound();

#ifdef __cplusplus
}
#endif

#endif // AUDIO_H
