#include <stdio.h>

#include "include/old.h"

void main() { // Example usage of placeholder function with KHOL
    char output[100];  // User-defined buffer for output

    // Call the placeholder function
    placeholder("Enter your name here...", output, sizeof(output));

    // User can print the input when desired
    printf("\nYou entered: %s\n", output);

    return 0;placeholder("Enter your name here...");
}