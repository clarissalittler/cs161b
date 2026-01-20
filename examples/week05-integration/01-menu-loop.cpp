/*
 * 01-menu-loop.cpp
 * A simple menu-driven loop.
 */

#include <iostream>
using namespace std;

void printMenu() {
    cout << "=== Counter Menu ===" << endl;
    cout << "1. Increment" << endl;
    cout << "2. Show value" << endl;
    cout << "3. Quit" << endl;
    cout << "Choice: ";
}

int main() {
    int counter = 0;
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                counter++;
                cout << "Counter incremented." << endl;
                break;
            case 2:
                cout << "Counter = " << counter << endl;
                break;
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
        cout << endl;
    } while (choice != 3);

    return 0;
}
