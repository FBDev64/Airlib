#include <stdio.h>
#include <stdlib.h>
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

void DisplayRedColor(char *txt) {
    printf("%s%s%s\n", KRED, txt, KNRM);
}

void DisplayGreenColor(char *txt) {
    printf("%s%s%s\n", KGRN, txt, KNRM);
}

void DisplayYellowColor(char *txt) {
    printf("%s%s%s\n", KYEL, txt, KNRM);
}

void DisplayBlueColor(char *txt) {
    printf("%s%s%s\n", KBLU, txt, KNRM);
}

void DisplayMagentaColor(char *txt) {
    printf("%s%s%s\n", KMAG, txt, KNRM);
}

void DisplayCyanColor(char *txt) {
    printf("%s%s%s\n", KCYN, txt, KNRM);
}

void DisplayWhiteColor(char *txt) {
    printf("%s%s%s\n", KWHT, txt, KNRM);
}

void DisplayTitle(char *txt, char *color) {
    printf("%s# %s%s\n", color, txt, KNRM);
}

void DisplaySubTitle(char *txt, char *color) {
    printf("%s## %s%s\n", color, txt, KNRM);
}

void DisplayBreakLine() {
    printf("\n");
}

// ------------------------------------------------
// Window
// ------------------------------------------------

void InitWindow() { // This one is just for code readability
    system("@cls||clear");
}

void CloseWindowNy() {
    // User want to close window if else
    char ny;
    printf("Do you want to close window? (y/n) ");
    scanf("%s", &ny);
    if (ny == 'y' || ny == 'Y') {
        exit(0);
    }
}

void CloseWindow() {
    exit(0);
}

void SegFault() {
    int *p = NULL;
    *p = 1;
}

void clrscr() {
    system("@cls||clear");
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

void DrawRedLine() {
    printf("%s-----------------%s\n", KRED, KNRM);
}

void DrawGreenLine() {
    printf("%s-----------------%s\n", KGRN, KNRM);
}

void DrawYellowLine() {
    printf("%s-----------------%s\n", KYEL, KNRM);
}

void DrawBlueLine() {
    printf("%s-----------------%s\n", KBLU, KNRM);
}

void DrawMagentaLine() {
    printf("%s-----------------%s\n", KMAG, KNRM);
}

void DrawCyanLine() {
    printf("%s-----------------%s\n", KCYN, KNRM);
}

void DrawWhiteLine() {
    printf("%s-----------------%s\n", KWHT, KNRM);
}

void DrawRedPolygon(int sides) {
    printf("%s", KRED);
    for (int i = 0; i < sides; i++) {
        printf("*---");
    }
    printf("*%s\n", KNRM);
}

void DrawGreenPolygon(int sides) {
    printf("%s", KGRN);
    for (int i = 0; i < sides; i++) {
        printf("*---");
    }
    printf("*%s\n", KNRM);
}

void DrawYellowPolygon(int sides) {
    printf("%s", KYEL);
    for (int i = 0; i < sides; i++) {
        printf("*---");
    }
    printf("*%s\n", KNRM);
}

void DrawBluePolygon(int sides) {
    printf("%s", KBLU);
    for (int i = 0; i < sides; i++) {
        printf("*---");
    }
    printf("*%s\n", KNRM);
}

void DrawMagentaPolygon(int sides) {
    printf("%s", KMAG);
    for (int i = 0; i < sides; i++) {
        printf("*---");
    }
    printf("*%s\n", KNRM);
}

void DrawCyanPolygon(int sides) {
    printf("%s", KCYN);
    for (int i = 0; i < sides; i++) {
        printf("*---");
    }
    printf("*%s\n", KNRM);
}

void DrawWhitePolygon(int sides) {
    printf("%s", KWHT);
    for (int i = 0; i < sides; i++) {
        printf("*---");
    }
    printf("*%s\n", KNRM);
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
