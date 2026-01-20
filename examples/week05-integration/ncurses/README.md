# Optional: Ncurses Examples

This folder has small ncurses programs for terminal UI. These are optional and are not built by the main Makefiles.

## Quick Start

```bash
cd examples/week05-integration/ncurses
make
./01-hello
```

## If ncurses is missing

If you see `ncurses.h: No such file or directory`, install the dev package:

- Debian/Ubuntu:
  ```bash
  sudo apt-get install libncurses5-dev
  ```
- Fedora:
  ```bash
  sudo dnf install ncurses-devel
  ```
- Arch:
  ```bash
  sudo pacman -S ncurses
  ```

## What the examples cover

1. **01-hello.cpp** - Initialize ncurses, print text, wait for a key
2. **02-input.cpp** - Read keys (including arrow keys)
3. **03-menu.cpp** - Basic menu with highlight and Enter

## Manual compile

If you prefer manual compilation:

```bash
g++ -Wall -g 01-hello.cpp -lncurses -o 01-hello
```
