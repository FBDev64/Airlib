#ifndef GRAPHICS_H
#define GRAPHICS_H

void createWindow(int width, int height, const char *name);
void displayWindowText(const char *msg);
void setWindowIcon(const char *iconPath);

void agGLCreateWindow(int width, int height, const char *title);
void agGLRender();
void agGLCleanup();

#endif // GRAPHICS_H
