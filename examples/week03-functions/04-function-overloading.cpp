/*
 * 04-function-overloading.cpp
 * Same function name, different parameter lists.
 */

#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << "add(3, 4) = " << add(3, 4) << endl;
    cout << "add(2.5, 1.75) = " << add(2.5, 1.75) << endl;
    cout << "add(1, 2, 3) = " << add(1, 2, 3) << endl;

    return 0;
}
