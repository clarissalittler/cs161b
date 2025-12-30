/*
 * 02-writing-files.cpp
 * Creating and writing to files.
 *
 * ofstream works like cout, but writes to a file instead of the screen.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // === Creating a new file ===
    cout << "=== Writing to a new file ===" << endl;

    ofstream outFile;
    outFile.open("output.txt");

    if (!outFile) {
        cerr << "Error: Could not create output.txt" << endl;
        return 1;
    }

    // Write to the file just like cout
    outFile << "Hello, file!" << endl;
    outFile << "This is line 2." << endl;
    outFile << "The answer is " << 42 << endl;

    // You can write multiple things on one line
    outFile << "Name: " << "Alice" << ", Age: " << 25 << endl;

    outFile.close();

    cout << "Created output.txt with 4 lines." << endl;
    cout << endl;

    // === Appending to an existing file ===
    cout << "=== Appending to a file ===" << endl;

    // ios::app means "append mode" - add to end instead of overwriting
    ofstream appendFile("output.txt", ios::app);

    if (!appendFile) {
        cerr << "Error: Could not open output.txt for appending" << endl;
        return 1;
    }

    appendFile << "--- Appended content ---" << endl;
    appendFile << "This line was added later." << endl;

    appendFile.close();

    cout << "Appended 2 more lines to output.txt" << endl;
    cout << endl;

    // === Verify by reading it back ===
    cout << "=== Contents of output.txt ===" << endl;

    ifstream checkFile("output.txt");
    string line;
    while (getline(checkFile, line)) {
        cout << line << endl;
    }
    checkFile.close();

    cout << endl;

    // === Writing structured data ===
    cout << "=== Writing structured data ===" << endl;

    ofstream dataFile("students.txt");

    // Write a "header" comment
    dataFile << "# Student data: name age gpa" << endl;

    // Write some records
    dataFile << "Alice 20 3.8" << endl;
    dataFile << "Bob 22 3.2" << endl;
    dataFile << "Carol 19 3.9" << endl;

    dataFile.close();

    cout << "Created students.txt with structured data." << endl;
    cout << endl;

    // === Using different file formats ===
    cout << "=== CSV format example ===" << endl;

    ofstream csvFile("data.csv");

    // Header row
    csvFile << "Name,Age,Score" << endl;

    // Data rows
    csvFile << "Alice,20,95" << endl;
    csvFile << "Bob,22,87" << endl;
    csvFile << "Carol,19,92" << endl;

    csvFile.close();

    cout << "Created data.csv - can be opened in Excel!" << endl;

    return 0;
}

/*
 * Key points:
 *
 * 1. ofstream for writing (output file stream)
 *
 * 2. By default, opening a file for writing OVERWRITES it
 *
 * 3. Use ios::app to append instead of overwrite:
 *    ofstream file("log.txt", ios::app);
 *
 * 4. << works exactly like cout
 *
 * 5. endl flushes the buffer to disk (ensures data is written)
 *
 * 6. Choose a format that makes reading easy:
 *    - Space-separated for simple data
 *    - CSV for spreadsheet compatibility
 *    - Custom delimiters for complex data
 */
