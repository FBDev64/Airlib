#ifndef AIRLIB_LIBRARY_H
#define AIRLIB_LIBRARY_H

// -------------------------------------------------
// Color and Strings
// -------------------------------------------------

void DisplayRedColor(char *txt);
void DisplayGreenColor(char *txt);
void DisplayYellowColor(char *txt);
void DisplayBlueColor(char *txt);
void DisplayMagentaColor(char *txt);
void DisplayCyanColor(char *txt);
void DisplayWhiteColor(char *txt);
void DisplayNormalColor(char *txt);
void DisplayColor(char *txt, char *color);
void DisplayH1(char *txt, char *color);
void DisplayH2(char *txt, char *color);
void DisplayH3(char *txt, char *color);
void DisplayH4(char *txt, char *color);
void DisplayH5(char *txt, char *color);
void DisplayH6(char *txt, char *color);
void DisplayBreakLineDash();
void DisplayBreakLine();

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

#endif //AIRLIB_LIBRARY_H
