# Assignment: Mini Text Dungeon

## Overview

Your task is to build a simple, text-based console game: a single-level "Mini Text Dungeon". This assignment focuses on C++ programming concepts while emphasizing the use of **null-terminated C-style strings**, **2D arrays**, and **pointers**. The game will run entirely in the console and include basic map navigation and player interactions.

## Learning Objectives

By completing this assignment, you will:

- Use and manipulate **null-terminated C-style strings**.
- Work with **2D arrays** to represent game maps.
- Practice **pointer arithmetic** and **array indexing**.
- Implement basic input handling and game logic.

## Game Requirements

Your game must fulfill the following criteria:

### Core Game Features

#### 1. Player Information

- Prompt the player for their name and store it in a **null-terminated C-style string**.
- Display the player's name at the start of the game.

#### 2. Dungeon Map

- Represent the dungeon map as a **2D char array**. Choose a grid size (e.g., 5x5 or 8x8).
- Design the map using the following symbols:
  - `#` for walls
  - `.` for empty floor space
  - `T` for treasure (goal position)
  - `S` for the starting position

**Example Map Layout (5x5):**
```
#####
#S..#
#.###
#..T#
#####
```

#### 3. Player Movement

- The player can move using the keyboard commands:
  - `w` - Move up
  - `a` - Move left
  - `s` - Move down
  - `d` - Move right
- Validate the player's movement:
  - Prevent movement through walls (`#`).
  - Prevent the player from moving outside the map boundaries.

#### 4. Game Ending Condition

- The game ends when the player reaches the treasure (`T`). Display a victory message that includes the player's name.

#### 5. Code Emphasis

- Use **raw arrays** and **pointers** where appropriate:
  - Store and display the player's name using a **null-terminated C-style string**.
  - Access dungeon cells using **indices** and optionally **pointer arithmetic**.

## Additional Features (Optional)

If you get done early, here are some things to try adding:

- Add **ASCII art** to the game display (e.g., borders, title screen, or victory screen).
- Display **additional stats** like a move counter (e.g., number of steps taken to find the treasure).
- Allow the player to quit the game early by entering a special command (e.g., `q`).

## Hints (examples in the repo)

- C-style string handling: [examples-from-videos/week1/chararray2commented.cpp](../examples-from-videos/week1/chararray2commented.cpp)
- Game loop + repeated input/feedback: [examples-from-videos/week1/hangedmancommented.cpp](../examples-from-videos/week1/hangedmancommented.cpp)
- 2D arrays and indexing: [examples-from-videos/week2/multiarray1commented.cpp](../examples-from-videos/week2/multiarray1commented.cpp)

## What you need to turn in

Submit the following:

1. Your complete source code.
2. A reflection document answering the following questions:

## Reflection Questions

To receive full credit, you must answer the following reflection questions. The highest grade you can achieve without answering these is **3/4**.

1. **Initial Approach:**
   - *How did you begin working on this assignment—did you plan or sketch out a design first, or did you jump straight into coding? Briefly explain why you took that approach.*

2. **Challenges & Problem-Solving:**
   - *What was the most challenging aspect of the assignment, and how did you address it?*

3. **Testing & Debugging:**
   - *How did you test your code, and can you describe one example of a bug you discovered and how you fixed it?*

4. **Design & Structure Improvements:**
   - *If you had more time, what would you change in your code's structure or style to improve clarity or maintainability?*

5. **Conceptual Understanding:**
   - *Did this project change or deepen your understanding of how arrays or pointers work? Describe one insight you gained.*

## Grading Rubric (4-Point Scale)

| Score | Description |
|-------|-------------|
| 4 | The game meets all requirements, compiles, runs correctly, and includes thorough reflection responses. |
| 3 | The game meets most requirements, but reflection questions are missing or incomplete. |
| 2 | The game runs with significant issues or fails to meet core requirements. |
| 1 | Minimal progress; the game is incomplete or does not compile. |
| 0 | No submission. |

Good luck, and have fun designing your dungeon crawler!
