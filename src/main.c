#include <stdio.h>
#include "../include/graphics.h"

int main() {
    Window* window = create_window(800, 600, "Mini Window");

    while (1) {
        poll_events();

        // Ajoute ici la logique de rendu

        // Petite pause pour éviter une utilisation excessive du CPU
#ifdef _WIN32
        Sleep(16);
#else
        usleep(16000);
#endif
    }

    destroy_window(window);
    return 0;
}