/*
 * Mini-Project: Memory-Safe Dynamic Strings
 *
 * Implement a set of functions for safely handling
 * dynamically-allocated C-strings.
 *
 * Focus on:
 * - No memory leaks
 * - No dangling pointers
 * - Safe handling of edge cases
 *
 * Test with valgrind!
 */

#include <iostream>
#include <cstring>
using namespace std;

// TODO: Implement these functions

// Allocate a string buffer of given capacity
// Returns nullptr if capacity <= 0
// Initializes to empty string (just null terminator)
char* createString(int capacity) {
    if (capacity <= 0) return nullptr;

    // TODO: Allocate capacity bytes
    // Set first character to '\0'

    return nullptr;
}

// Free a string and set pointer to nullptr
// Safe to call with nullptr
void freeString(char*& str) {
    // TODO: Check if not null, delete, set to null

}

// Create a copy of src
// Returns nullptr if src is nullptr
// Caller must free the returned string
char* copyString(const char* src) {
    if (src == nullptr) return nullptr;

    // TODO: Calculate length, allocate, copy

    return nullptr;
}

// Concatenate two strings into a new string
// Handles nullptr inputs (treats as empty string)
// Caller must free the returned string
char* concatenate(const char* a, const char* b) {
    // TODO: Handle nullptr cases
    // Calculate total length needed
    // Allocate new string
    // Copy a, then append b

    return nullptr;
}

// Resize a string buffer
// If str is nullptr, creates a new string of newCapacity
// If newCapacity is smaller, truncates the string
// Preserves contents up to newCapacity-1
void resizeString(char*& str, int newCapacity) {
    if (newCapacity <= 0) {
        freeString(str);
        return;
    }

    // TODO: Create new buffer
    // Copy old contents (if any)
    // Free old buffer
    // Update str to point to new buffer

}

// ============================================================
// TEST FUNCTIONS
// ============================================================

void testCreateAndFree() {
    cout << "=== Test createString/freeString ===" << endl;

    char* s1 = createString(10);
    if (s1 != nullptr) {
        cout << "Created string of capacity 10" << endl;
        cout << "Length: " << strlen(s1) << " (should be 0)" << endl;

        strcpy(s1, "Hello");
        cout << "After strcpy: \"" << s1 << "\"" << endl;

        freeString(s1);
        cout << "After free: s1 = " << (s1 == nullptr ? "nullptr" : "NOT null") << endl;
    }

    // Edge case: zero capacity
    char* s2 = createString(0);
    cout << "createString(0) returns: " << (s2 == nullptr ? "nullptr" : "NOT null") << endl;

    // Safe to free nullptr
    freeString(s2);
    cout << endl;
}

void testCopyString() {
    cout << "=== Test copyString ===" << endl;

    const char* original = "Hello, World!";
    char* copy = copyString(original);

    if (copy != nullptr) {
        cout << "Original: \"" << original << "\"" << endl;
        cout << "Copy: \"" << copy << "\"" << endl;
        cout << "Same address? " << (original == copy ? "YES (bad!)" : "NO (good!)") << endl;
        freeString(copy);
    }

    // Edge case: null input
    char* nullCopy = copyString(nullptr);
    cout << "copyString(nullptr) returns: " << (nullCopy == nullptr ? "nullptr" : "NOT null") << endl;
    cout << endl;
}

void testConcatenate() {
    cout << "=== Test concatenate ===" << endl;

    char* result = concatenate("Hello, ", "World!");
    if (result != nullptr) {
        cout << "concatenate(\"Hello, \", \"World!\") = \"" << result << "\"" << endl;
        freeString(result);
    }

    // Edge cases
    result = concatenate(nullptr, "test");
    if (result != nullptr) {
        cout << "concatenate(nullptr, \"test\") = \"" << result << "\"" << endl;
        freeString(result);
    }

    result = concatenate("test", nullptr);
    if (result != nullptr) {
        cout << "concatenate(\"test\", nullptr) = \"" << result << "\"" << endl;
        freeString(result);
    }

    result = concatenate(nullptr, nullptr);
    cout << "concatenate(nullptr, nullptr) = " << (result == nullptr ? "nullptr" : "\"" + string(result) + "\"") << endl;
    freeString(result);
    cout << endl;
}

void testResize() {
    cout << "=== Test resizeString ===" << endl;

    char* s = createString(10);
    if (s != nullptr) {
        strcpy(s, "Hello");
        cout << "Initial: \"" << s << "\" (capacity 10)" << endl;

        resizeString(s, 20);
        if (s != nullptr) {
            cout << "After resize to 20: \"" << s << "\"" << endl;

            strcat(s, ", World!");
            cout << "After append: \"" << s << "\"" << endl;
        }

        resizeString(s, 5);
        if (s != nullptr) {
            cout << "After resize to 5: \"" << s << "\" (truncated)" << endl;
        }

        freeString(s);
    }

    // Edge case: resize from nullptr
    char* nullStr = nullptr;
    resizeString(nullStr, 10);
    if (nullStr != nullptr) {
        cout << "resizeString(nullptr, 10) created new string" << endl;
        freeString(nullStr);
    }
    cout << endl;
}

int main() {
    cout << "=== Safe String Functions Test ===" << endl << endl;

    testCreateAndFree();
    testCopyString();
    testConcatenate();
    testResize();

    cout << "=== All tests complete ===" << endl;
    cout << "Run with valgrind to check for memory leaks:" << endl;
    cout << "  valgrind ./safe_strings" << endl;

    return 0;
}

/*
 * Implementation hints:
 *
 * createString:
 *   char* str = new char[capacity];
 *   str[0] = '\0';
 *   return str;
 *
 * freeString:
 *   if (str != nullptr) {
 *       delete[] str;
 *       str = nullptr;
 *   }
 *
 * copyString:
 *   int len = strlen(src) + 1;
 *   char* copy = new char[len];
 *   strcpy(copy, src);
 *   return copy;
 *
 * concatenate:
 *   int lenA = (a != nullptr) ? strlen(a) : 0;
 *   int lenB = (b != nullptr) ? strlen(b) : 0;
 *   char* result = new char[lenA + lenB + 1];
 *   result[0] = '\0';
 *   if (a != nullptr) strcpy(result, a);
 *   if (b != nullptr) strcat(result, b);
 *   return result;
 *
 * resizeString:
 *   char* newStr = new char[newCapacity];
 *   newStr[0] = '\0';
 *   if (str != nullptr) {
 *       strncpy(newStr, str, newCapacity - 1);
 *       newStr[newCapacity - 1] = '\0';
 *       delete[] str;
 *   }
 *   str = newStr;
 */
