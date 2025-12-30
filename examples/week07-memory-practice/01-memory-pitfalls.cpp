/*
 * 01-memory-pitfalls.cpp
 * Common memory mistakes - demonstrated safely with explanations.
 *
 * DO NOT copy these anti-patterns into your code!
 * They're here so you can recognize and avoid them.
 */

#include <iostream>
using namespace std;

// ============================================================
// PITFALL 1: MEMORY LEAK
// ============================================================

void demonstrateLeak() {
    cout << "=== Memory Leak ===" << endl;

    // BAD: This function leaks memory
    // We allocate but never delete
    int* leaked = new int[100];
    leaked[0] = 42;
    cout << "Allocated 100 integers, never freed them." << endl;
    cout << "Memory is now orphaned - we can't access or free it." << endl;

    // In real code, this is BAD because:
    // - Memory accumulates over time
    // - Long-running programs eventually exhaust RAM
    // - Even short programs should clean up

    // GOOD version would be:
    int* notLeaked = new int[100];
    notLeaked[0] = 42;
    delete[] notLeaked;  // Clean up!
    cout << "Properly allocated and freed 100 integers." << endl;
    cout << endl;
}

// ============================================================
// PITFALL 2: LEAK ON EARLY RETURN
// ============================================================

bool demonstrateEarlyReturnLeak(bool triggerError) {
    cout << "=== Leak on Early Return ===" << endl;

    int* data = new int[50];
    data[0] = 1;

    if (triggerError) {
        cout << "Error condition triggered!" << endl;
        // BAD: We return without freeing data
        // return false;  // LEAK!

        // GOOD: Free before returning
        delete[] data;
        return false;
    }

    // Normal path
    cout << "Normal processing complete." << endl;
    delete[] data;
    return true;
}

// ============================================================
// PITFALL 3: DANGLING POINTER
// ============================================================

void demonstrateDanglingPointer() {
    cout << "=== Dangling Pointer ===" << endl;

    int* ptr = new int(42);
    cout << "Before delete: *ptr = " << *ptr << endl;

    delete ptr;
    // ptr is now "dangling" - it points to freed memory

    // BAD: Using ptr after delete
    // cout << *ptr << endl;  // UNDEFINED BEHAVIOR!

    // The memory might still contain 42, or garbage, or crash
    cout << "After delete: ptr still holds address " << ptr << endl;
    cout << "But that memory is no longer ours to use!" << endl;

    // GOOD: Set to nullptr after delete
    ptr = nullptr;
    cout << "After nulling: ptr = " << ptr << endl;

    // Now we can safely check before using
    if (ptr != nullptr) {
        cout << *ptr << endl;
    } else {
        cout << "ptr is null, won't dereference." << endl;
    }
    cout << endl;
}

// ============================================================
// PITFALL 4: DOUBLE FREE
// ============================================================

void demonstrateDoubleFree() {
    cout << "=== Double Free ===" << endl;

    int* ptr = new int(42);
    cout << "Allocated integer." << endl;

    delete ptr;
    cout << "First delete - OK." << endl;

    // BAD: Deleting again
    // delete ptr;  // CRASH or CORRUPTION!

    // GOOD: Set to nullptr, then delete is safe
    ptr = nullptr;
    delete ptr;  // delete nullptr does nothing - safe!
    cout << "Delete nullptr - safe (does nothing)." << endl;
    cout << endl;
}

// ============================================================
// PITFALL 5: MISMATCHED NEW/DELETE
// ============================================================

void demonstrateMismatch() {
    cout << "=== Mismatched new/delete ===" << endl;

    // new with delete - OK
    int* single = new int(42);
    delete single;
    cout << "new int + delete - correct." << endl;

    // new[] with delete[] - OK
    int* array = new int[10];
    delete[] array;
    cout << "new int[10] + delete[] - correct." << endl;

    // BAD combinations (don't do these!):
    // int* arr = new int[10];
    // delete arr;  // WRONG! Should be delete[]

    // int* single = new int(42);
    // delete[] single;  // WRONG! Should be delete

    cout << "Mismatched pairs cause undefined behavior!" << endl;
    cout << endl;
}

// ============================================================
// PITFALL 6: RETURNING STACK ADDRESS
// ============================================================

// BAD: Returns pointer to local variable
/*
int* badFunction() {
    int local = 42;
    return &local;  // local disappears when function returns!
}
*/

// GOOD: Returns dynamically allocated memory
int* goodFunction() {
    int* result = new int(42);
    return result;  // Caller must delete this!
}

void demonstrateStackReturn() {
    cout << "=== Returning Stack Address ===" << endl;

    // BAD version would crash or give garbage:
    // int* bad = badFunction();
    // cout << *bad << endl;  // UNDEFINED!

    // GOOD version:
    int* good = goodFunction();
    cout << "goodFunction returned: " << *good << endl;
    delete good;  // Caller's responsibility
    cout << "Caller freed the memory." << endl;
    cout << endl;
}

int main() {
    cout << "=== Memory Pitfalls Demonstration ===" << endl << endl;

    demonstrateLeak();
    demonstrateEarlyReturnLeak(true);
    cout << endl;
    demonstrateDanglingPointer();
    demonstrateDoubleFree();
    demonstrateMismatch();
    demonstrateStackReturn();

    cout << "=== End of Demonstration ===" << endl;
    cout << "Run this program with valgrind to see the leak!" << endl;
    cout << "  valgrind ./01-memory-pitfalls" << endl;

    return 0;
}
