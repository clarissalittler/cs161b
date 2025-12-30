/*
 * 02-gdb-practice.cpp
 * A program with bugs to practice using GDB.
 *
 * Compile with: g++ -g 02-gdb-practice.cpp -o debug_me
 * Debug with: gdb ./debug_me
 *
 * GDB quick reference:
 *   break main      - Set breakpoint at main
 *   break 42        - Set breakpoint at line 42
 *   run             - Start/restart the program
 *   next (n)        - Execute next line (step over)
 *   step (s)        - Execute next line (step into)
 *   continue (c)    - Run until next breakpoint
 *   print x         - Print value of x
 *   print arr[0]    - Print array element
 *   display x       - Print x after every step
 *   backtrace (bt)  - Show call stack
 *   quit            - Exit GDB
 */

#include <iostream>
using namespace std;

// This function has a bug - can you find it with GDB?
int calculateSum(int arr[], int size) {
    int sum = 0;

    // Hint: Set a breakpoint here and watch the loop
    for (int i = 1; i <= size; i++) {  // BUG: starts at 1, uses <=
        sum += arr[i];
    }

    return sum;
}

// This function also has a bug
int findMax(int arr[], int size) {
    int max = 0;  // BUG: should be arr[0], not 0

    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// This recursive function has a bug
int factorial(int n) {
    // BUG: Missing base case check for n < 0
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// This function has a bug with array access
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {  // BUG: should be size/2
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
}

int main() {
    cout << "=== GDB Practice Program ===" << endl;
    cout << "(This program has bugs to find with GDB)" << endl << endl;

    // Test data
    int numbers[] = {5, 2, 8, 1, 9, 3};
    int size = 6;

    cout << "Original array: ";
    printArray(numbers, size);
    cout << endl;

    // Test calculateSum
    // Expected: 5+2+8+1+9+3 = 28
    int sum = calculateSum(numbers, size);
    cout << "Sum (should be 28): " << sum << endl;

    // Test findMax
    // Expected: 9
    int max = findMax(numbers, size);
    cout << "Max (should be 9): " << max << endl;

    // Test factorial
    // Expected: 120
    int fact = factorial(5);
    cout << "5! (should be 120): " << fact << endl;

    // Test reverseArray
    // Make a copy to reverse
    int copy[] = {1, 2, 3, 4, 5};
    cout << "Before reverse: ";
    printArray(copy, 5);

    reverseArray(copy, 5);

    cout << "After reverse (should be 5,4,3,2,1): ";
    printArray(copy, 5);

    cout << endl << "=== GDB Practice ===" << endl;
    cout << "Try these GDB commands:" << endl;
    cout << "  gdb ./debug_me" << endl;
    cout << "  (gdb) break calculateSum" << endl;
    cout << "  (gdb) run" << endl;
    cout << "  (gdb) print i" << endl;
    cout << "  (gdb) print arr[i]" << endl;
    cout << "  (gdb) next" << endl;
    cout << "  (gdb) continue" << endl;

    return 0;
}

/*
 * Bugs in this program:
 *
 * 1. calculateSum: Loop starts at i=1 instead of i=0,
 *    and uses <= instead of <
 *    Fix: for (int i = 0; i < size; i++)
 *
 * 2. findMax: Initializes max to 0 instead of arr[0]
 *    This fails if all elements are negative
 *    Fix: int max = arr[0];
 *
 * 3. factorial: No check for n < 0
 *    factorial(-1) would recurse forever
 *    Fix: if (n <= 0) return 1; // or handle error
 *
 * 4. reverseArray: Loop goes to size instead of size/2
 *    This reverses the array twice (back to original)
 *    Fix: for (int i = 0; i < size/2; i++)
 *
 * Use GDB to step through each function and watch the
 * variables to understand why the output is wrong.
 */
