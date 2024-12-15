#ifndef VIDEO_H
#define VIDEO_H

#include <GL/gl.h>
#include "io.h"

typedef struct Win {
   void (*create)(int width, int height, const char* title);
   void (*pollEvents)(void);
   void (*swapBuffers)(void);
   int (*shouldClose)(void);
   void (*drawText)(float x, float y, const char* text, unsigned char* color);
   void (*drawButton)(float x, float y, float width, float height, const char* label);
   void (*destroy)(void);
   int (*isButtonClicked)(float x, float y, float width, float height);
   void (*setBackgroundColor)(float red, float green, float blue, float alpha);
   void (*getOpenGLVersion)(void);
   GLuint (*loadTexture)(const char* filename);  // Add loadTexture
   void (*drawTexture)(GLuint textureID, float x, float y, float width, float height);
   void (*checkGLError)(void);
   int (*vdl_isKeyPressed)(VDL_Key key);

} Win;

// Creates and returns a pointer to a Win instance
Win* createWindowInstance(void);

#endif // VIDEO_H