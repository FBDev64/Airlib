/* Copyright (c) 2024 Adam Ellouze. All Rights Reserved. */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// ------------------------------------
// ANSI Escape Colors
// ------------------------------------

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m" 
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

// ------------------------------------
// Error handling
// ------------------------------------

/* If you ever have to use this,  */

char *Airlib_Logger(char *text, int error, int warn, int info) {
  
  // Color
  if (error) printf(KRED);
  if (warn) printf(KYEL);
  if (info) printf(KBLU);
  
  // text
  if (error) printf("error: ");
  if (warn) printf("warn: ");
  if (info) printf("info: ");
  printf("%s", text);
  
  printf(KNRM);
}

// ------------------------------------
// Get Platform
// ------------------------------------

const char *Airlib_GetPlatform(void) {
  #if defined(_WIN32)
    return "Windows";
  #elif defined(__APPLE__)
    return "Apple";
  #elif defined(__MACH__)
    return "Apple";
  #elif defined(TARGET_OS_EMBEDDED)
    return "iOS Embedded";
  #elif defined(TARGET_IPHONE_SIMULATOR)
    return "iOS Emulator";
  #elif defined(TARGET_OS_IPHONE)
    return "iOS";
  #elif defined(TARGET_OS_MAC)
    return "MacOS";
  #elif defined(__unix__)
    return "Unix";
  #elif defined(__linux__)
    return "Linux";
  #elif defined(__sun)
    return "Solaris";
  #elif defined(__hpux)
    return "HP UX"; 
  #elif defined(__DragonFly__)
    return "DragonFly BSD";
  #elif defined(__FreeBSD__)
    return "FreeBSD";
  #elif defined(__NetBSD__)
    return "NetBSD";
  #elif defined(__OpenBSD__)
    return "OpenBSD";
  #else 
    #error "[ platform ] : unknown platform !"
  #endif
}

// ------------------------------------
// Color and Strings
// ------------------------------------

void DisplayText(char *text, char *color, int bold, int italic, int underline) {
    printf("%s", color);
    if (bold) printf("\033[1m");
    if (italic) printf("\033[3m");
    if (underline) printf("\033[4m");
    printf("%s", text);
    printf(KNRM);  // Reset to normal
    printf("\n");
}

// ------------------------------------
// Window
// ------------------------------------

void SegFault() {
    int *p = NULL;
    *p = 1;
}

void clrscr() {
    system("@cls||clear");  // This clears the screen
}

// Clock and Time

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

// Drawing

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
