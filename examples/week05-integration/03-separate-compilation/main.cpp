/*
 * main.cpp
 * Uses functions defined in another .cpp file.
 */

#include <iostream>
#include "math_utils.h"
using namespace std;

int main() {
    int a;
    int b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Sum: " << add(a, b) << endl;
    cout << "Product: " << multiply(a, b) << endl;

    return 0;
}
