# Airlib

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
[![Licence](https://img.shields.io/static/v1.svg?label=lLicense&message=ZLib&color=blue&style=for-the-badge)](./LICENSE)

Airlib - a game development library for C.

## Further reading

For further reading, documents are available in [docs](./docs/). The the planning document ([NOTES.md](./docs/PLAN.md)) is a technical sort of changelog.

The website is available [here](https://adamonair.neocities.org/airlib).

## Download

Shared Object library, use at compile time :

```bash
git clone https://github.com/AdamOnAir/Airlib.git
cd Airlib
mkdir build && cd build
cmake ..
make
```

Git Submodule :

```bash
git submodule add https://github.com/AdamOnAir/Airlib.git
```

## Cute

Airlib has a [cute version](./include/cute_airlib.h) (one-file header) for the old library. It is better to use it if only using terminal-based utilities.

## License

Distribute, modify and use freely under the terms of the [ZLib License](./LICENSE).
