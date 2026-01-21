# Week 09: Debugging

This week adds a small debug summary you can toggle at build time.

## New in this week
- `debugSummary` for quick state dumps
- A debug build target
- Debug output goes to `stderr`

## Build and run

```bash
make
./game
```

To build with debug output:

```bash
make debug
./game_debug
```

## Files
- `map.txt` provides the dungeon layout
- `save.txt` is created when you save
