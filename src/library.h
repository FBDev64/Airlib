/* Copyright (c) 2024 Adam Ellouze. All Rights Reserved. */

#ifndef AIRLIB_LIBRARY_H
#define AIRLIB_LIBRARY_H

// ------------------------------------------------
// Some Basic Info
// ------------------------------------------------

#define KCLS  "\e[2J"
#define KNRM  "\e[0m"
#define KRED  "\e[31m"
#define KGRN  "\e[32m"
#define KYEL  "\e[33m"
#define KBLU  "\e[34m"
#define KMAG  "\e[35m"
#define KCYN  "\e[36m"
#define KWHT  "\e[37m"

// -------------------------------------------------
// Error Handling
// -------------------------------------------------

char *Airlib_Logger(char *text, unsigned int error, unsigned int warn, unsigned int info);

// -------------------------------------------------
// Get Platform
// -------------------------------------------------

const char *Airlib_GetPlatform(void);

// -------------------------------------------------
// Color and Strings
// -------------------------------------------------

void DisplayText(char *text, char *color, unsigned int bold, unsigned int italic, unsigned int underline);

// ------------------------------------------------
// Window
// ------------------------------------------------


void SegFault();
void clrscr();

// ------------------------------------------------
// Clock and Time
// ------------------------------------------------

void SysSleep(int ms);
float GetGameTime();

// ------------------------------------------------
// Drawing
// ------------------------------------------------

void DrawBox(int x, int y, int width, int height, char *color);

#endif //AIRLIB_LIBRARY_H
