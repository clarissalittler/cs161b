/*
 * 03-arrays-of-structs.cpp
 * Combining the power of arrays and structs.
 *
 * Instead of parallel arrays like:
 *   string names[10];
 *   int ages[10];
 *   double gpas[10];
 *
 * We can have one array of structs where each element
 * contains all the data for one entity.
 */

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int id;
    double gpa;
};

// Print a single student
void printStudent(const Student& s) {
    cout << s.name << " (#" << s.id << ") - GPA: " << s.gpa << endl;
}

// Find student with highest GPA
// Returns the INDEX of that student
int findTopStudent(Student students[], int count) {
    int topIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].gpa > students[topIndex].gpa) {
            topIndex = i;
        }
    }
    return topIndex;
}

// Calculate average GPA
double averageGpa(Student students[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].gpa;
    }
    return sum / count;
}

int main() {
    const int CLASS_SIZE = 5;

    // === Creating an array of structs ===
    cout << "=== Class Roster ===" << endl;

    Student roster[CLASS_SIZE] = {
        {"Alice", 1001, 3.8},
        {"Bob", 1002, 3.2},
        {"Carol", 1003, 3.9},
        {"Dave", 1004, 2.7},
        {"Eve", 1005, 3.5}
    };

    // Print all students
    for (int i = 0; i < CLASS_SIZE; i++) {
        printStudent(roster[i]);
    }
    cout << endl;

    // === Accessing specific students ===
    cout << "=== Accessing individuals ===" << endl;
    cout << "First student: " << roster[0].name << endl;
    cout << "Third student's GPA: " << roster[2].gpa << endl;
    cout << endl;

    // === Modifying data ===
    cout << "=== After grade updates ===" << endl;
    roster[1].gpa = 3.4;  // Bob improved!
    roster[3].gpa = 3.0;  // Dave too!
    cout << "Bob's new GPA: " << roster[1].gpa << endl;
    cout << "Dave's new GPA: " << roster[3].gpa << endl;
    cout << endl;

    // === Using helper functions ===
    cout << "=== Class statistics ===" << endl;
    int topIdx = findTopStudent(roster, CLASS_SIZE);
    cout << "Top student: " << roster[topIdx].name;
    cout << " with GPA " << roster[topIdx].gpa << endl;
    cout << "Class average GPA: " << averageGpa(roster, CLASS_SIZE) << endl;
    cout << endl;

    // === Sorting by GPA (simple bubble sort) ===
    cout << "=== Sorted by GPA (highest first) ===" << endl;

    // Bubble sort - swap whole structs!
    for (int i = 0; i < CLASS_SIZE - 1; i++) {
        for (int j = 0; j < CLASS_SIZE - 1 - i; j++) {
            if (roster[j].gpa < roster[j + 1].gpa) {
                // Swap the entire structs
                Student temp = roster[j];
                roster[j] = roster[j + 1];
                roster[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < CLASS_SIZE; i++) {
        cout << (i + 1) << ". ";
        printStudent(roster[i]);
    }
    cout << endl;

    // === Why this is better than parallel arrays ===
    cout << "=== The beauty of structs ===" << endl;
    cout << "Notice how the sort moved entire students as units." << endl;
    cout << "With parallel arrays, you'd have to remember to swap" << endl;
    cout << "names[j], ids[j], AND gpas[j] - easy to mess up!" << endl;

    return 0;
}

/*
 * Design tip:
 *
 * When you find yourself with multiple arrays that are "parallel"
 * (index i in each array refers to the same entity), it's a sign
 * you should probably use a struct instead.
 *
 * Structs make your code:
 * - Easier to understand (data is grouped logically)
 * - Easier to modify (add a field in one place)
 * - Less error-prone (can't accidentally use wrong index)
 * - Easier to pass to functions (one parameter instead of many)
 */
