/*
 * 07-pointer-iteration.cpp
 * Looping through an array with a pointer.
 */

#include <iostream>
using namespace std;

int main() {
    int numbers[4] = {10, 20, 30, 40};

    cout << "Values: ";
    for (int* p = numbers; p < numbers + 4; p++) {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}
