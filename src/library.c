/* Copyright (c) 2024 Adam Ellouze. All Rights Reserved. */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "library.h"

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

