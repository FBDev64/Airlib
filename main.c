#include <stdio.h>

#include "include/old.h"

void main() {
    char che[100];
    // Example usage of placeholder function with KHOL
    placeholder("Enter your name here...", che);
    richText("Hello World", KBLU, 1, 0, 0);
    printf("%s", che);
}