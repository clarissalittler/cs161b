/*
 * 04-uninitialized.cpp
 * Always initialize variables before use.
 */

#include <iostream>
using namespace std;

int sumFixed(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int values[4] = {1, 2, 3, 4};
    cout << "Sum: " << sumFixed(values, 4) << endl;
    return 0;
}
