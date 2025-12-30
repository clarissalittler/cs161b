/*
 * 03-loops.cpp
 * Repeating actions: for loops and while loops.
 *
 * Use 'for' when you know how many times to loop.
 * Use 'while' when you're waiting for something to happen.
 */

#include <iostream>
using namespace std;

int main() {
    // === FOR LOOPS ===
    // The classic counting loop

    cout << "=== Counting with for ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "i is " << i << endl;
    }
    cout << endl;

    // Note: i starts at 0 and goes to 4 (not 5!)
    // This "zero-indexed, less-than" pattern is everywhere in C++

    // Counting backwards
    cout << "=== Countdown ===" << endl;
    for (int i = 5; i > 0; i--) {
        cout << i << "..." << endl;
    }
    cout << "Liftoff!" << endl;
    cout << endl;

    // === WHILE LOOPS ===
    // Keep going until a condition is false

    cout << "=== Doubling with while ===" << endl;
    int value = 1;
    while (value < 100) {
        cout << value << endl;
        value = value * 2;  // Double it each time
    }
    cout << "(Stopped because " << value << " >= 100)" << endl;
    cout << endl;

    // === NESTED LOOPS ===
    // Loops inside loops - useful for grids and tables

    cout << "=== Multiplication table (1-5) ===" << endl;
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= 5; col++) {
            cout << (row * col) << "\t";  // \t is a tab character
        }
        cout << endl;  // New line after each row
    }

    return 0;
}

/*
 * Quick check:
 * - How many times does the outer loop run in the multiplication table?
 * - How many times does the inner loop run in total?
 * - What would happen if we used < instead of <= in those loops?
 */
