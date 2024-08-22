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
// Color and Strings
// -------------------------------------------------

void DisplayText(char *text, char *color, int bold, int italic, int underline);

// ------------------------------------------------
// Window
// ------------------------------------------------

void InitWindow();
void CloseWindowNy();
void CloseWindow();
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

void DrawRedLine();
void DrawGreenLine();
void DrawYellowLine();
void DrawBlueLine();
void DrawMagentaLine();
void DrawCyanLine();
void DrawWhiteLine();
void DrawRedPolygon(int sides);
void DrawGreenPolygon(int sides);
void DrawYellowPolygon(int sides);
void DrawBluePolygon(int sides);
void DrawMagentaPolygon(int sides);
void DrawCyanPolygon(int sides);
void DrawWhitePolygon(int sides);

// ------------------------------------------------
// Math
// ------------------------------------------------

float DEG2RAD(float deg);
float RAD2DEG(float rad);

#endif //AIRLIB_LIBRARY_H
