/* Copyright (c) 2024 Adam Ellouze. All Rights Reserved. */

#ifndef AIRLIB_LIBRARY_H
#define AIRLIB_LIBRARY_H

// ------------------------------------------------
// Some Basic Info
// ------------------------------------------------

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

// -------------------------------------------------
// Get Platform
// -------------------------------------------------

const char *Airlib_GetPlatform(void);

// -------------------------------------------------
// Color and Strings
// -------------------------------------------------

void DisplayText(char *text, char *color, int bold, int italic, int underline);

// ------------------------------------------------
// Window
// ------------------------------------------------

void InitWindow();
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
