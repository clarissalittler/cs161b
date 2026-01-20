/*
 * 06-recursion-basics.cpp
 * Simple recursion with base cases.
 */

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int sumToN(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + sumToN(n - 1);
}

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    cout << n << "! = " << factorial(n) << endl;
    cout << "Sum 1.." << n << " = " << sumToN(n) << endl;

    return 0;
}
