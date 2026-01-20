/*
 * 05-nullptr-check.cpp
 * Checking for nullptr before dereferencing.
 */

#include <iostream>
using namespace std;

int main() {
    int* ptr = nullptr;

    if (ptr == nullptr) {
        cout << "ptr is nullptr" << endl;
    }

    int value = 42;
    ptr = &value;

    if (ptr != nullptr) {
        cout << "Value: " << *ptr << endl;
    }

    return 0;
}
