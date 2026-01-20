/*
 * 10-input-validation.cpp
 * Checking cin state and retrying until input is valid.
 */

#include <iostream>
using namespace std;

int main() {
    int value;

    cout << "Enter an integer from 1 to 10: ";
    while (!(cin >> value) || value < 1 || value > 10) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Try again (1-10): ";
    }

    cout << "You entered " << value << endl;
    return 0;
}
