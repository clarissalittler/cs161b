/*
 * 03-pointer-arithmetic.cpp
 * The secret connection between arrays and pointers.
 *
 * Key insight: arr[i] is just shorthand for *(arr + i)
 *
 * When you add to a pointer, it moves by the SIZE of the thing
 * it points to, not by one byte.
 */

#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    // The array name, used without brackets, gives you a pointer
    // to the first element
    cout << "=== Array name as pointer ===" << endl;
    cout << "arr (the address): " << arr << endl;
    cout << "&arr[0] (same thing): " << &arr[0] << endl;
    cout << "*arr (first element): " << *arr << endl;
    cout << endl;

    // Pointer arithmetic: adding to a pointer moves it
    cout << "=== Pointer arithmetic ===" << endl;
    int* p = arr;  // p points to arr[0]

    cout << "p points to:     " << *p << " (arr[0])" << endl;
    cout << "p + 1 points to: " << *(p + 1) << " (arr[1])" << endl;
    cout << "p + 2 points to: " << *(p + 2) << " (arr[2])" << endl;
    cout << "p + 4 points to: " << *(p + 4) << " (arr[4])" << endl;
    cout << endl;

    // Brackets are just syntactic sugar!
    cout << "=== Brackets vs. pointer arithmetic ===" << endl;
    cout << "arr[2] = " << arr[2] << endl;
    cout << "*(arr + 2) = " << *(arr + 2) << endl;
    cout << "(They're the same thing!)" << endl;
    cout << endl;

    // We can loop through an array with a pointer
    cout << "=== Looping with a pointer ===" << endl;
    for (int* ptr = arr; ptr < arr + 5; ptr++) {
        cout << *ptr << " ";
    }
    cout << endl << endl;

    // How does this work? Let's see the addresses
    cout << "=== Addresses in the array ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] is at address " << &arr[i];
        cout << " and holds " << arr[i] << endl;
    }
    cout << endl;
    cout << "Notice the addresses differ by " << sizeof(int) << " bytes each time." << endl;
    cout << "(That's sizeof(int) on this system.)" << endl;
    cout << endl;

    // A quirk: you can even write it backwards
    cout << "=== A weird but legal syntax ===" << endl;
    cout << "2[arr] = " << 2[arr] << endl;  // Same as arr[2]!
    cout << "(Because a[b] means *(a+b), and addition is commutative...)" << endl;
    cout << "Please don't actually write code like this." << endl;

    return 0;
}

/*
 * Why does this matter?
 *
 * Understanding the array-pointer connection helps you:
 * 1. Understand how arrays work in function parameters
 * 2. Work with dynamic memory (coming in Week 6)
 * 3. Read and write code that uses pointer iteration
 * 4. Debug array-related bugs
 *
 * When you pass an array to a function, you're really passing
 * a pointer to its first element. That's why:
 * - Changes to array elements inside the function affect the original
 * - The function can't tell how big the array is without you passing the size
 */
