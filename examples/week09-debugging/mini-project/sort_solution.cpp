/*
 * sort_solution.cpp
 * The corrected version of buggy_sort.cpp
 *
 * DON'T PEEK until you've tried to fix it yourself!
 *
 * All 5 bugs have been fixed with comments explaining each.
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int readNumbers(int arr[]) {
    int count;
    cout << "How many numbers? ";
    cin >> count;

    if (count > MAX_SIZE) {
        count = MAX_SIZE;
    }

    // FIX #1: Start at 0, use < instead of <=
    // Arrays are 0-indexed, so we need indices 0 to count-1
    for (int i = 0; i < count; i++) {
        cout << "Enter number " << (i + 1) << ": ";  // Display as 1-based
        cin >> arr[i];
    }

    return count;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {  // Outer loop: size-1 passes
        // FIX #2: Inner loop should be size - 1 - i
        // Each pass moves one more element to its final position
        for (int j = 0; j < size - 1 - i; j++) {
            // FIX #3: Use > for ascending order (swap if left > right)
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;  // FIX #4: Complete the swap!
            }
        }
    }
}

void printArray(int arr[], int size) {
    cout << "Sorted array: ";
    // FIX #5: Use < instead of <= to stay within bounds
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
}

int main() {
    int numbers[MAX_SIZE];

    cout << "=== Bubble Sort (Fixed) ===" << endl;

    int count = readNumbers(numbers);
    bubbleSort(numbers, count);
    printArray(numbers, count);

    return 0;
}

/*
 * Summary of bugs:
 *
 * BUG #1 (readNumbers): for (int i = 1; i <= count; i++)
 *   - Should be: for (int i = 0; i < count; i++)
 *   - Arrays are 0-indexed!
 *
 * BUG #2 (bubbleSort inner loop): j < size - 1
 *   - Should be: j < size - 1 - i
 *   - After each pass, one more element is in place
 *
 * BUG #3 (bubbleSort comparison): arr[j] < arr[j+1]
 *   - Should be: arr[j] > arr[j+1]
 *   - For ascending order, swap if left is greater than right
 *
 * BUG #4 (bubbleSort swap): Missing arr[j+1] = temp
 *   - A swap needs both assignments!
 *
 * BUG #5 (printArray): i <= size
 *   - Should be: i < size
 *   - Off-by-one error accessing past array end
 */
