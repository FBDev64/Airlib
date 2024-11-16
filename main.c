#include <X11/Xlib.h>

#include "include/Airlib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  createWindow(800, 600);
  if(XPending(d)) {
    XNextEvent(d, &e);
    printf("EVENT: %d", e.type);
  }
  printf("EXITTING\n");
}
