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
void DisplayColor(char *txt, char *color);

// ------------------------------------------------
// Window
// ------------------------------------------------

void CloseWindow();
void SegFault();
void clrscr();

// ------------------------------------------------
// Clock and Time
// ------------------------------------------------

void Sleep(int ms);
float GetGameTime();

#endif //AIRLIB_LIBRARY_H
