// graphics.h
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <X11/Xlib.h>

void createWin(int width, int height, const char *name);
void displayWinText(const char *msg);

#endif // GRAPHICS_H

