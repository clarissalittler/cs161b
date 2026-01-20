/*
 * 06-array-of-structs-search.cpp
 * Searching an array of structs by a field.
 */

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int id;
};

int findById(const Student students[], int count, int targetId) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == targetId) {
            return i;
        }
    }
    return -1;
}

int main() {
    Student roster[3] = {
        {"Alice", 101},
        {"Bob", 202},
        {"Carol", 303}
    };

    int target = 202;
    int index = findById(roster, 3, target);

    if (index != -1) {
        cout << "Found: " << roster[index].name << endl;
    } else {
        cout << "ID not found." << endl;
    }

    return 0;
}
