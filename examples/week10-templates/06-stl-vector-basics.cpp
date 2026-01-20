/*
 * 06-stl-vector-basics.cpp
 * Basic std::vector usage.
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;

    numbers.push_back(4);
    numbers.push_back(7);
    numbers.push_back(1);

    cout << "Size: " << numbers.size() << endl;
    cout << "Values: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
