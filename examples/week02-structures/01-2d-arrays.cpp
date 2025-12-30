/*
 * 01-2d-arrays.cpp
 * Working with grids and tables.
 *
 * A 2D array is an array of arrays. Think of it like a spreadsheet:
 * rows and columns, accessed with two indices: array[row][col]
 */

#include <iostream>
using namespace std;

int main() {
    // === Creating 2D arrays ===
    cout << "=== Creating a 3x4 grid ===" << endl;

    // A 2D array: 3 rows, 4 columns
    int grid[3][4] = {
        {1,  2,  3,  4},   // Row 0
        {5,  6,  7,  8},   // Row 1
        {9, 10, 11, 12}    // Row 2
    };

    // Print it out nicely
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << grid[row][col] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // === Accessing specific elements ===
    cout << "=== Specific elements ===" << endl;
    cout << "grid[0][0] (top-left): " << grid[0][0] << endl;
    cout << "grid[2][3] (bottom-right): " << grid[2][3] << endl;
    cout << "grid[1][2] (middle-ish): " << grid[1][2] << endl;
    cout << endl;

    // === Modifying elements ===
    cout << "=== After setting corners to 99 ===" << endl;
    grid[0][0] = 99;
    grid[0][3] = 99;
    grid[2][0] = 99;
    grid[2][3] = 99;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << grid[row][col] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // === Finding the sum ===
    cout << "=== Computing the sum ===" << endl;
    int sum = 0;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            sum += grid[row][col];
        }
    }
    cout << "Sum of all elements: " << sum << endl;
    cout << endl;

    // === A practical example: game board ===
    cout << "=== Tic-Tac-Toe board ===" << endl;
    char board[3][3] = {
        {'X', 'O', 'X'},
        {' ', 'X', 'O'},
        {'O', ' ', 'X'}
    };

    // Print with grid lines
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << " " << board[row][col] << " ";
            if (col < 2) cout << "|";
        }
        cout << endl;
        if (row < 2) cout << "---+---+---" << endl;
    }

    return 0;
}

/*
 * Key points:
 *
 * 1. First index is row, second is column: array[row][col]
 * 2. Nested loops are natural for processing 2D arrays
 * 3. Outer loop usually iterates rows, inner loop iterates columns
 * 4. Initializer uses nested braces { {row0}, {row1}, {row2} }
 *
 * Memory note:
 * Under the hood, a 3x4 array is stored as 12 consecutive integers.
 * grid[1][2] is really element 1*4 + 2 = 6 in the flat sequence.
 */
