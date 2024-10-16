/* Copyright (c) 2024 Adam Ellouze. All Rights Reserved. */

#ifndef AIRLIB_LIBRARY_H
#define AIRLIB_LIBRARY_H

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

#endif //AIRLIB_LIBRARY_H

