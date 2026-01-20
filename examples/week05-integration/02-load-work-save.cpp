/*
 * 02-load-work-save.cpp
 * Load items from a file, update them, then save.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int loadItems(const string& filename, string items[], int maxItems) {
    ifstream inFile(filename.c_str());
    if (!inFile) {
        return 0;
    }

    int count = 0;
    while (count < maxItems && getline(inFile, items[count])) {
        if (!items[count].empty()) {
            count++;
        }
    }

    return count;
}

void saveItems(const string& filename, const string items[], int count) {
    ofstream outFile(filename.c_str());
    for (int i = 0; i < count; i++) {
        outFile << items[i] << endl;
    }
}

int main() {
    const int MAX = 5;
    string items[MAX];

    int count = loadItems("items.txt", items, MAX);

    if (count == 0) {
        items[0] = "Apples";
        items[1] = "Bread";
        count = 2;
    }

    if (count < MAX) {
        items[count] = "Milk";
        count++;
    }

    cout << "Current items:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "- " << items[i] << endl;
    }

    saveItems("items.txt", items, count);

    cout << "Saved to items.txt" << endl;
    return 0;
}
