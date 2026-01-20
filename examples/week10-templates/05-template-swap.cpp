/*
 * 05-template-swap.cpp
 * Swapping values with a template.
 */

#include <iostream>
#include <string>
using namespace std;

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5;
    int y = 9;
    mySwap(x, y);
    cout << "x=" << x << ", y=" << y << endl;

    string first = "left";
    string second = "right";
    mySwap(first, second);
    cout << "first=" << first << ", second=" << second << endl;

    return 0;
}
