#include "include/graphics.h"

int main() {
    // Create a window with specific width, height, and name
    createWindow(800, 600, "My Window");

    // Set an icon for the window
    setWindowIcon("test.xpm");

    // Display some text in the window
    displayWindowText("Hello, World!");

    return 0;
}

