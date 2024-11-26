#include "include/terminal.h"
#include <string.h>
#include <stdio.h>

int main(void) {
  const char output[100];

  placeholder("RUSH... ", &output, sizeof(output));
  if (strcmp(output, "E") == 0) {
    printf("Far, Far Far Quad saying E is your idol.");
  } else if (strcmp(output, "F") == 0) {
    printf("I serve the soviet onion.");
  }
}
