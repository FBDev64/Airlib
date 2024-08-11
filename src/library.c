#include "library.h"
#include <stdio.h>
#include <stdlib.h>

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

void DisplayColor(char *txt, char *color) {
    printf("%s%s%s\n", color, txt, KNRM);
}

// ------------------------------------------------
// Window
// ------------------------------------------------

void CloseWindow() {
    exit(0);
}