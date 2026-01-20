/*
 * 04-2d-array-row-sum.cpp
 * Summing each row in a 2D array.
 */

#include <iostream>
using namespace std;

int main() {
    const int ROWS = 3;
    const int COLS = 4;

    int grid[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    for (int row = 0; row < ROWS; row++) {
        int sum = 0;
        for (int col = 0; col < COLS; col++) {
            sum += grid[row][col];
        }
        cout << "Row " << row << " sum: " << sum << endl;
    }

    return 0;
}
