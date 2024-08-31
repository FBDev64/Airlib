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

void SegFault() {
    int *p = NULL;
    *p = 1;
}

void clrscr() {
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

float StopWatch() {
    clock_t start = clock();
    clock_t end = clock();
    float seconds = (float) (end - start) / CLOCKS_PER_SEC;
    return seconds;
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
