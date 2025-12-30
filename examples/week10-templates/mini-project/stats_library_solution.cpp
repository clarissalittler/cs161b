/*
 * Mini-Project: Generic Statistics Library (Solution)
 */

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T minimum(const vector<T>& v) {
    if (v.empty()) {
        return T();
    }

    T minVal = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < minVal) {
            minVal = v[i];
        }
    }
    return minVal;
}

template <typename T>
T maximum(const vector<T>& v) {
    if (v.empty()) {
        return T();
    }

    T maxVal = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] > maxVal) {
            maxVal = v[i];
        }
    }
    return maxVal;
}

template <typename T>
T sum(const vector<T>& v) {
    T total = T();
    for (size_t i = 0; i < v.size(); i++) {
        total += v[i];
    }
    return total;
}

template <typename T>
double average(const vector<T>& v) {
    if (v.empty()) {
        return 0.0;
    }

    return static_cast<double>(sum(v)) / v.size();
}

template <typename T>
void printStats(const vector<T>& v) {
    if (v.empty()) {
        cout << "(empty vector)" << endl;
        return;
    }

    cout << "Min: " << minimum(v) << endl;
    cout << "Max: " << maximum(v) << endl;
    cout << "Sum: " << sum(v) << endl;
    cout << "Average: " << average(v) << endl;
}

void testIntegers() {
    cout << "=== Testing with integers ===" << endl;
    vector<int> integers = {1, 5, 3, 9, 2, 7, 4, 8, 6};

    cout << "Data: ";
    for (int n : integers) cout << n << " ";
    cout << endl;

    printStats(integers);
    cout << endl;

    cout << "Expected: Min=1, Max=9, Sum=45, Avg=5" << endl;
    cout << endl;
}

void testDoubles() {
    cout << "=== Testing with doubles ===" << endl;
    vector<double> doubles = {1.5, 2.5, 3.5, 4.5, 5.5};

    cout << "Data: ";
    for (double d : doubles) cout << d << " ";
    cout << endl;

    printStats(doubles);
    cout << endl;

    cout << "Expected: Min=1.5, Max=5.5, Sum=17.5, Avg=3.5" << endl;
    cout << endl;
}

void testSingleElement() {
    cout << "=== Testing with single element ===" << endl;
    vector<int> single = {42};

    printStats(single);
    cout << endl;

    cout << "Expected: Min=42, Max=42, Sum=42, Avg=42" << endl;
    cout << endl;
}

void testEmpty() {
    cout << "=== Testing with empty vector ===" << endl;
    vector<int> empty;

    printStats(empty);
    cout << endl;
}

int main() {
    cout << "=== Generic Statistics Library ===" << endl << endl;

    testIntegers();
    testDoubles();
    testSingleElement();
    testEmpty();

    cout << "=== Interactive Mode ===" << endl;
    cout << "Enter numbers (negative to stop): " << endl;

    vector<double> userNumbers;
    double input;

    while (cin >> input && input >= 0) {
        userNumbers.push_back(input);
    }

    if (!userNumbers.empty()) {
        cout << endl << "Your statistics:" << endl;
        printStats(userNumbers);
    } else {
        cout << "No numbers entered." << endl;
    }

    return 0;
}
