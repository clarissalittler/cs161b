/*
 * 07-function-pointers.cpp
 * Function pointers (a bit advanced).
 */

#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int apply(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

int main() {
    cout << "Function pointers are a bit advanced, but useful." << endl;

    int (*op)(int, int) = add;
    cout << "add: " << apply(3, 4, op) << endl;

    op = multiply;
    cout << "multiply: " << apply(3, 4, op) << endl;

    return 0;
}
