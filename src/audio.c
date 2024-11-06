#include "../include/audio.h"
#include <stdio.h>
#include <stdlib.h>
#include <pulse/pulseaudio.h>

static pa_simple *s = NULL;

void PlaySoundFile(const char *filename) {
    // Set up PulseAudio context
    pa_sample_spec ss;
    ss.format = PA_SAMPLE_S16LE;  // 16-bit signed little-endian samples
    ss.rate = 44100;              // 44.1 kHz sample rate
    ss.channels = 2;              // Stereo output

    // Open the PulseAudio stream for playback
    s = pa_simple_new(NULL,               // Use default server
                      "AudioPlayer",       // Application name
                      PA_STREAM_PLAYBACK,  // Playback mode
                      NULL,                // No specific device
                      "Audio",             // Stream description
                      &ss,                 // Sample format
                      NULL,                // No specific channel map
                      NULL,                // No buffering attributes
                      NULL);               // No error handling required

    if (!s) {
        fprintf(stderr, "PulseAudio: Failed to create playback stream\n");
        return;
    }

    // Use system command to play sound file using PulseAudio
    char command[256];
    snprintf(command, sizeof(command), "paplay %s", filename);
    system(command);
}

void StopSound() {
    if (s) {
        // Stop playback by closing the PulseAudio stream
        pa_simple_free(s);
        s = NULL;
    }

    // Terminate any ongoing playback if necessary
    system("killall paplay");
}
