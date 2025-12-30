/*
 * 01-new-delete.cpp
 * Introduction to dynamic memory allocation.
 *
 * new: Request memory from the operating system
 * delete: Give it back when you're done
 */

#include <iostream>
using namespace std;

int main() {
    // ========================================
    // SINGLE VALUE ALLOCATION
    // ========================================

    cout << "=== Single value allocation ===" << endl;

    // Allocate space for one integer
    // new returns a pointer to the allocated memory
    int* ptr = new int;

    // Use the memory (through the pointer)
    *ptr = 42;
    cout << "Value: " << *ptr << endl;
    cout << "Address: " << ptr << endl;

    // Release the memory when done
    delete ptr;

    // Good practice: set to nullptr after delete
    ptr = nullptr;

    cout << endl;

    // ========================================
    // INITIALIZING DURING ALLOCATION
    // ========================================

    cout << "=== Initializing with new ===" << endl;

    // You can initialize the value directly
    int* answer = new int(42);
    double* pi = new double(3.14159);
    char* letter = new char('X');

    cout << "*answer = " << *answer << endl;
    cout << "*pi = " << *pi << endl;
    cout << "*letter = " << *letter << endl;

    // Clean up all three
    delete answer;
    delete pi;
    delete letter;

    // Set to nullptr
    answer = pi = nullptr;
    letter = nullptr;

    cout << endl;

    // ========================================
    // DYNAMIC STRUCT ALLOCATION
    // ========================================

    cout << "=== Dynamic structs ===" << endl;

    struct Point {
        int x;
        int y;
    };

    // Allocate a Point
    Point* p = new Point;
    p->x = 10;  // Arrow operator for pointer-to-struct
    p->y = 20;

    cout << "Point: (" << p->x << ", " << p->y << ")" << endl;

    delete p;
    p = nullptr;

    // Initialize during allocation (C++11 and later)
    Point* p2 = new Point{30, 40};
    cout << "Point2: (" << p2->x << ", " << p2->y << ")" << endl;

    delete p2;

    cout << endl;

    // ========================================
    // WHAT HAPPENS IF WE FORGET DELETE?
    // ========================================

    cout << "=== Memory leak demonstration ===" << endl;
    cout << "(This allocates memory but doesn't delete it)" << endl;

    for (int i = 0; i < 3; i++) {
        int* leaked = new int(i);
        cout << "Allocated: " << *leaked << " at " << leaked << endl;
        // Oops! No delete!
        // The memory is now unreachable - a memory leak
    }

    cout << "Those 3 integers are now leaked." << endl;
    cout << "(Small leak here, but imagine in a loop running millions of times...)" << endl;

    return 0;
}

/*
 * Key points:
 *
 * 1. new returns a pointer to allocated memory
 *
 * 2. delete frees that memory
 *
 * 3. Every new must have a matching delete
 *
 * 4. After delete, set the pointer to nullptr
 *
 * 5. Forgetting delete = memory leak
 *
 * 6. Using memory after delete = undefined behavior (dangerous!)
 *
 * 7. Arrow operator (p->member) is shorthand for (*p).member
 */
