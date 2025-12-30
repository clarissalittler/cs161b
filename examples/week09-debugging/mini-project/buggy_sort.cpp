/*
 * Mini-Project: Bug Hunt
 *
 * This sorting program has exactly 5 bugs.
 * Your mission: Find and fix all of them!
 *
 * The program should:
 * 1. Read numbers from the user
 * 2. Sort them in ascending order using bubble sort
 * 3. Print the sorted result
 *
 * Bugs to find:
 * - Look for off-by-one errors
 * - Look for wrong comparisons
 * - Look for missing operations
 * - Look for incorrect array access
 * - Look for logic errors
 *
 * Use print debugging, GDB, or careful reading to find them all!
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// BUG(S) may be in this function
int readNumbers(int arr[]) {
    int count;
    cout << "How many numbers? ";
    cin >> count;

    if (count > MAX_SIZE) {
        count = MAX_SIZE;
    }

    for (int i = 1; i <= count; i++) {  // BUG #1: Should start at 0, use <
        cout << "Enter number " << i << ": ";
        cin >> arr[i];
    }

    return count;
}

// BUG(S) may be in this function
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {  // BUG #2: should be size - 1 - i
            if (arr[j] < arr[j + 1]) {  // BUG #3: Should be > for ascending
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                // BUG #4: Missing the other half of swap
            }
        }
    }
}

// BUG(S) may be in this function
void printArray(int arr[], int size) {
    cout << "Sorted array: ";
    for (int i = 0; i <= size; i++) {  // BUG #5: Should use <, not <=
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
}

int main() {
    int numbers[MAX_SIZE];

    cout << "=== Bubble Sort ===" << endl;

    int count = readNumbers(numbers);
    bubbleSort(numbers, count);
    printArray(numbers, count);

    return 0;
}

/*
 * Test case:
 * Input: 5 numbers: 3, 1, 4, 1, 5
 * Expected output: 1, 1, 3, 4, 5
 *
 * If your output is wrong, you haven't found all the bugs!
 *
 * Hints (only read if stuck):
 *
 *
 *
 *
 *
 * Hint 1: Arrays are 0-indexed
 * Hint 2: Bubble sort moves the largest to the end each pass
 * Hint 3: A swap needs to exchange BOTH values
 * Hint 4: Loop bounds matter!
 * Hint 5: What does the comparison operator do?
 */
