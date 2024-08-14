# Airlib

I recently discoverd Raylib, and I, as a C developer, decided I'll create a "port" of for the Terminal.

## Technical Badges

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

## Documentation
See the [FN.md](./FN.md), where thre is the descripton of the functions and usages.
For a real example, check [FBD](https://github.com/fbdev64/FBD.git)

## Compile and Run

Just include the `library.c` and `library.h` in your codebase and rename it to `airlib.c` and `airlib.h`.
<br>I use CMake, by the way.

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Tip : If a function **YOU** implemented doesn't work, just delete it. Like I did for `void DisplayColor(char *txt, char *color)` in previous versions.

## License

Distribute, modify and use freely under the terms of the
[BSD 3-Clause “New” or “Revised” License](./LICENSE).
