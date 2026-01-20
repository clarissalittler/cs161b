/*
 * 05-return-values.cpp
 * Returning values from a function.
 */

#include <iostream>
using namespace std;

double average(int a, int b) {
    return (a + b) / 2.0;
}

int main() {
    int x = 10;
    int y = 14;

    double avg = average(x, y);
    cout << "Average: " << avg << endl;

    return 0;
}
