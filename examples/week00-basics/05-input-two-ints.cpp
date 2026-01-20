/*
 * 05-input-two-ints.cpp
 * Reading two integers and using them.
 */

#include <iostream>
using namespace std;

int main() {
    int a;
    int b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Sum: " << (a + b) << endl;

    return 0;
}
