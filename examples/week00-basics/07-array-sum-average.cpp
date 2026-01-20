/*
 * 07-array-sum-average.cpp
 * Summing an array and computing an average.
 */

#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int scores[SIZE] = {80, 90, 75, 88, 95};
    int sum = 0;

    for (int i = 0; i < SIZE; i++) {
        sum += scores[i];
    }

    double average = static_cast<double>(sum) / SIZE;

    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;

    return 0;
}
