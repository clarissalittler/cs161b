/*
 * Assignment 2: Mini Text Dungeon - Starter Code
 *
 * This provides the basic structure. You need to:
 * 1. Design your map
 * 2. Implement player movement
 * 3. Handle collision detection
 * 4. Implement win condition
 *
 * This is just one possible approach - feel free to restructure!
 */

#include <iostream>
using namespace std;

int main() {
    // Player name (C-style string)
    const int NAME_SIZE = 50;
    char playerName[NAME_SIZE];

    // TODO: Prompt for and read player name
    cout << "Enter your name: ";
    // Your input code here (use cin.getline or similar)

    // TODO: Display welcome message with player's name

    // Dungeon map - TODO: Design your own map
    const int MAP_SIZE = 5;  // You can change this
    char map[MAP_SIZE][MAP_SIZE] = {
        {'#', '#', '#', '#', '#'},
        {'#', 'S', '.', '.', '#'},
        {'#', '.', '#', '#', '#'},
        {'#', '.', '.', 'T', '#'},
        {'#', '#', '#', '#', '#'}
    };

    // Player position - TODO: Set to starting position
    int playerRow = 0;  // Replace with correct starting row
    int playerCol = 0;  // Replace with correct starting col

    // Game loop
    bool gameWon = false;
    char move;

    while (!gameWon) {
        // TODO: Display the map
        // Your code here to print the 2D array

        // TODO: Show player position or mark it on the map

        // Get player input
        cout << "\nMove (w/a/s/d): ";
        cin >> move;

        // TODO: Calculate new position based on move
        int newRow = playerRow;
        int newCol = playerCol;

        // Your movement logic here
        // w = up (row-1), s = down (row+1)
        // a = left (col-1), d = right (col+1)

        // TODO: Check if new position is valid
        // - Not outside boundaries
        // - Not a wall ('#')

        // TODO: If valid, update player position

        // TODO: Check if player reached treasure ('T')
        // If so, set gameWon = true
    }

    // TODO: Display victory message with player's name

    return 0;
}
