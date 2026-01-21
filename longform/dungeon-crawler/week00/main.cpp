/*
 * Week 00: Basic movement on a fixed map.
 */

#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 7;

void printMap(const char map[ROWS][COLS], int playerRow, int playerCol) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (r == playerRow && c == playerCol) {
                cout << '@';
            } else {
                cout << map[r][c];
            }
        }
        cout << endl;
    }
}

int main() {
    char map[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#'},
        {'#', 'S', '.', '.', '#', 'T', '#'},
        {'#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#'}
    };

    int row = 1;
    int col = 1;

    cout << "Use w/a/s/d to move, q to quit." << endl;

    while (true) {
        printMap(map, row, col);
        cout << "Move: ";

        char input;
        cin >> input;
        if (input == 'q') {
            break;
        }

        int newRow = row;
        int newCol = col;

        if (input == 'w') newRow--;
        else if (input == 's') newRow++;
        else if (input == 'a') newCol--;
        else if (input == 'd') newCol++;

        if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLS) {
            cout << "Out of bounds!" << endl;
            continue;
        }

        if (map[newRow][newCol] == '#') {
            cout << "Wall!" << endl;
            continue;
        }

        row = newRow;
        col = newCol;

        if (map[row][col] == 'T') {
            printMap(map, row, col);
            cout << "You found the treasure!" << endl;
            break;
        }
    }

    return 0;
}
