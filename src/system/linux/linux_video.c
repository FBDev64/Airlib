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
