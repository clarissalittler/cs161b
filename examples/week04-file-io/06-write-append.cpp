/*
 * 06-write-append.cpp
 * Appending lines to an existing file.
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream logFile("log.txt", ios::app);

    if (!logFile) {
        cerr << "Could not open log.txt" << endl;
        return 1;
    }

    logFile << "Log entry appended." << endl;
    logFile.close();

    cout << "Appended one line to log.txt" << endl;
    return 0;
}
