#include "include/video.h"
#include "include/audio.h"

int main() {
    avGLCreateWindow(800, 600, "OpenGL b");
    playSoundFile("C:/Users/Adam/Downloads/Rick Astley Never Gonna Give You Up Official Music Video.wav");
    bool running = true;
    while (running) {
        avGLRender();
    }

}