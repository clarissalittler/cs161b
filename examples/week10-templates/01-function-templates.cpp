/*
 * 01-function-templates.cpp
 * Writing generic functions that work with any type.
 *
 * Templates let you write a function once and use it with
 * int, double, string, or any type that supports the operations used.
 */

#include <iostream>
#include <string>
using namespace std;

// ============================================================
// BASIC TEMPLATE FUNCTION
// ============================================================

// Template version of max
// T is a placeholder for any type
template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

// Template version of min
template <typename T>
T myMin(T a, T b) {
    return (a < b) ? a : b;
}

// ============================================================
// TEMPLATE WITH MULTIPLE TYPE PARAMETERS
// ============================================================

// Print a pair of potentially different types
template <typename T, typename U>
void printPair(T first, U second) {
    cout << "(" << first << ", " << second << ")" << endl;
}

// ============================================================
// TEMPLATE WITH ARRAYS
// ============================================================

// Print any array of any type
template <typename T>
void printArray(T arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Find element in array (returns index or -1)
template <typename T>
int findElement(T arr[], int size, T target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// Sum array elements
template <typename T>
T sumArray(T arr[], int size) {
    T sum = T();  // Default initialization (0 for numbers)
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    return sum;
}

// ============================================================
// SWAP FUNCTION
// ============================================================

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// ============================================================
// DEMONSTRATION
// ============================================================

int main() {
    cout << "=== Function Templates ===" << endl << endl;

    // Basic templates with different types
    cout << "=== myMax with different types ===" << endl;
    cout << "myMax(3, 7) = " << myMax(3, 7) << endl;
    cout << "myMax(3.14, 2.71) = " << myMax(3.14, 2.71) << endl;
    cout << "myMax('a', 'z') = " << myMax('a', 'z') << endl;
    cout << "myMax(\"apple\", \"banana\") = " << myMax(string("apple"), string("banana")) << endl;
    cout << endl;

    // Multiple type parameters
    cout << "=== printPair with mixed types ===" << endl;
    printPair(42, "the answer");
    printPair(3.14, 'x');
    printPair("name", 100);
    cout << endl;

    // Array operations
    cout << "=== Template array functions ===" << endl;

    int intArr[] = {5, 2, 8, 1, 9};
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    string strArr[] = {"cat", "dog", "bird"};

    cout << "int array: ";
    printArray(intArr, 5);
    cout << "Sum: " << sumArray(intArr, 5) << endl;
    cout << "Find 8: index " << findElement(intArr, 5, 8) << endl;
    cout << endl;

    cout << "double array: ";
    printArray(doubleArr, 5);
    cout << "Sum: " << sumArray(doubleArr, 5) << endl;
    cout << endl;

    cout << "string array: ";
    printArray(strArr, 3);
    cout << "Find \"dog\": index " << findElement(strArr, 3, string("dog")) << endl;
    cout << endl;

    // Swap
    cout << "=== Template swap ===" << endl;
    int x = 10, y = 20;
    cout << "Before: x=" << x << ", y=" << y << endl;
    mySwap(x, y);
    cout << "After:  x=" << x << ", y=" << y << endl;

    string s1 = "hello", s2 = "world";
    cout << "Before: s1=" << s1 << ", s2=" << s2 << endl;
    mySwap(s1, s2);
    cout << "After:  s1=" << s1 << ", s2=" << s2 << endl;

    return 0;
}

/*
 * Key points:
 *
 * 1. template <typename T> introduces a type parameter T
 *
 * 2. The compiler generates specific versions for each type used
 *
 * 3. The type is usually inferred from arguments, but can be specified:
 *    myMax<double>(3, 5)
 *
 * 4. Templates work with any type that supports the operations used
 *    (comparison, arithmetic, etc.)
 *
 * 5. T() creates a default-initialized value (0 for numbers, empty for strings)
 */
