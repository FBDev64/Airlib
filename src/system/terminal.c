#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stddef.h>

#ifdef _WIN32
  #include <conio.h>
  #include <windows.h> // For Sleep function
#else
  #include <fcntl.h>
  #include <termios.h>
  #include <unistd.h>
#endif /* ifdef _WIN32 */

#include "../../include/terminal.h"
#include <string.h>

// ------------------------------------
// Error handling
// ------------------------------------

char *errorLog(char *text, unsigned int error, unsigned int warn, unsigned int info) {

    // Color
    if (error) printf(KRED);
    if (warn) printf(KYEL);
    if (info) printf(KBLU);

    // Text
    if (error) printf("error: ");
    if (warn) printf("warn: ");
    if (info) printf("info: ");
    printf("%s", text);

    printf(KNRM);

    return text;
}

// ------------------------------------
// Color and Strings
// ------------------------------------

void richText(char *text, char *color, unsigned int bold, unsigned int italic, unsigned int underline) {
    printf("%s", color);
    if (bold) printf("\033[1m");
    if (italic) printf("\033[3m");
    if (underline) printf("\033[4m");
    printf("%s", text);
    printf(KNRM);  // Reset to normal
    printf("\n");
}

void placeholder(char *text, char *output, size_t output_size) {
    int ch, index = 0;

    // Display the placeholder text in light gray using KHOL
    printf(KHOL, text);
    fflush(stdout);

    // Move cursor back to the beginning of the line to type over the placeholder
    printf("\033[1000D");  // Move cursor far left

    // Read characters one by one
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // If the user starts typing, clear the placeholder
        if (index == 0) {
            // Clear the placeholder by overwriting with spaces
            printf("\033[1000D\033[0K"); // Move to start of line and clear it
            fflush(stdout);
        }

        // Add character to the output buffer
        if (index < output_size - 1) {
            output[index++] = ch;
        }
    }
    output[index] = '\0';  // Null-terminate the input string
    printf(KNRM);
}

// ------------------------------------
// Window
// ------------------------------------

void segFault() {
    int *p = NULL;
    *p = 1;
}

void clrscr() {
    printf(KCLS);  // This clears the screen
}

// ------------------------------------
// Clock and Time
// ------------------------------------

void sysSleep(int ms) {
    clock_t goal = ms * CLOCKS_PER_SEC / 1000;
    clock_t start = clock();
    while (clock() < goal) {
    }
}

float getGameTime() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("The time is %d:%d:%d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    return "The time is %d:%d:%d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec;
}

float stopWatch() {
    clock_t start = clock();
    clock_t end = clock();
    float seconds = (float) (end - start) / CLOCKS_PER_SEC;
    return seconds;
}

// ------------------------------------
// Drawing
// ------------------------------------

void drawBox(int x, int y, int width, int height, char *color) {
    printf("%s", color);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf(KNRM);  // Reset to normal
}

// -----------------------------------
// I/O
// -----------------------------------

#ifdef _WIN32


// Function to check for non-blocking input
char nonBlockingInput() {
    if (_kbhit()) { // Check if a key is pressed
        return _getch(); // Return the character without waiting for Enter
    }
    return 0; // Return 0 if no key was pressed
}

#else

void enableNonBlockingInput() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t); // Get terminal attributes
    t.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &t); // Set terminal attributes

    int flags = fcntl(STDIN_FILENO, F_GETFL, 0); // Get file status flags
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK); // Set stdin to non-blocking
}

void disableNonBlockingInput() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON | ECHO; // Re-enable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags & ~O_NONBLOCK); // Set stdin back to blocking
}

#endif /* ifdef _WIN32 */

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
