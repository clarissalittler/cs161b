/*
 * 02-cleanup-patterns.cpp
 * Reliable patterns for managing dynamic memory.
 *
 * These patterns help prevent memory bugs:
 * 1. Initialize to nullptr
 * 2. Set to nullptr after delete
 * 3. Check before use
 * 4. Single owner principle
 * 5. Cleanup function pattern
 */

#include <iostream>
#include <cstring>
using namespace std;

// ============================================================
// PATTERN 1: SAFE ARRAY FUNCTIONS
// ============================================================

// Create a zeroed array
int* createIntArray(int size) {
    if (size <= 0) return nullptr;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
    return arr;
}

// Free array and set pointer to null (note the reference!)
void freeIntArray(int*& arr) {
    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }
}

void demonstrateSafeArray() {
    cout << "=== Safe Array Pattern ===" << endl;

    int* data = createIntArray(5);
    if (data == nullptr) {
        cout << "Failed to create array." << endl;
        return;
    }

    // Use the array
    for (int i = 0; i < 5; i++) {
        data[i] = i * 10;
        cout << data[i] << " ";
    }
    cout << endl;

    // Free it safely
    freeIntArray(data);

    // data is now nullptr
    cout << "After free: data = " << data << endl;

    // Double free is now safe
    freeIntArray(data);  // Does nothing, data is already null
    cout << "Double free attempt: no crash!" << endl;
    cout << endl;
}

// ============================================================
// PATTERN 2: STRUCT WITH CLEANUP
// ============================================================

struct DynamicArray {
    int* data;
    int size;
    int capacity;
};

DynamicArray createDynamicArray(int capacity) {
    DynamicArray arr;
    arr.data = new int[capacity];
    arr.size = 0;
    arr.capacity = capacity;
    return arr;
}

void freeDynamicArray(DynamicArray& arr) {
    if (arr.data != nullptr) {
        delete[] arr.data;
        arr.data = nullptr;
    }
    arr.size = 0;
    arr.capacity = 0;
}

void addElement(DynamicArray& arr, int value) {
    if (arr.size < arr.capacity && arr.data != nullptr) {
        arr.data[arr.size] = value;
        arr.size++;
    }
}

void printDynamicArray(const DynamicArray& arr) {
    cout << "[";
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i];
        if (i < arr.size - 1) cout << ", ";
    }
    cout << "] (size=" << arr.size << ", capacity=" << arr.capacity << ")" << endl;
}

void demonstrateStructCleanup() {
    cout << "=== Struct Cleanup Pattern ===" << endl;

    DynamicArray arr = createDynamicArray(10);

    addElement(arr, 10);
    addElement(arr, 20);
    addElement(arr, 30);

    printDynamicArray(arr);

    freeDynamicArray(arr);
    cout << "After cleanup: data = " << arr.data << endl;
    cout << endl;
}

// ============================================================
// PATTERN 3: SINGLE OWNER (Who deletes?)
// ============================================================

// This function CREATES memory - caller owns it
char* createGreeting(const char* name) {
    // Calculate needed size
    const char* prefix = "Hello, ";
    const char* suffix = "!";
    int len = strlen(prefix) + strlen(name) + strlen(suffix) + 1;

    // Allocate and build string
    char* result = new char[len];
    strcpy(result, prefix);
    strcat(result, name);
    strcat(result, suffix);

    return result;  // Caller must delete!
}

// This function USES memory - does NOT own it
void printString(const char* str) {
    // Just use it, don't delete
    cout << str << endl;
}

// This function MODIFIES but does not own
void uppercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

void demonstrateSingleOwner() {
    cout << "=== Single Owner Pattern ===" << endl;

    // We create, so we own and must delete
    char* greeting = createGreeting("World");
    cout << "Created: " << greeting << endl;

    // These functions borrow but don't own
    printString(greeting);  // Just uses it
    uppercase(greeting);    // Modifies but doesn't delete
    printString(greeting);

    // Owner cleans up
    delete[] greeting;
    greeting = nullptr;
    cout << "Owner cleaned up." << endl;
    cout << endl;
}

// ============================================================
// PATTERN 4: MULTIPLE EXIT POINTS
// ============================================================

int processWithCleanup(int input) {
    int* buffer = new int[100];
    int result = 0;

    // Instead of multiple returns, use a single exit point
    // This ensures cleanup always happens

    if (input < 0) {
        result = -1;
        // goto cleanup;  // Old-school C way
    } else if (input > 100) {
        result = -2;
    } else {
        // Normal processing
        for (int i = 0; i < input; i++) {
            buffer[i] = i * i;
            result += buffer[i];
        }
    }

    // Single cleanup point
    delete[] buffer;
    return result;
}

void demonstrateMultipleExits() {
    cout << "=== Single Exit Point Pattern ===" << endl;

    cout << "processWithCleanup(5) = " << processWithCleanup(5) << endl;
    cout << "processWithCleanup(-1) = " << processWithCleanup(-1) << endl;
    cout << "processWithCleanup(101) = " << processWithCleanup(101) << endl;
    cout << "All paths clean up properly!" << endl;
    cout << endl;
}

// ============================================================
// MAIN
// ============================================================

int main() {
    cout << "=== Memory Cleanup Patterns ===" << endl << endl;

    demonstrateSafeArray();
    demonstrateStructCleanup();
    demonstrateSingleOwner();
    demonstrateMultipleExits();

    cout << "=== All demonstrations complete ===" << endl;
    cout << "Run with valgrind to verify no leaks!" << endl;

    return 0;
}
