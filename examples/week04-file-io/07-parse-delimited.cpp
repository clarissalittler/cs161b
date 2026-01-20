/*
 * 07-parse-delimited.cpp
 * Parsing a file with a custom delimiter.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("data/fullnames.txt");
    if (!inFile) {
        cerr << "Could not open data/fullnames.txt" << endl;
        return 1;
    }

    string name;
    int score;

    while (getline(inFile, name, '|')) {
        if (!(inFile >> score)) {
            break;
        }
        inFile.ignore(1000, '\n');
        cout << name << " scored " << score << endl;
    }

    inFile.close();
    return 0;
}
