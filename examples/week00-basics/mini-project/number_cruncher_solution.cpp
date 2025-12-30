/*
 * Mini-Project: Number Cruncher (Solution)
 */

#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    double numbers[MAX_SIZE];
    int count;

    cout << "How many numbers? ";
    cin >> count;

    if (count < 1 || count > MAX_SIZE) {
        cout << "Please enter a number between 1 and " << MAX_SIZE << endl;
        return 1;
    }

    for (int i = 0; i < count; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }

    double average = sum / count;

    double largest = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
    }

    double smallest = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }

    cout << endl;
    cout << "Results:" << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Largest: " << largest << endl;
    cout << "Smallest: " << smallest << endl;

    return 0;
}
