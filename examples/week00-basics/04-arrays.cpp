/*
 * 04-arrays.cpp
 * Working with collections of values.
 *
 * An array is a block of memory holding multiple values of the same type.
 * Instead of score1, score2, score3... you use scores[0], scores[1], scores[2]...
 */

#include <iostream>
using namespace std;

int main() {
    // === DECLARING ARRAYS ===

    // An array of 5 integers, initialized with values
    int scores[5] = {85, 92, 78, 95, 88};

    // An array of 10 integers, all automatically set to 0
    int counts[10] = {0};

    // An array where the size comes from the initializer
    // (The compiler counts for you - this has 4 elements)
    string names[] = {"Alice", "Bob", "Carol", "Dave"};

    // === ACCESSING ELEMENTS ===

    cout << "=== Accessing array elements ===" << endl;
    cout << "First score: " << scores[0] << endl;   // Index 0 = first
    cout << "Third score: " << scores[2] << endl;   // Index 2 = third
    cout << "Last score: " << scores[4] << endl;    // Index 4 = fifth (last)
    cout << endl;

    // DANGER ZONE: What if you access scores[5]?
    // That's past the end of the array! C++ won't stop you, but Bad Things happen.
    // (Uncomment the next line if you want to see chaos. Or don't.)
    // cout << "Past the end: " << scores[5] << endl;

    // === LOOPING THROUGH ARRAYS ===

    cout << "=== All scores ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Score " << i << ": " << scores[i] << endl;
    }
    cout << endl;

    // === MODIFYING ARRAYS ===

    cout << "=== Adding 5 points to each score ===" << endl;
    for (int i = 0; i < 5; i++) {
        scores[i] = scores[i] + 5;  // Curved!
    }

    // Print them again to see the change
    for (int i = 0; i < 5; i++) {
        cout << "Score " << i << ": " << scores[i] << endl;
    }
    cout << endl;

    // === FINDING THINGS IN ARRAYS ===

    cout << "=== Finding the highest score ===" << endl;
    int highest = scores[0];  // Assume the first one is highest
    for (int i = 1; i < 5; i++) {  // Start at 1, we already have 0
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }
    cout << "Highest score: " << highest << endl;
    cout << endl;

    // === COMPUTING WITH ARRAYS ===

    cout << "=== Computing the average ===" << endl;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum = sum + scores[i];
    }
    double average = (double)sum / 5;  // Cast to double for decimal division
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;

    return 0;
}

/*
 * Things to ponder:
 *
 * 1. Why do we start at index 0 instead of 1?
 *    Historical reasons, mostly. It makes pointer arithmetic cleaner.
 *    You'll see why in Week 1.
 *
 * 2. Why can't we just ask an array how big it is?
 *    In C++, basic arrays don't know their own size. The size is just
 *    baked into how much memory was allocated. We'll see better options
 *    later (std::vector, for instance).
 *
 * 3. What's with the (double) in front of sum?
 *    That's a "cast" - it converts sum to a double before the division.
 *    Without it, 5/2 would give you 2, not 2.5. Integer division truncates!
 */
