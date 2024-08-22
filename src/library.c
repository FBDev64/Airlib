#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// ------------------------------------------------
// Some Basic Info
// ------------------------------------------------

#ifndef PI
#define PI 3.14159265358979323846f
#endif

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

// -------------------------------------------------
// Input Handling
// -------------------------------------------------

int cursorX = 0;
int cursorY = 0;

void MoveCursor(int x, int y) {
    cursorX = x;
    cursorY = y;
    printf("\033[%d;%dH", y, x);
}

// -------------------------------------------------
// Color and Strings
// -------------------------------------------------

void DisplayText(char *text, char *color, int bold, int italic, int underline) {
    printf("%s", color);
    if (bold) printf("\033[1m");
    if (italic) printf("\033[3m");
    if (underline) printf("\033[4m");
    printf("%s", text);
    printf(KNRM);  // Reset to normal
    printf("\n");
}

// ------------------------------------------------
// Window
// ------------------------------------------------

void InitWindow(void) { // This one is just for code readability
    system("@cls||clear");
}

void CloseWindowNy(void) {
    // User want to close window if else
    char ny;
    printf("Do you want to close window? (y/n) ");
    scanf("%s", &ny);
    if (ny == 'y' || ny == 'Y') {
        exit(0);
    }
}

void CloseWindow(void) {
    exit(0);
}

void SegFault() {
    int *p = NULL;
    *p = 1;
}

void clscr() {
    system("@cls||clear");  // This clears the screen
}

// ------------------------------------------------
// Clock and Time
// ------------------------------------------------

void SysSleep(int ms) {
    clock_t goal = ms * CLOCKS_PER_SEC / 1000;
    clock_t start = clock();
    while (clock() < goal) {
    }
}

float GetGameTime() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("The time is %d:%d:%d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

// ------------------------------------------------
// Drawing
// ------------------------------------------------

void DrawBox(int x, int y, int width, int height, char *color) {
    printf("%s", color);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf(KNRM);  // Reset to normal
}

typedef void (*ButtonAction)();

void DrawButton(int x, int y, int width, int height, const char* text, ButtonAction action) {
    // Draw the button as before
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("*");
            } else if (i == height / 2 && j > 1 && j < width - 2) {
                printf("%s", text);
                j += strlen(text) - 1;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Check if the button is clicked (you'd need to implement input handling)
    // Removed the call to IsButtonClicked as it's not defined
    // You should implement this function or use an appropriate input handling mechanism
    // For now, we'll just call the action if it's provided
    if (action != NULL) {
        action();
    }
}

// ------------------------------------------------
// Math
// ------------------------------------------------

float DEG2RAD(float deg) {
    return deg * PI / 180.0f;
}

float RAD2DEG(float rad) {
    return rad * 180.0f / PI;
}
