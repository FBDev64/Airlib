#ifdef _WIN32

#include <windows.h>
#include "../../../include/io.h"

// Function to check if a key is currently pressed
__declspec(dllexport) int vdl_isKeyPressed(VDL_Key key) {
    return (GetAsyncKeyState((int)key) & 0x8000) != 0;
}

#endif
