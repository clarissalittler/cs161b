/*
 * 01-reading-files.cpp
 * Different ways to read data from files.
 *
 * ifstream works like cin, but reads from a file instead of the keyboard.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // === Opening a file ===
    cout << "=== Opening and reading a file ===" << endl;

    ifstream inFile;
    inFile.open("data/sample.txt");

    // Always check if the file opened successfully!
    if (!inFile) {
        cerr << "Error: Could not open data/sample.txt" << endl;
        cerr << "Make sure you're running from the week04-file-io directory." << endl;
        return 1;
    }

    cout << "File opened successfully!" << endl << endl;

    // === Reading word by word ===
    cout << "=== Reading word by word ===" << endl;

    string word;
    int wordCount = 0;

    // >> skips whitespace and reads one "word" at a time
    while (inFile >> word) {
        cout << "Word " << (wordCount + 1) << ": " << word << endl;
        wordCount++;
    }
    cout << "Total words: " << wordCount << endl << endl;

    // === Important: reset the file to read again ===
    inFile.clear();              // Clear any error flags
    inFile.seekg(0);             // Go back to the beginning

    // === Reading line by line ===
    cout << "=== Reading line by line ===" << endl;

    string line;
    int lineCount = 0;

    while (getline(inFile, line)) {
        lineCount++;
        cout << "Line " << lineCount << ": " << line << endl;
    }
    cout << "Total lines: " << lineCount << endl << endl;

    // === Don't forget to close! ===
    inFile.close();

    // === Reading numbers ===
    cout << "=== Reading numbers from a file ===" << endl;

    ifstream numFile("data/numbers.txt");
    if (!numFile) {
        cerr << "Could not open data/numbers.txt" << endl;
        return 1;
    }

    int number;
    int sum = 0;
    int count = 0;

    while (numFile >> number) {
        cout << "Read: " << number << endl;
        sum += number;
        count++;
    }

    cout << "Sum: " << sum << endl;
    cout << "Average: " << (double)sum / count << endl;

    numFile.close();

    return 0;
}

/*
 * Key points:
 *
 * 1. #include <fstream> for file streams
 *
 * 2. ifstream for reading (input file stream)
 *
 * 3. Always check if open succeeded: if (!inFile) { ... }
 *
 * 4. >> reads whitespace-delimited tokens (words, numbers)
 *    getline() reads whole lines
 *
 * 5. The reading loop naturally stops at end-of-file
 *
 * 6. To read a file again, clear() and seekg(0)
 *
 * 7. close() when you're done (or let destructor handle it)
 */
