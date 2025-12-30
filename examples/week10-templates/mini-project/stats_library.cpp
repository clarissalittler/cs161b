/*
 * Mini-Project: Generic Statistics Library
 *
 * Implement template functions that work with any numeric type.
 * Use std::vector for the data.
 */

#include <iostream>
#include <vector>
using namespace std;

// TODO: Implement these template functions

// Find the minimum element in a vector
template <typename T>
T minimum(const vector<T>& v) {
    if (v.empty()) {
        return T();  // Default value for empty vector
    }

    // TODO: Find and return the smallest element

    return v[0];  // Placeholder
}

// Find the maximum element in a vector
template <typename T>
T maximum(const vector<T>& v) {
    if (v.empty()) {
        return T();
    }

    // TODO: Find and return the largest element

    return v[0];  // Placeholder
}

// Calculate the sum of all elements
template <typename T>
T sum(const vector<T>& v) {
    // TODO: Sum all elements and return

    return T();  // Placeholder
}

// Calculate the average (always returns double)
template <typename T>
double average(const vector<T>& v) {
    if (v.empty()) {
        return 0.0;
    }

    // TODO: Calculate and return the average
    // Hint: Cast the sum to double before dividing

    return 0.0;  // Placeholder
}

// Print all statistics for a vector
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

// ============================================================
// TEST CODE
// ============================================================

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

    // Interactive mode
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

/*
 * Implementation hints:
 *
 * minimum:
 *   T min = v[0];
 *   for (size_t i = 1; i < v.size(); i++) {
 *       if (v[i] < min) min = v[i];
 *   }
 *   return min;
 *
 * maximum:
 *   T max = v[0];
 *   for (size_t i = 1; i < v.size(); i++) {
 *       if (v[i] > max) max = v[i];
 *   }
 *   return max;
 *
 * sum:
 *   T total = T();  // Initialize to 0 (or empty)
 *   for (const T& elem : v) {
 *       total = total + elem;  // Or total += elem
 *   }
 *   return total;
 *
 * average:
 *   return static_cast<double>(sum(v)) / v.size();
 *
 * Or use STL algorithms:
 *   #include <algorithm>
 *   #include <numeric>
 *   min: *min_element(v.begin(), v.end())
 *   max: *max_element(v.begin(), v.end())
 *   sum: accumulate(v.begin(), v.end(), T())
 */
