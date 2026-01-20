/*
 * 06-pointer-swap.cpp
 * Swapping values using pointer parameters.
 */

#include <iostream>
using namespace std;

void swapInts(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 3;
    int y = 7;

    cout << "Before: x=" << x << ", y=" << y << endl;
    swapInts(&x, &y);
    cout << "After:  x=" << x << ", y=" << y << endl;

    return 0;
}
