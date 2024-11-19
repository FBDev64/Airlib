/* NOTE : Linux audio uses PulseAudio */

#ifdef __linux__

#include "../../../include/audio.h"
#include <stdio.h>
#include <stdlib.h>
#include <pulse/pulseaudio.h>
#include <pulse/simple.h>

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

#endif

/*
Copyright (C) 2024 Ellouze Adam <elzadam11@tutamail.com>
  
This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:
  
1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required. 
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
