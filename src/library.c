/* Copyright (c) 2024 Adam Ellouze. All Rights Reserved. */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// ------------------------------------
// ANSI Escape Colors
// ------------------------------------

#define KCLS  "\e[2J" 
#define KNRM  "\e[0m"
#define KRED  "\e[31m"
#define KGRN  "\e[32m"
#define KYEL  "\e[33m" 
#define KBLU  "\e[34m"
#define KMAG  "\e[35m"
#define KCYN  "\e[36m"
#define KWHT  "\e[37m"

// ------------------------------------
// Error handling
// ------------------------------------

/* If you ever have to use this,  */

char *Airlib_Logger(char *text, unsigned int error, unsigned int warn, unsigned int info) {
  
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

void DisplayText(char *text, char *color, unsigned int bold, unsigned int italic, unsigned int underline) {
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
    printf(KCLS);  // This clears the screen
}

// ------------------------------------
// Clock and Time
// ------------------------------------

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
