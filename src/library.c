/* Copyright (c) 2024 Adam Ellouze. All Rights Reserved. */

/* Window */

void newWindow(char title, int width, int height) {}
void closeWindow() {}
void setWindowTitle(char *title) {}

/* Animation */

void frames() {}

/* Input */

enum {
    KEY_UP = 1,
    KEY_DOWN = 2,
    KEY_LEFT = 3,
    KEY_RIGHT = 4,
    KEY_ENTER = 5,
    KEY_ESC = 6,
    KEY_SPACE = 7,
    KEY_BACKSPACE = 8,
    KEY_TAB = 9,
    KEY_CAPS = 10,
    KEY_SHIFT = 11,
    KEY_CTRL = 12,
    KEY_ALT = 13,
    KEY_WIN = 14,
    KEY_MENU = 15,
    KEY_PRINT = 16,
    KEY_PAUSE = 17,
    KEY_HOME = 18,
    KEY_END = 19,
    KEY_PAGEUP = 20,
    KEY_PAGEDOWN = 21,
    KEY_INSERT = 22,
    KEY_DELETE = 23,
    KEY_F1 = 24,
    KEY_F2 = 25,
    KEY_F3 = 26,
    KEY_F4 = 27
} keys;

char nonBlockingInput() {
    return 0;
}

enum {
    MOUSE_LEFT = 1,
    MOUSE_RIGHT = 2,
    MOUSE_MIDDLE = 3,
    MOUSE_WHEEL_UP = 4,
    MOUSE_WHEEL_DOWN = 5
} mouse;

/* Media */

void playSound(char *file) {}
void stopSound(char *file) {}

void sprite(char *file) {}