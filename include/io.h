#ifndef VDL_IO_H
#define VDL_IO_H

#ifdef _WIN32
#include <windows.h>
#endif

typedef enum {
    VDL_KEY_UNKNOWN = 0,
    VDL_KEY_A = 0x41,
    VDL_KEY_B = 0x42,
    VDL_KEY_C = 0x43,
    VDL_KEY_D = 0x44,
    VDL_KEY_E = 0x45,
    VDL_KEY_F = 0x46,
    VDL_KEY_G = 0x47,
    VDL_KEY_H = 0x48,
    VDL_KEY_I = 0x49,
    VDL_KEY_J = 0x4A,
    VDL_KEY_K = 0x4B,
    VDL_KEY_L = 0x4C,
    VDL_KEY_M = 0x4D,
    VDL_KEY_N = 0x4E,
    VDL_KEY_O = 0x4F,
    VDL_KEY_P = 0x50,
    VDL_KEY_Q = 0x51,
    VDL_KEY_R = 0x52,
    VDL_KEY_S = 0x53,
    VDL_KEY_T = 0x54,
    VDL_KEY_U = 0x55,
    VDL_KEY_V = 0x56,
    VDL_KEY_W = 0x57,
    VDL_KEY_X = 0x58,
    VDL_KEY_Y = 0x59,
    VDL_KEY_Z = 0x5A,
    VDL_KEY_0 = 0x30,
    VDL_KEY_1 = 0x31,
    VDL_KEY_2 = 0x32,
    VDL_KEY_3 = 0x33,
    VDL_KEY_4 = 0x34,
    VDL_KEY_5 = 0x35,
    VDL_KEY_6 = 0x36,
    VDL_KEY_7 = 0x37,
    VDL_KEY_8 = 0x38,
    VDL_KEY_9 = 0x39,
    VDL_KEY_ESCAPE = VK_ESCAPE,
    VDL_KEY_SPACE = VK_SPACE,
    VDL_KEY_ENTER = VK_RETURN,
    VDL_KEY_BACKSPACE = VK_BACK,
    VDL_KEY_TAB = VK_TAB,
    VDL_KEY_SHIFT = VK_SHIFT,
    VDL_KEY_CONTROL = VK_CONTROL,
    VDL_KEY_ALT = VK_MENU,
    VDL_KEY_UP = VK_UP,
    VDL_KEY_DOWN = VK_DOWN,
    VDL_KEY_LEFT = VK_LEFT,
    VDL_KEY_RIGHT = VK_RIGHT,
    VDL_KEY_F1 = VK_F1,
    VDL_KEY_F2 = VK_F2,
    VDL_KEY_F3 = VK_F3,
    VDL_KEY_F4 = VK_F4,
    VDL_KEY_F5 = VK_F5,
    VDL_KEY_F6 = VK_F6,
    VDL_KEY_F7 = VK_F7,
    VDL_KEY_F8 = VK_F8,
    VDL_KEY_F9 = VK_F9,
    VDL_KEY_F10 = VK_F10,
    VDL_KEY_F11 = VK_F11,
    VDL_KEY_F12 = VK_F12
} VDL_Key;

int vdl_isKeyPressed(VDL_Key key);

#endif // VDL_IO_H
