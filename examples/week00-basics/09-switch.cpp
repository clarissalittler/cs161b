/*
 * 09-switch.cpp
 * Using switch with integer choices.
 */

#include <iostream>
using namespace std;

int main() {
    int choice;
    cout << "Enter a menu option (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Option 1 selected" << endl;
            break;
        case 2:
            cout << "Option 2 selected" << endl;
            break;
        case 3:
            cout << "Option 3 selected" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }

    return 0;
}
