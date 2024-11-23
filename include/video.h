#ifndef VIDEO_H
#define VIDEO_H

/* X11 */
#ifdef __linux__

#define KEY_ESCAPE   9
#define KEY_SPACEBAR 65
#define KEY_UP      111
#define KEY_RIGHT   114
#define KEY_DOWN    116
#define KEY_LEFT    113

static Display *d;
static Window w;
static XEvent e;
static int s;
static GC gc;

void axCreateWindow(int width, int height);
void axDrawRect(unsigned long color, int x, int y, int width, int height);
void axClearWindow();
int axGetNextEvent(XEvent *event);
void axCloseWindow();
int axGetNextEvent(XEvent *event)

#endif

/* FreeGLUT (cross-platform) */

typedef struct Window {
   void (*create)(int width, int height, const char* title);
   void (*pollEvents)(void);
   void (*swapBuffers)(void);
   int (*shouldClose)(void);
   void (*drawText)(float x, float y, const char* text);
   void (*drawButton)(float x, float y, float width, float height, const char* label);
   void (*destroy)(void);
   int (*isButtonClicked)(float x, float y, float width, float height);
} Window;

Window* createWindowInstance(void);

#endif

/*
Copyright (C) 2024 Ellouze Adam <elzadam11@tutamail.com>

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:
  
1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required. 
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
