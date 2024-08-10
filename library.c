#include "library.h"
#include <stdio.h>
#include <process.h>

// ------------------------------------------------
// Some Basic Info
// ------------------------------------------------

#ifndef PI
#define PI 3.14159265358979323846f
#endif
#ifndef DEG2RAD
#define DEG2RAD (PI/180.0f)
#endif
#ifndef RAD2DEG
#define RAD2DEG (180.0f/PI)
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
// Color
// -------------------------------------------------

void DisplayRedColor(char *txt) {
    printf("%sred\n", KRED);
}

void DisplayGreenColor(char *txt) {
    printf("%sgreen\n", KGRN);
}

void DisplayYellowColor(char *txt) {
    printf("%syellow\n", KYEL);
}

void DisplayBlueColor(char *txt) {
    printf("%sblue\n", KBLU);
}

void DisplayMagentaColor(char *txt) {
    printf("%smagenta\n", KMAG);
}

void DisplayCyanColor(char *txt) {
    printf("%scyan\n", KCYN);
}

void DisplayWhiteColor(char *txt) {
    printf("%swhite\n", KWHT);
}

void DisplayNormalColor(char *txt) {
    printf("%snormal\n", KNRM);
}

// ------------------------------------------------
// Window
// ------------------------------------------------

void CloseWindow() {
    exit(0);
}

// ------------------------------------------------
// Math
// ------------------------------------------------

float sqrt(float x) {
    printf("sqrt(%f) = %f\n", x, sqrt(x));
}

float sin(float x) {
    printf("sin(%f) = %f\n", x, sin(x));
}

float cos(float x) {
    printf("cos(%f) = %f\n", x, cos(x));
}

float tan(float x) {
    printf("tan(%f) = %f\n", x, tan(x));
}

float pow(float x, float y) {
    printf("pow(%f, %f) = %f\n", x, y, pow(x, y));
}