# Week 10: ncurses + Templates

This week switches the UI to `ncurses` and adds a small template helper.

## New in this week
- `ncurses` screen drawing and key input
- A templated `clamp` helper in `utils.h`
- A status bar above the map

## Install ncurses (Linux)

On Ubuntu/Debian:

```bash
sudo apt-get update
sudo apt-get install libncurses5-dev libncursesw5-dev
```

## Build and run

```bash
make
./game
```

## Files
- `map.txt` provides the dungeon layout
- `save.txt` is created when you save
