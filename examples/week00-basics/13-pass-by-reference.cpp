/*
 * 13-pass-by-reference.cpp
 * Pass by value vs. pass by reference.
 *
 * The & symbol in a parameter declaration means "pass by reference" -
 * the function gets the actual variable, not a copy.
 */

#include <iostream>
using namespace std;

// ============================================================
// PASS BY VALUE: The function gets a COPY
// Changes inside the function don't affect the original
// ============================================================

void tryToDouble(int x) {
    x = x * 2;  // Only changes the local copy
    cout << "  Inside tryToDouble: x = " << x << endl;
}

// ============================================================
// PASS BY REFERENCE: The function gets the ORIGINAL
// Changes persist after the function returns
// ============================================================

void actuallyDouble(int& x) {
    x = x * 2;  // Changes the original variable
    cout << "  Inside actuallyDouble: x = " << x << endl;
}

// ============================================================
// "RETURNING" MULTIPLE VALUES via reference parameters
// C++ functions can only return one thing, but reference
// parameters let you "return" additional values
// ============================================================

void divideWithRemainder(int dividend, int divisor, int& quotient, int& remainder) {
    quotient = dividend / divisor;
    remainder = dividend % divisor;
}

// ============================================================
// ARRAYS are always passed by reference (sort of)
// When you pass an array, you're really passing a pointer
// ============================================================

void doubleAll(int arr[], int size) {
    // This DOES modify the original array
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

int main() {
    // === Pass by value ===
    cout << "=== Pass by Value ===" << endl;
    int num = 5;
    cout << "Before tryToDouble: num = " << num << endl;
    tryToDouble(num);
    cout << "After tryToDouble: num = " << num << " (unchanged!)" << endl;
    cout << endl;

    // === Pass by reference ===
    cout << "=== Pass by Reference ===" << endl;
    num = 5;
    cout << "Before actuallyDouble: num = " << num << endl;
    actuallyDouble(num);
    cout << "After actuallyDouble: num = " << num << " (changed!)" << endl;
    cout << endl;

    // === Multiple "return" values ===
    cout << "=== Multiple Return Values ===" << endl;
    int q, r;
    divideWithRemainder(17, 5, q, r);
    cout << "17 / 5 = " << q << " remainder " << r << endl;
    cout << endl;

    // === Arrays are always modifiable ===
    cout << "=== Arrays ===" << endl;
    int values[] = {1, 2, 3, 4, 5};
    cout << "Before doubleAll: ";
    for (int i = 0; i < 5; i++) cout << values[i] << " ";
    cout << endl;

    doubleAll(values, 5);

    cout << "After doubleAll: ";
    for (int i = 0; i < 5; i++) cout << values[i] << " ";
    cout << endl;

    return 0;
}

/*
 * When to use what:
 *
 * PASS BY VALUE (just the type name):
 *   void foo(int x)
 *   - When the function only needs to read the value
 *   - When the type is small (int, char, bool, double, pointers)
 *   - When you WANT a copy (to modify without affecting original)
 *
 * PASS BY REFERENCE (with &):
 *   void foo(int& x)
 *   - When the function needs to modify the original
 *   - When "returning" multiple values
 *
 * Arrays are passed as pointers, so changes in a function
 * affect the original array.
 */
