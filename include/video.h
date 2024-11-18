#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Airlib_defs.h"

/* X11 */
void createWindow(int height, int width);
void displayWindowText(const char *msg);
void setWindowIcon(const char *iconPath);

/* OpenGL */
void avGLCreateWindow(int width, int height, const char *title);
void avGLRender();
void avGLCleanup();

#endif // GRAPHICS_H
