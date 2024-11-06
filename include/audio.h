#ifndef AUDIO_H
#define AUDIO_H

#ifdef __cplusplus
extern "C" {
#endif

// Function declarations
void PlaySoundFile(const char *filename);
void StopSound();

#ifdef __cplusplus
}
#endif

#endif // AUDIO_H
