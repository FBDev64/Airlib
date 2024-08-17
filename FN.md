# FN
The documentation of the Functions present in the project.
To see an in-project example, please refer to [Airlib-examples](https://github.com/FBDev64/Airlib-examples)

## Color and Strings
The following functions are used to manipulate colors and strings.

Color functions:
- DisplayRedColor(txt)
    - Displays text in red color
    - Parameters:
        - txt: char* - The text to be displayed
    - Usage: DisplayRedColor("This is red text");

- DisplayGreenColor(txt)
    - Displays text in green color
    - Parameters:
        - txt: char* - The text to be displayed
    - Usage: DisplayGreenColor("This is green text");

- DisplayYellowColor(txt)
    - Displays text in yellow color
    - Parameters:
        - txt: char* - The text to be displayed
    - Usage: DisplayYellowColor("This is yellow text");

- DisplayBlueColor(txt)
    - Displays text in blue color
    - Parameters:
        - txt: char* - The text to be displayed
    - Usage: DisplayBlueColor("This is blue text");

- DisplayMagentaColor(txt)
    - Displays text in magenta color
    - Parameters:
        - txt: char* - The text to be displayed
    - Usage: DisplayMagentaColor("This is magenta text");

- DisplayCyanColor(txt)
    - Displays text in cyan color
    - Parameters:
        - txt: char* - The text to be displayed
    - Usage: DisplayCyanColor("This is cyan text");

- DisplayWhiteColor(txt)
    - Displays text in white color (whiter than normal)
    - Parameters:
        - txt: char* - The text to be displayed
    - Usage: DisplayWhiteColor("This is white text");

String functions:
- DisplayTitle(txt)
    - Displays a header 1 (largest)
    - Parameters:
        - txt: char* - The text to be displayed
        - color: char* - The color code to use (e.g., KRED, KGRN)
    - Usage: DisplayH1("Main Title", KRED);

- DisplaySubTitle(txt)
    - Displays a header 2
    - Parameters:
        - txt: char* - The text to be displayed
        - color: char* - The color code to use
    - Usage: DisplayH2("Subtitle");
    - 
- DisplayBreakLine()
    - Displays a line break (newline)
    - Usage: DisplayBreakLine();

## Window

The following functions are used to manipulate windows.

- InitWindow()
    - Clears the console screen
    - Usage: InitWindow();

- CloseWindowNy()
    - Prompts the user to confirm window closure
    - Usage: CloseWindowNy();

- CloseWindow()
    - Closes the window (exits the program) without confirmation
    - Usage: CloseWindow();

- SegFault()
    - Intentionally causes a segmentation fault (for testing purposes)
    - Usage: SegFault();

- clrscr()
    - Clears the console screen (alias for InitWindow)
    - Usage: clrscr();

## Clock And Time

The following functions are used to manipulate clock and time.

- SysSleep(ms)
    - Pauses the program execution for a specified time
    - Parameters:
        - ms: int - The number of milliseconds to sleep
    - Usage: SysSleep(1000); // Sleep for 1 second

- GetGameTime()
    - Prints the current local time
    - Usage: GetGameTime();

## Drawing

The following functions are used for drawing various shapes and lines.

- DrawRedLine()
    - Draws a red horizontal line
    - Usage: DrawRedLine();

- DrawGreenLine()
    - Draws a green horizontal line
    - Usage: DrawGreenLine();

- DrawYellowLine()
    - Draws a yellow horizontal line
    - Usage: DrawYellowLine();

- DrawBlueLine()
    - Draws a blue horizontal line
    - Usage: DrawBlueLine();

- DrawMagentaLine()
    - Draws a magenta horizontal line
    - Usage: DrawMagentaLine();

- DrawCyanLine()
    - Draws a cyan horizontal line
    - Usage: DrawCyanLine();

- DrawWhiteLine()
    - Draws a white horizontal line
    - Usage: DrawWhiteLine();

- DrawRedPolygon(sides)
    - Draws a red polygon with specified number of sides
    - Parameters:
        - sides: int - The number of sides for the polygon
    - Usage: DrawRedPolygon(5); // Draws a red pentagon

- DrawGreenPolygon(sides)
    - Draws a green polygon with specified number of sides
    - Parameters:
        - sides: int - The number of sides for the polygon
    - Usage: DrawGreenPolygon(3); // Draws a green triangle

- DrawYellowPolygon(sides)
    - Draws a yellow polygon with specified number of sides
    - Parameters:
        - sides: int - The number of sides for the polygon
    - Usage: DrawYellowPolygon(4); // Draws a yellow square

- DrawBluePolygon(sides)
    - Draws a blue polygon with specified number of sides
    - Parameters:
        - sides: int - The number of sides for the polygon
    - Usage: DrawBluePolygon(6); // Draws a blue hexagon

- DrawMagentaPolygon(sides)
    - Draws a magenta polygon with specified number of sides
    - Parameters:
        - sides: int - The number of sides for the polygon
    - Usage: DrawMagentaPolygon(8); // Draws a magenta octagon

- DrawCyanPolygon(sides)
    - Draws a cyan polygon with specified number of sides
    - Parameters:
        - sides: int - The number of sides for the polygon
    - Usage: DrawCyanPolygon(7); // Draws a cyan heptagon

- DrawWhitePolygon(sides)
    - Draws a white polygon with specified number of sides
    - Parameters:
        - sides: int - The number of sides for the polygon
    - Usage: DrawWhitePolygon(10); // Draws a white decagon

## Math

The following functions provide mathematical operations.

- DEG2RAD(deg)
    - Converts degrees to radians
    - Parameters:
        - deg: float - The angle in degrees
    - Returns: float - The angle in radians
    - Usage: float radians = DEG2RAD(90.0f);

- RAD2DEG(rad)
    - Converts radians to degrees
    - Parameters:
        - rad: float - The angle in radians
    - Returns: float - The angle in degrees
    - Usage: float degrees = RAD2DEG(3.14159f);
