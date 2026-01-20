/*
 * 04-cstrings.cpp
 * C-style strings: arrays of characters ending with '\0'.
 *
 * Before std::string existed, this was how we handled text.
 * You still need to understand it because:
 * - Lots of existing code uses it
 * - Some APIs require it
 * - It teaches you about memory and pointers
 */

#include <iostream>
#include <cstring>  // For strlen, strcpy, etc.
using namespace std;

int main() {
    // A C-string is just a char array with a null terminator
    cout << "=== C-string basics ===" << endl;

    char greeting[] = "Hello";  // Compiler adds the \0 for you

    // What's really in there?
    cout << "greeting says: " << greeting << endl;
    cout << "What's actually stored: ";
    for (int i = 0; i <= 5; i++) {  // Note: <= to include the \0
        if (greeting[i] == '\0') {
            cout << "'\\0' ";
        } else {
            cout << "'" << greeting[i] << "' ";
        }
    }
    cout << endl;
    cout << "That's 6 characters (including the null terminator)!" << endl;
    cout << endl;

    // strlen counts characters (not including the \0)
    cout << "=== strlen ===" << endl;
    cout << "strlen(greeting) = " << strlen(greeting) << endl;
    cout << "sizeof(greeting) = " << sizeof(greeting) << endl;
    cout << "(strlen counts chars; sizeof counts bytes including \\0)" << endl;
    cout << endl;

    // Be careful! If you forget the null terminator, bad things happen
    cout << "=== The importance of \\0 ===" << endl;
    char risky[5] = {'H', 'e', 'l', 'l', 'o'};  // No null terminator!
    // cout << risky << endl;  // DANGER: would read past the array!
    cout << "First char in risky: " << risky[0] << endl;
    cout << "We made a char array without \\0. Printing it would be dangerous!" << endl;
    cout << "strlen would wander through memory looking for a \\0 somewhere..." << endl;
    cout << endl;

    // You can use pointers to walk through a string
    cout << "=== Traversing with pointers ===" << endl;
    char* ptr = greeting;
    cout << "Characters in greeting: ";
    while (*ptr != '\0') {
        cout << *ptr << " ";
        ptr++;  // Move to next character
    }
    cout << endl << endl;

    // Copying strings
    cout << "=== Copying strings ===" << endl;
    char copy[20];  // Make sure it's big enough!
    strcpy(copy, greeting);  // Copy greeting into copy
    cout << "Original: " << greeting << endl;
    cout << "Copy: " << copy << endl;

    // Modifying the copy doesn't affect the original
    copy[0] = 'J';
    cout << "After changing copy[0]:" << endl;
    cout << "Original: " << greeting << endl;
    cout << "Copy: " << copy << endl;
    cout << endl;

    // Comparing strings
    cout << "=== Comparing strings ===" << endl;
    char a[] = "apple";
    char b[] = "banana";
    char c[] = "apple";
    const char* aPtr = a;
    const char* cPtr = c;

    // You can't use == to compare C-strings! It compares addresses.
    cout << "a == c? " << (aPtr == cPtr) << " (compares addresses, not content!)" << endl;
    cout << "strcmp(a, c) = " << strcmp(a, c) << " (0 means equal)" << endl;
    cout << "strcmp(a, b) = " << strcmp(a, b) << " (negative means a < b)" << endl;
    cout << "strcmp(b, a) = " << strcmp(b, a) << " (positive means b > a)" << endl;
    cout << endl;

    // String literals are stored in read-only memory
    cout << "=== String literals ===" << endl;
    const char* literal = "I am a literal";
    cout << literal << endl;
    cout << "String literals are read-only. Don't try to modify them!" << endl;
    // literal[0] = 'X';  // This would crash or cause undefined behavior!

    return 0;
}

/*
 * C-string gotchas:
 *
 * 1. Always make sure your destination is big enough for strcpy
 * 2. Always null-terminate if you're building a string manually
 * 3. Never compare with ==, use strcmp
 * 4. Never modify string literals
 *
 * Modern C++ alternative: std::string handles all of this for you.
 * But understanding C-strings helps you understand memory, and you'll
 * encounter them in older code and C libraries.
 */
