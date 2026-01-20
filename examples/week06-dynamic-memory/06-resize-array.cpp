/*
 * 06-resize-array.cpp
 * Resizing a dynamic array by allocating a new one.
 */

#include <iostream>
using namespace std;

int* resizeArray(const int* oldArr, int oldSize, int newSize) {
    int* newArr = new int[newSize];
    int limit = (oldSize < newSize) ? oldSize : newSize;

    for (int i = 0; i < limit; i++) {
        newArr[i] = oldArr[i];
    }
    for (int i = limit; i < newSize; i++) {
        newArr[i] = 0;
    }

    return newArr;
}

int main() {
    int* data = new int[3]{1, 2, 3};

    int* bigger = resizeArray(data, 3, 5);
    delete[] data;
    data = bigger;

    cout << "Resized array: ";
    for (int i = 0; i < 5; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    delete[] data;
    return 0;
}
