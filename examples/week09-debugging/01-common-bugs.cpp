/*
 * 01-common-bugs.cpp
 * Examples of common bugs and how to fix them.
 *
 * Each section shows a BUGGY version and a FIXED version.
 */

#include <iostream>
#include <cstring>
using namespace std;

// ============================================================
// BUG 1: OFF-BY-ONE ERROR
// ============================================================

void offByOneBuggy(int arr[], int size) {
    // BUG: <= instead of <
    // Accesses arr[size], which is out of bounds!
    for (int i = 0; i <= size; i++) {
        arr[i] = i * 10;
    }
}

void offByOneFixed(int arr[], int size) {
    // FIXED: Use < instead of <=
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }
}

// ============================================================
// BUG 2: UNINITIALIZED VARIABLE
// ============================================================

int sumBuggy(int arr[], int size) {
    int sum;  // BUG: Not initialized! Contains garbage.
    for (int i = 0; i < size; i++) {
        sum += arr[i];  // Adding to garbage
    }
    return sum;
}

int sumFixed(int arr[], int size) {
    int sum = 0;  // FIXED: Initialize to 0
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// ============================================================
// BUG 3: ASSIGNMENT VS COMPARISON
// ============================================================

bool checkValueBuggy(int x) {
    // BUG: = is assignment, not comparison!
    // This assigns 5 to x, then evaluates to true (non-zero)
    if ((x = 5)) {
        return true;
    }
    return false;
}

bool checkValueFixed(int x) {
    // FIXED: Use == for comparison
    if (x == 5) {
        return true;
    }
    return false;
}

// ============================================================
// BUG 4: INFINITE LOOP
// ============================================================

void infiniteLoopBuggy() {
    // BUG: Forgot to increment i
    // while (i < 10) {
    //     cout << i << endl;
    //     // i++ missing!
    // }
    cout << "(Skipping infinite loop example)" << endl;
}

void infiniteLoopFixed() {
    int i = 0;
    // FIXED: Increment i
    while (i < 10) {
        cout << i << " ";
        i++;
    }
    cout << endl;
}

// ============================================================
// BUG 5: NULL POINTER DEREFERENCE
// ============================================================

struct Node {
    int data;
    Node* next;
};

void printListBuggy(Node* head) {
    // BUG: What if head is nullptr?
    // cout << head->data;  // CRASH!
    cout << "(Skipping null pointer crash)" << endl;
}

void printListFixed(Node* head) {
    // FIXED: Check before dereferencing
    if (head != nullptr) {
        cout << head->data << endl;
    } else {
        cout << "(list is empty)" << endl;
    }
}

// ============================================================
// BUG 6: WRONG LOOP BOUNDS
// ============================================================

void copyStringBuggy(char* dest, const char* src) {
    int len = strlen(src);
    // BUG: Doesn't copy the null terminator!
    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
    // dest is not null-terminated!
}

void copyStringFixed(char* dest, const char* src) {
    int len = strlen(src);
    // FIXED: Include null terminator (use <= or add after loop)
    for (int i = 0; i <= len; i++) {
        dest[i] = src[i];  // Copies '\0' when i == len
    }
}

// ============================================================
// BUG 7: RETURN VALUE IGNORED
// ============================================================

void findMaxBuggy(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    // BUG: Function doesn't return the max!
    // (Compiler might warn about this)
}

int findMaxFixed(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;  // FIXED: Return the result
}

// ============================================================
// BUG 8: DANGLING POINTER
// ============================================================

int* danglingBuggy() {
    int* value = new int(42);
    delete value;
    return value;  // BUG: value now dangles
}

int* danglingFixed() {
    int* value = new int(42);
    return value;  // FIXED: Use dynamic memory (caller must delete)
}

// ============================================================
// DEMONSTRATION
// ============================================================

int main() {
    cout << "=== Common Bug Examples ===" << endl << endl;

    // Bug 1: Off-by-one
    cout << "1. Off-by-one error:" << endl;
    int arr[5];
    // offByOneBuggy(arr, 5);  // Would write past array!
    offByOneFixed(arr, 5);
    cout << "   Fixed version runs safely." << endl << endl;

    // Bug 2: Uninitialized
    cout << "2. Uninitialized variable:" << endl;
    int data[] = {1, 2, 3, 4, 5};
    cout << "   Buggy sum: (unpredictable)" << endl;
    cout << "   Fixed sum: " << sumFixed(data, 5) << endl << endl;

    // Bug 3: Assignment vs comparison
    cout << "3. Assignment vs comparison:" << endl;
    cout << "   checkValueBuggy(3): " << checkValueBuggy(3) << " (wrong!)" << endl;
    cout << "   checkValueFixed(3): " << checkValueFixed(3) << " (correct)" << endl << endl;

    // Bug 4: Infinite loop
    cout << "4. Infinite loop:" << endl;
    infiniteLoopBuggy();
    cout << "   Fixed version: ";
    infiniteLoopFixed();
    cout << endl;

    // Bug 5: Null pointer
    cout << "5. Null pointer:" << endl;
    printListBuggy(nullptr);
    printListFixed(nullptr);
    cout << endl;

    // Bug 6: String copy
    cout << "6. String copy without null terminator:" << endl;
    char dest[20];
    copyStringFixed(dest, "Hello");
    cout << "   Fixed copy: " << dest << endl << endl;

    // Bug 7: Return value
    cout << "7. Missing return value:" << endl;
    int nums[] = {3, 7, 2, 9, 4};
    cout << "   Max: " << findMaxFixed(nums, 5) << endl << endl;

    // Bug 8: Dangling pointer
    cout << "8. Dangling pointer:" << endl;
    int* ptr = danglingFixed();
    cout << "   Fixed version: " << *ptr << endl;
    delete ptr;

    cout << endl << "=== Debugging tips ===" << endl;
    cout << "1. Enable warnings: g++ -Wall -Wextra" << endl;
    cout << "2. Initialize all variables" << endl;
    cout << "3. Check pointers before dereferencing" << endl;
    cout << "4. Double-check loop bounds" << endl;
    cout << "5. Use == for comparison, not =" << endl;

    return 0;
}
