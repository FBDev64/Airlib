# FN
The documentation of the Functions present in the project.
To see a in-project example, please refer to [Airlib-examples](https://github.com/FBDev64/Airlib-examples)

## Color and Strings
The following functions are used to manipulate colors and strings.

Color functions:
- DisplayRedColor(txt) // Used to display a red color, takes text as a parameter
- DisplayGreenColor(txt) // Used to display a green color, takes text as a parameter
- DisplayYellowColor(txt) // Used to display a yellow color, takes text as a parameter
- DisplayBlueColor(txt) // Used to display a blue color, takes text as a parameter
- DisplayMagentaColor(txt) // Used to display a magenta color, takes text as a parameter
- DisplayCyanColor(txt) // Used to display a cyan color, takes text as a parameter
- DisplayWhiteColor(txt) // Used to display a white color, whiter than normal, takes text as a parameter
- DisplayColor(txt, color) // Used to display a color, takes text as a parameter and color as a parameter

String functions:
- DisplayH1(txt, color) // Used to display a header 1
- DisplayH2(txt, color) // Used to display a header 2
- DisplayH3(txt, color) // Used to display a header 3
- DisplayH4(txt, color) // Used to display a header 4
- DisplayH5(txt, color) // Used to display a header 5
- DisplayH6(txt, color) // Used to display a header 6
- DisplayBreakLineDash() // Used to display a dash break line
- DisplayBreakLine() // Used to display a break line

## Window

The following functions are used to manipulate windows.

- InitWindow(title) // Used in a function, e.g. TitleScreen(), to initialize a window. Takes a title as a parameter.
- CloseWindowNy() // Used in a function, e.g. TitleScreen(), to close a window. Asks the user to confirm.
- CloseWindow() // Used in a function, e.g. TitleScreen(), to close a window. Does not ask the user to confirm.
- SegFault() // Used to exit the program with a segmentation fault.
- clrscr() // Used to clear the screen.

## Clock And Time

The following functions are used to manipulate clock and time.

- SysSleep() // Used to sleep the program for a certain amount of time. Takes int as a parameter. In Millisenconds.
- GetTime() // Used to get the current time. Returns a float.
