# Airlib

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
[![Licence](https://img.shields.io/static/v1.svg?label=lLicense&message=ZLib&color=blue&style=for-the-badge)](./LICENSE)

Airlib is a game development library for C.

## Further reading

For further reading, documents are available in [docs](./docs/). The documentation, [docs.tex](./docs/docs.tex) is written in French, but the planning document ([NOTES.md](./docs/NOTES.md)) is in English.

The website is [hosted here](https://adamonair.neocities.org/airlib).

## Download

```bash
git clone https://github.com/AdamOnAir/Airlib.git
cd Airlib
mkdir build && cd build
cmake ..
make
```

> [!TIP]
> Use it as a git submodule and include files in `Airlib/include/`.

## Cute

Airlib has a [cute version](./include/cute_airlib.h) (one-file header) for the old library. It is better to use it if only using terminal-based utilities.

## License

Distribute, modify and use freely under the terms of the
[ZLib License](./LICENSE).
