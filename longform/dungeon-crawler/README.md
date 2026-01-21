# Longform Tutorial: Dungeon Crawler

This is a week-by-week build of a simple dungeon crawler. Each week is a full snapshot that compiles and runs on its own. The goal is to layer new course concepts onto the same project until it becomes a fully-formed game with combat, loot, persistence, and a terminal UI.

## Structure

Each folder contains a README and a full program for that week:

```
longform/dungeon-crawler/
  week00/
  week01/
  ...
  week10/
```

## How to build

For weeks with a single file:

```bash
g++ -Wall -g main.cpp -o game
./game
```

For weeks with multiple files, a Makefile is provided in that week.

## Notes

- Week 10 switches to `ncurses` for the UI. See that week's README for install steps and build flags.
- Each week’s README lists the new features and concepts introduced.
