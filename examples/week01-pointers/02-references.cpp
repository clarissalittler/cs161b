/*
 * 02-references.cpp
 * References: the friendlier cousin of pointers.
 *
 * A reference is like an alias - another name for an existing variable.
 * Unlike pointers:
 * - You don't need * to use them
 * - They can never be null
 * - They can't be changed to refer to something else
 */

#include <iostream>
using namespace std;

// This function gets a COPY of the argument
// Changing n here doesn't affect the original
void doubleByCopy(int n) {
    n = n * 2;
    cout << "Inside doubleByCopy: n = " << n << endl;
}

// This function gets a REFERENCE to the argument
// The & means "refer to the original, don't copy"
void doubleByReference(int& n) {
    n = n * 2;
    cout << "Inside doubleByReference: n = " << n << endl;
}

// Classic example: swapping two values
// Without references (or pointers), this is impossible!
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    // === Basic reference usage ===
    cout << "=== References as aliases ===" << endl;
    int x = 42;
    int& ref = x;  // ref is now another name for x

    cout << "x = " << x << endl;
    cout << "ref = " << ref << endl;

    ref = 100;  // Change through the reference
    cout << "After ref = 100:" << endl;
    cout << "x = " << x << endl;  // x changed too!
    cout << endl;

    // === Pass by copy vs. pass by reference ===
    cout << "=== Pass by copy ===" << endl;
    int value = 5;
    cout << "Before doubleByCopy: value = " << value << endl;
    doubleByCopy(value);
    cout << "After doubleByCopy: value = " << value << endl;  // Unchanged!
    cout << endl;

    cout << "=== Pass by reference ===" << endl;
    cout << "Before doubleByReference: value = " << value << endl;
    doubleByReference(value);
    cout << "After doubleByReference: value = " << value << endl;  // Changed!
    cout << endl;

    // === The swap example ===
    cout << "=== Swapping values ===" << endl;
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;
    cout << endl;

    // === When to use references ===
    cout << "=== When to use references ===" << endl;
    cout << "1. When you want to modify the original variable" << endl;
    cout << "2. When passing large objects (to avoid copying)" << endl;
    cout << "3. When you don't need to 'repoint' like you can with pointers" << endl;

    return 0;
}

/*
 * References vs. Pointers:
 *
 * Use references when you can (they're simpler and safer).
 * Use pointers when you must (for arrays, dynamic memory, or when
 * you need to change what you're pointing to).
 *
 * In modern C++, you'll often see const references for function
 * parameters when you want to avoid copies but don't need to modify:
 *
 *     void printName(const string& name) { ... }
 *
 * This says "I'll refer to the original, but I promise not to change it."
 */
