/*
 * 03-stl-intro.cpp
 * Introduction to the Standard Template Library.
 *
 * The STL provides:
 * - Containers (vector, list, map, set, ...)
 * - Iterators (generalized pointers)
 * - Algorithms (sort, find, transform, ...)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    cout << "=== STL Introduction ===" << endl << endl;

    // ============================================================
    // VECTOR BASICS
    // ============================================================

    cout << "=== std::vector basics ===" << endl;

    // Create an empty vector
    vector<int> numbers;

    // Add elements
    numbers.push_back(5);
    numbers.push_back(2);
    numbers.push_back(8);
    numbers.push_back(1);
    numbers.push_back(9);

    // Size and capacity
    cout << "Size: " << numbers.size() << endl;
    cout << "Empty? " << (numbers.empty() ? "yes" : "no") << endl;

    // Access elements
    cout << "First: " << numbers[0] << endl;
    cout << "Last: " << numbers.back() << endl;
    cout << "At index 2: " << numbers.at(2) << endl;  // Bounds-checked

    // Print all elements
    cout << "All elements: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl << endl;

    // ============================================================
    // RANGE-BASED FOR LOOP (C++11)
    // ============================================================

    cout << "=== Range-based for loop ===" << endl;

    // Much cleaner than index-based loop
    cout << "Elements: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    // Modifying elements (use reference)
    for (int& n : numbers) {
        n *= 2;  // Double each element
    }
    cout << "Doubled: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl << endl;

    // ============================================================
    // ITERATORS
    // ============================================================

    cout << "=== Iterators ===" << endl;

    // Iterator is like a generalized pointer
    // begin() points to first element
    // end() points PAST the last element

    cout << "Using iterators: ";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";  // Dereference like a pointer
    }
    cout << endl;

    // With auto (C++11)
    cout << "Using auto: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // ============================================================
    // ALGORITHMS
    // ============================================================

    cout << "=== Algorithms ===" << endl;

    // Restore original values (halve them)
    for (int& n : numbers) n /= 2;

    // Sort
    cout << "Before sort: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    sort(numbers.begin(), numbers.end());

    cout << "After sort:  ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Reverse
    reverse(numbers.begin(), numbers.end());
    cout << "Reversed:    ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Find
    auto it = find(numbers.begin(), numbers.end(), 5);
    if (it != numbers.end()) {
        cout << "Found 5 at position " << (it - numbers.begin()) << endl;
    }

    // Count
    numbers.push_back(5);  // Add another 5
    int count5 = count(numbers.begin(), numbers.end(), 5);
    cout << "Count of 5s: " << count5 << endl;

    // Min and Max
    auto minIt = min_element(numbers.begin(), numbers.end());
    auto maxIt = max_element(numbers.begin(), numbers.end());
    cout << "Min: " << *minIt << ", Max: " << *maxIt << endl;
    cout << endl;

    // ============================================================
    // VECTOR OF STRINGS
    // ============================================================

    cout << "=== Vector of strings ===" << endl;

    vector<string> words = {"banana", "apple", "cherry", "date"};

    cout << "Original: ";
    for (const string& w : words) cout << w << " ";
    cout << endl;

    sort(words.begin(), words.end());

    cout << "Sorted:   ";
    for (const string& w : words) cout << w << " ";
    cout << endl << endl;

    // ============================================================
    // VECTOR OPERATIONS
    // ============================================================

    cout << "=== More vector operations ===" << endl;

    vector<int> v = {1, 2, 3, 4, 5};

    // Remove last element
    v.pop_back();
    cout << "After pop_back: ";
    for (int n : v) cout << n << " ";
    cout << endl;

    // Insert at position (before element at that position)
    v.insert(v.begin() + 2, 99);
    cout << "After insert at 2: ";
    for (int n : v) cout << n << " ";
    cout << endl;

    // Erase at position
    v.erase(v.begin() + 2);
    cout << "After erase at 2: ";
    for (int n : v) cout << n << " ";
    cout << endl;

    // Clear all
    v.clear();
    cout << "After clear: size = " << v.size() << endl;

    return 0;
}

/*
 * Key STL concepts:
 *
 * 1. CONTAINERS store collections of elements
 *    - vector: dynamic array
 *    - list: doubly-linked list
 *    - map: key-value pairs
 *    - set: unique sorted elements
 *
 * 2. ITERATORS provide uniform access to containers
 *    - begin() and end()
 *    - Dereference with *
 *    - Increment with ++
 *
 * 3. ALGORITHMS work with iterators
 *    - sort, find, count, reverse, etc.
 *    - Work with any container that provides iterators
 *
 * Why use STL?
 * - Less code to write
 * - Fewer bugs (tested, optimized)
 * - More readable
 * - Consistent interface
 */
