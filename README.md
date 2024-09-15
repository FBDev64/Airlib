# Airlib

A Cross-Platform development library for Terminal gamedev.

## Technical Badges

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

## Features

- Rich Text Display : DisplayText()
- Error Beautifying : Airlib_Logger()
- Drawing : DrawBox()
- Screen Manipulation : clrscr(), SegFault()
- Clock and Time : GetGameTime(), SysSleep()
- Get Platform : Airlib_GetPlatform()

## Compile and Run

Just include the `library.c` and `library.h` in your codebase and rename it to `airlib.c` and `airlib.h`.

Tip : Compile like `gcc main.c <path/to/airlib.c>`

## Contributing 

Pull requests are welcome. Make sure the code you wrote works before making the PR.

Tip : If a function **YOU** implemented doesn't work, just delete it. Like I did for `void DisplayColor(char *txt, char *color)` in previous versions.

## License

Distribute, modify and use freely under the terms of the
[BSD 3-Clause “New” or “Revised” License](./LICENSE).
