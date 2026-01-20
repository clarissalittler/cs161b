/*
 * 05-read-lines.cpp
 * Reading a file line by line with getline.
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

    string line;
    int lineCount = 0;
    while (getline(inFile, line)) {
        cout << line << endl;
        lineCount++;
    }

    cout << "Lines read: " << lineCount << endl;
    inFile.close();

    return 0;
}
