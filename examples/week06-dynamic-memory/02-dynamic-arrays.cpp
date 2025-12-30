/*
 * 02-dynamic-arrays.cpp
 * Arrays whose size is determined at runtime.
 *
 * new[] allocates an array
 * delete[] frees an array
 *
 * Note: delete[] is different from delete!
 */

#include <iostream>
using namespace std;

// Function that returns a dynamically allocated array
// Caller is responsible for deleting it!
int* createArray(int size, int defaultValue) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = defaultValue;
    }
    return arr;
}

int main() {
    // ========================================
    // BASIC DYNAMIC ARRAY
    // ========================================

    cout << "=== Dynamic array basics ===" << endl;

    int size;
    cout << "How many numbers do you want to store? ";
    cin >> size;

    // Allocate an array of the requested size
    int* numbers = new int[size];

    // Fill it with some values
    for (int i = 0; i < size; i++) {
        numbers[i] = (i + 1) * 10;
    }

    // Print the array
    cout << "Array contents: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Don't forget: delete[] for arrays!
    delete[] numbers;
    numbers = nullptr;

    cout << endl;

    // ========================================
    // ARRAY FROM USER INPUT
    // ========================================

    cout << "=== Array from user input ===" << endl;

    int count;
    cout << "How many scores? ";
    cin >> count;

    double* scores = new double[count];

    // Read the scores
    for (int i = 0; i < count; i++) {
        cout << "Score " << (i + 1) << ": ";
        cin >> scores[i];
    }

    // Calculate average
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += scores[i];
    }
    double average = sum / count;

    cout << "Average: " << average << endl;

    delete[] scores;
    scores = nullptr;

    cout << endl;

    // ========================================
    // RETURNING DYNAMIC ARRAYS FROM FUNCTIONS
    // ========================================

    cout << "=== Returning arrays from functions ===" << endl;

    int* myArray = createArray(5, 42);

    cout << "Array from function: ";
    for (int i = 0; i < 5; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // WE are responsible for deleting what createArray allocated
    delete[] myArray;
    myArray = nullptr;

    cout << endl;

    // ========================================
    // COMMON MISTAKES
    // ========================================

    cout << "=== Dangerous patterns (don't do these!) ===" << endl;

    // MISTAKE 1: Using delete instead of delete[]
    // int* arr = new int[10];
    // delete arr;  // WRONG! Should be delete[] arr;

    // MISTAKE 2: Accessing after delete
    // int* arr = new int[10];
    // delete[] arr;
    // arr[0] = 5;  // DANGER: arr is now invalid!

    // MISTAKE 3: Losing the pointer before deleting
    // int* arr = new int[10];
    // arr = nullptr;  // Now we can never delete the array!
    // delete[] arr;   // Does nothing - arr is nullptr

    cout << "(See comments in code for examples of what NOT to do)" << endl;

    return 0;
}

/*
 * Remember:
 *
 * new int       -> delete
 * new int[n]    -> delete[]
 *
 * Mixing them up is undefined behavior!
 *
 * When returning a dynamic array from a function:
 * - The caller becomes responsible for deleting it
 * - Document this in comments!
 * - Better: use std::vector (Week 10)
 */
