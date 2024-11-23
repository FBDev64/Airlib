#ifndef VIDEO_H
#define VIDEO_H

/* X11 */
#ifdef __linux__

#include <X11/Xlib.h>

#define KEY_ESCAPE   9
#define KEY_SPACEBAR 65
#define KEY_UP      111
#define KEY_RIGHT   114
#define KEY_DOWN    116
#define KEY_LEFT    113

static Display *d;
static XEvent e;
static int *s;
static GC gc;

void axCreateWindow(int width, int height);
void axDrawRect(unsigned long color, int x, int y, int width, int height);
void axClearWindow();
int axGetNextEvent(XEvent *event);
void axCloseWindow();
int axGetNextEvent(XEvent *event);

#endif

/* FreeGLUT (cross-platform) */

typedef struct CustomWindow {
   void (*create)(int width, int height, const char* title);
   void (*pollEvents)(void);
   void (*swapBuffers)(void);
   int (*shouldClose)(void);
   void (*drawText)(float x, float y, const char* text);
   void (*drawButton)(float x, float y, float width, float height, const char* label);
   void (*destroy)(void);
   int (*isButtonClicked)(float x, float y, float width, float height);
} CustomWindow;

CustomWindow* createWindowInstance(void);

#endif

