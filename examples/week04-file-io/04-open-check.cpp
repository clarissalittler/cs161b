/*
 * 04-open-check.cpp
 * Opening a file and checking for errors.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("data/sample.txt");

    if (!inFile) {
        cerr << "Could not open data/sample.txt" << endl;
        return 1;
    }

    string firstWord;
    if (inFile >> firstWord) {
        cout << "First word: " << firstWord << endl;
    }

    inFile.close();
    return 0;
}
