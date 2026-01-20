/*
 * 11-function-prototypes.cpp
 * Declaring functions before main.
 */

#include <iostream>
using namespace std;

int add(int a, int b);
void printDivider();

int main() {
    printDivider();
    cout << "3 + 4 = " << add(3, 4) << endl;
    printDivider();

    return 0;
}

int add(int a, int b) {
    return a + b;
}

void printDivider() {
    cout << "----------------" << endl;
}
