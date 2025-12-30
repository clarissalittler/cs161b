/*
 * 01-pointer-basics.cpp
 * Your first look at pointers.
 *
 * Key ideas:
 * - Every variable lives at an address in memory
 * - & gives you the address of a variable
 * - * follows a pointer to get the value at that address
 * - int* means "pointer to an int"
 */

#include <iostream>
using namespace std;

int main() {
    // A regular integer variable
    int x = 42;

    // A pointer to an integer
    // We initialize it with the address of x
    int* p = &x;

    cout << "=== The basics ===" << endl;
    cout << "x is: " << x << endl;
    cout << "Address of x (&x): " << &x << endl;
    cout << "p holds: " << p << endl;           // Same address!
    cout << "Value at that address (*p): " << *p << endl;  // 42
    cout << endl;

    // Here's the magic: we can change x through the pointer
    cout << "=== Changing values through pointers ===" << endl;
    *p = 100;  // "Put 100 in the cubbyhole that p points to"
    cout << "After *p = 100:" << endl;
    cout << "x is now: " << x << endl;  // x changed!
    cout << "*p is: " << *p << endl;     // Same value, same cubbyhole
    cout << endl;

    // We can have multiple pointers to the same variable
    cout << "=== Multiple pointers ===" << endl;
    int* q = &x;  // Another pointer to x
    *q = 200;
    cout << "After *q = 200:" << endl;
    cout << "x: " << x << ", *p: " << *p << ", *q: " << *q << endl;
    cout << "(All the same, because they all refer to x)" << endl;
    cout << endl;

    // We can also change which variable a pointer points to
    cout << "=== Repointing ===" << endl;
    int y = 999;
    p = &y;  // Now p points to y instead of x
    cout << "Now p points to y" << endl;
    cout << "*p: " << *p << endl;  // 999
    cout << "x is still: " << x << endl;  // Unchanged
    cout << endl;

    // A common source of confusion: declaration vs. use
    cout << "=== The * symbol does double duty ===" << endl;
    cout << "In 'int* p', the * means 'p is a pointer'" << endl;
    cout << "In '*p = 100', the * means 'follow the pointer'" << endl;
    cout << "Same symbol, different meanings. C++ is fun like that." << endl;

    return 0;
}

/*
 * Mental model:
 *
 * Think of memory as a hotel. Each room has a number (address) and
 * can hold a guest (value). A regular variable is like "Room 42 has Bob."
 * A pointer is like a note that says "Go to Room 42."
 *
 * If you have the note, you can find Bob. And if you change who's in
 * Room 42, anyone with a note pointing there will find the new guest.
 */
