//  NOTE: Any system running X11 can be handled by linux_video

#ifdef __linux__

#include "../../../include/video.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

static Display *d;
static Window w;
static XEvent e;
static int s;

void createWindow(int width, int height) {
  
  d = XOpenDisplay(NULL);
  w = XCreateSimpleWindow(d, RootWindow(d,s), 0, 0, width, height, 1, 
    BlackPixel(d,s), WhitePixel(d,s));

  s = DefaultScreen(d);


  if (d == NULL) {
    printf("Cannot open display");
    exit(1);
  }
  
  XMapWindow(d, w);
  XPending(d);
}


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
