#ifndef AIRLIB_LIBRARY_H
#define AIRLIB_LIBRARY_H

// -------------------------------------------------
// Color
// -------------------------------------------------

void DisplayRedColor(char *txt);
void DisplayGreenColor(char *txt);
void DisplayYellowColor(char *txt);
void DisplayBlueColor(char *txt);
void DisplayMagentaColor(char *txt);
void DisplayCyanColor(char *txt);
void DisplayWhiteColor(char *txt);
void DisplayNormalColor(char *txt);

// ------------------------------------------------
// Window
// ------------------------------------------------

void CloseWindow();

// ------------------------------------------------
// Math
// ------------------------------------------------

float sqrt(float x);
float sin(float x);
float cos(float x);
float tan(float x);
float pow(float x, float y);

#endif //AIRLIB_LIBRARY_H
