/*
 * 04-template-max.cpp
 * A minimal function template example.
 */

#include <iostream>
using namespace std;

template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max of 3 and 7: " << myMax(3, 7) << endl;
    cout << "Max of 2.5 and 1.2: " << myMax(2.5, 1.2) << endl;
    return 0;
}
