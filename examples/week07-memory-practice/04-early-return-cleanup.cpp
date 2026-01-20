/*
 * 04-early-return-cleanup.cpp
 * Cleaning up before returning early.
 */

#include <iostream>
using namespace std;

bool processData(bool failEarly) {
    int* data = new int[3]{1, 2, 3};

    if (failEarly) {
        delete[] data;
        return false;
    }

    cout << "Processing: ";
    for (int i = 0; i < 3; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    delete[] data;
    return true;
}

int main() {
    cout << "Early return path: " << (processData(true) ? "ok" : "failed") << endl;
    cout << "Normal path: " << (processData(false) ? "ok" : "failed") << endl;

    return 0;
}
