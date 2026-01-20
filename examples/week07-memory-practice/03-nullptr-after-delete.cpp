/*
 * 03-nullptr-after-delete.cpp
 * Setting pointers to nullptr after deleting.
 */

#include <iostream>
using namespace std;

int main() {
    int* ptr = new int(10);
    cout << "Value: " << *ptr << endl;

    delete ptr;
    ptr = nullptr;

    if (ptr == nullptr) {
        cout << "ptr is now nullptr" << endl;
    }

    return 0;
}
