# Week 06: Dynamic Memory

The map and fog-of-war arrays are now allocated at runtime based on the map file.

## New in this week
- Dynamic 2D arrays with `new[]`
- Manual cleanup with `delete[]`
- Reuse skills, combat, and saves

## Build and run

```bash
make
./game
```

## Files
- `map.txt` provides the dungeon layout
- `save.txt` is created when you save
