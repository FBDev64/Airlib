/* Copyright (c) 2024 Adam Ellouze. All Rights Reserved. */

#ifndef TERMINAL_H
#define TERMINAL_H

#include <stddef.h>

// ------------------------------------------------
// Some Basic Info
// ------------------------------------------------

#define KCLS  "\e[2J"
#define KNRM  "\e[0m"
#define KRED  "\e[31m"
#define KGRN  "\e[32m"
#define KYEL  "\e[33m"
#define KBLU  "\e[34m"
#define KMAG  "\e[35m"
#define KCYN  "\e[36m"
#define KWHT  "\e[37m"
#define KHOL "\033[90m%s\033[0m" // placeholder

// -------------------------------------------------
// Error Handling
// -------------------------------------------------

char *errorLog(char *text, unsigned int error, unsigned int warn, unsigned int info);

// -------------------------------------------------
// Get Platform
// -------------------------------------------------

#if defined(_WIN32)
#define GET_PLATFORM "Windows"
#elif defined(__APPLE__) || defined(__MACH__)
    #define GET_PLATFORM "Apple"
#elif defined(TARGET_OS_EMBEDDED)
    #define GET_PLATFORM "iOS Embedded"
#elif defined(TARGET_IPHONE_SIMULATOR)
    #define GET_PLATFORM "iOS Emulator"
#elif defined(TARGET_OS_IPHONE)
    #define GET_PLATFORM "iOS"
#elif defined(TARGET_OS_MAC)
    #define GET_PLATFORM "MacOS"
#elif defined(__unix__)
    #define GET_PLATFORM "Unix"
#elif defined(__linux__)
    #define GET_PLATFORM "Linux"
#elif defined(__sun)
    #define GET_PLATFORM "Solaris"
#elif defined(__hpux)
    #define GET_PLATFORM "HP UX"
#elif defined(__DragonFly__)
    #define GET_PLATFORM "DragonFly BSD"
#elif defined(__FreeBSD__)
    #define GET_PLATFORM "FreeBSD"
#elif defined(__NetBSD__)
    #define GET_PLATFORM "NetBSD"
#elif defined(__OpenBSD__)
    #define GET_PLATFORM "OpenBSD"
#else
    #define GET_PLATFORM "Unknown platform"
#endif

// -------------------------------------------------
// Color and Strings
// -------------------------------------------------

void richText(char *text, char *color, unsigned int bold, unsigned int italic, unsigned int underline);

void placeholder(char *text, char *output, size_t output_size);

// ------------------------------------------------
// Window
// ------------------------------------------------

void segFault();

void clrscr();

// ------------------------------------------------
// Clock and Time
// ------------------------------------------------

void sysSleep(int ms);

float getGameTime();

float stopWatch();

// ------------------------------------------------
// Drawing
// ------------------------------------------------

void drawBox(int x, int y, int width, int height, char *color);

// -----------------------------------------------
// I/O 
// -----------------------------------------------

#ifdef _WIN32
char nonBlockingInput();
#else
  void enableNonBlockingInput(); 
  void disableNonBlockingInput();
#endif

#endif //TERMINAL_H

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
