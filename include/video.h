#ifndef VIDEO_H
#define VIDEO_H

#include <GL/gl.h>

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
   void (*drawTexture)(GLuint textureID, float x, float y, float width, float height);  // Add drawTexture
} Win;

// Creates and returns a pointer to a Win instance
Win* createWindowInstance(void);

#endif // VIDEO_H

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