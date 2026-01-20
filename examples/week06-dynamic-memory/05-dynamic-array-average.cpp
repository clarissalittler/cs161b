/*
 * 05-dynamic-array-average.cpp
 * Using a dynamic array to compute an average.
 */

#include <iostream>
using namespace std;

int main() {
    int count;
    cout << "How many scores? ";
    cin >> count;

    double* scores = new double[count];

    for (int i = 0; i < count; i++) {
        cout << "Score " << (i + 1) << ": ";
        cin >> scores[i];
    }

    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += scores[i];
    }

    if (count > 0) {
        cout << "Average: " << (sum / count) << endl;
    }

    delete[] scores;
    return 0;
}
