/*
 * 03-2d-dynamic.cpp
 * Two-dimensional dynamic arrays.
 *
 * A 2D dynamic array is an array of pointers, where each
 * pointer points to a row (itself a dynamic array).
 *
 * It's pointers all the way down!
 */

#include <iostream>
using namespace std;

// Allocate a 2D array of the given dimensions
int** create2DArray(int rows, int cols) {
    // Allocate the row pointers
    int** grid = new int*[rows];

    // Allocate each row
    for (int i = 0; i < rows; i++) {
        grid[i] = new int[cols];
    }

    return grid;
}

// Free a 2D array
void delete2DArray(int** grid, int rows) {
    // Delete each row first
    for (int i = 0; i < rows; i++) {
        delete[] grid[i];
    }

    // Then delete the row pointers
    delete[] grid;
}

// Fill with a pattern
void fillGrid(int** grid, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = r * cols + c;
        }
    }
}

// Print the grid
void printGrid(int** grid, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << grid[r][c] << "\t";
        }
        cout << endl;
    }
}

int main() {
    // ========================================
    // CREATE A 2D ARRAY
    // ========================================

    cout << "=== Creating a dynamic 2D array ===" << endl;

    int rows, cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter columns: ";
    cin >> cols;

    // Allocate the 2D array
    int** grid = create2DArray(rows, cols);

    // Fill it
    fillGrid(grid, rows, cols);

    // Print it
    cout << "Grid contents:" << endl;
    printGrid(grid, rows, cols);

    cout << endl;

    // ========================================
    // HOW IT WORKS IN MEMORY
    // ========================================

    cout << "=== Memory layout ===" << endl;
    cout << "grid points to: " << grid << endl;
    cout << "grid[0] points to: " << grid[0] << " (first row)" << endl;
    cout << "grid[1] points to: " << grid[1] << " (second row)" << endl;
    cout << endl;
    cout << "grid[0][0] = " << grid[0][0] << endl;
    cout << "&grid[0][0] = " << &grid[0][0] << endl;
    cout << endl;

    /*
     * Memory layout visualization:
     *
     * grid ───────> [ ptr0 | ptr1 | ptr2 | ... ]
     *                  │      │      │
     *                  ▼      │      │
     *               [0][1][2] │      │
     *                         ▼      │
     *                      [0][1][2] │
     *                                ▼
     *                             [0][1][2]
     */

    // ========================================
    // MANUAL ALLOCATION (for understanding)
    // ========================================

    cout << "=== Step-by-step allocation ===" << endl;

    // Let's do 3x4 step by step
    int numRows = 3;
    int numCols = 4;

    // Step 1: Allocate the row pointers
    int** matrix = new int*[numRows];
    cout << "Allocated " << numRows << " row pointers" << endl;

    // Step 2: Allocate each row
    for (int i = 0; i < numRows; i++) {
        matrix[i] = new int[numCols];
        cout << "Allocated row " << i << " with " << numCols << " columns" << endl;
    }

    // Fill with multiplication table
    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            matrix[r][c] = (r + 1) * (c + 1);
        }
    }

    cout << "Multiplication table:" << endl;
    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            cout << matrix[r][c] << "\t";
        }
        cout << endl;
    }

    // Step 3: Clean up (reverse order!)
    cout << endl << "Cleaning up..." << endl;
    for (int i = 0; i < numRows; i++) {
        delete[] matrix[i];
        cout << "Deleted row " << i << endl;
    }
    delete[] matrix;
    cout << "Deleted row pointers" << endl;
    matrix = nullptr;

    cout << endl;

    // ========================================
    // CLEAN UP THE FIRST GRID
    // ========================================

    delete2DArray(grid, rows);
    grid = nullptr;

    cout << "All memory freed!" << endl;

    return 0;
}

/*
 * 2D Dynamic Array Summary:
 *
 * ALLOCATION:
 *   int** grid = new int*[rows];     // Row pointers
 *   for each row:
 *       grid[i] = new int[cols];     // Each row
 *
 * USAGE:
 *   grid[row][col] = value;          // Just like static 2D arrays!
 *
 * DEALLOCATION (reverse order!):
 *   for each row:
 *       delete[] grid[i];            // Each row first
 *   delete[] grid;                    // Then row pointers
 *
 * Why reverse order?
 * - If you delete[] grid first, you lose the row pointers
 * - Then you can't access grid[i] to delete the rows
 * - Memory leak!
 */
