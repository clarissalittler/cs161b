/*
 * 06-while-sentinel.cpp
 * Using a sentinel value to end a while loop.
 */

#include <iostream>
using namespace std;

int main() {
    int value;
    int count = 0;
    int sum = 0;

    cout << "Enter numbers (-1 to stop): ";
    cin >> value;

    while (value != -1) {
        sum += value;
        count++;
        cout << "Enter another (-1 to stop): ";
        cin >> value;
    }

    if (count > 0) {
        double average = static_cast<double>(sum) / count;
        cout << "Count: " << count << endl;
        cout << "Average: " << average << endl;
    } else {
        cout << "No numbers entered." << endl;
    }

    return 0;
}
