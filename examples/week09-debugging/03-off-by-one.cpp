/*
 * 03-off-by-one.cpp
 * A classic off-by-one error (and the fix).
 */

#include <iostream>
using namespace std;

void fillArray(int arr[], int size) {
    // Correct loop uses <, not <=
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }
}

int main() {
    int data[5];
    fillArray(data, 5);

    cout << "Data: ";
    for (int i = 0; i < 5; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
