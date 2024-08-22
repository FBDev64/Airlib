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

typedef void (*ButtonAction)();

void DrawButton(int x, int y, int width, int height, const char* text, ButtonAction action) 

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

void DrawBox(int x, int y, int width, int height, char *color);

typedef void (*ButtonAction)();

void DrawButton(int x, int y, int width, int height, const char* text, char *ButtonAction) {
    // Draw the button as before
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("*");
            } else if (i == height / 2 && j > 1 && j < width - 2) {
                printf("%s", text);
                j += strlen(text) - 1;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Check if the button is clicked (you'd need to implement input handling)
    // Removed the call to IsButtonClicked as it's not defined
    // You should implement this function or use an appropriate input handling mechanism
    // For now, we'll just call the action if it's provided
    if (action != NULL) {
        action();
    }
}


// ------------------------------------------------
// Math
// ------------------------------------------------

float DEG2RAD(float deg);
float RAD2DEG(float rad);

#endif //AIRLIB_LIBRARY_H
