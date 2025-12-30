/*
 * 03-parsing.cpp
 * Reading and parsing structured data from files.
 *
 * Real data often has structure: records with multiple fields,
 * different data types, maybe some special formatting.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

int main() {
    // === Reading structured data (space-separated) ===
    cout << "=== Reading student records ===" << endl;

    ifstream inFile("data/students.txt");
    if (!inFile) {
        cerr << "Could not open data/students.txt" << endl;
        return 1;
    }

    Student students[100];
    int count = 0;

    // Read fields directly into struct members
    // This works because fields are separated by whitespace
    while (inFile >> students[count].name
                  >> students[count].age
                  >> students[count].gpa) {
        count++;
    }
    inFile.close();

    cout << "Read " << count << " students:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "  " << students[i].name
             << ", age " << students[i].age
             << ", GPA " << students[i].gpa << endl;
    }
    cout << endl;

    // === Reading with headers/comments ===
    cout << "=== Handling comments ===" << endl;

    ifstream dataFile("data/products.txt");
    if (!dataFile) {
        cerr << "Could not open data/products.txt" << endl;
        return 1;
    }

    string line;
    while (getline(dataFile, line)) {
        // Skip empty lines and comments
        if (line.empty() || line[0] == '#') {
            continue;
        }

        cout << "Data line: " << line << endl;
    }
    dataFile.close();
    cout << endl;

    // === Reading line-by-line then parsing ===
    cout << "=== Reading lines with spaces ===" << endl;

    // Sometimes you need getline first, then parse the line
    // Example: names might have spaces

    ifstream namesFile("data/fullnames.txt");
    if (!namesFile) {
        cerr << "Could not open data/fullnames.txt" << endl;
        return 1;
    }

    string fullName;
    int score;

    // File format: each line is "Full Name|score"
    while (getline(namesFile, fullName, '|')) {  // Read until |
        namesFile >> score;                        // Read the number
        namesFile.ignore();                        // Skip the newline

        cout << fullName << " scored " << score << endl;
    }
    namesFile.close();
    cout << endl;

    // === Mixed formats ===
    cout << "=== Mixed reading techniques ===" << endl;

    ifstream mixedFile("data/inventory.txt");
    if (!mixedFile) {
        cerr << "Could not open data/inventory.txt" << endl;
        return 1;
    }

    string productName;
    int quantity;
    double price;

    // File format: ProductName quantity price
    // But product name can have spaces, so we read line by line
    while (getline(mixedFile, line)) {
        if (line.empty()) continue;

        // Find the last two spaces (quantity and price are at the end)
        size_t lastSpace = line.rfind(' ');
        size_t secondLastSpace = line.rfind(' ', lastSpace - 1);

        productName = line.substr(0, secondLastSpace);
        quantity = stoi(line.substr(secondLastSpace + 1, lastSpace - secondLastSpace - 1));
        price = stod(line.substr(lastSpace + 1));

        cout << "Product: " << productName
             << " | Qty: " << quantity
             << " | Price: $" << price << endl;
    }
    mixedFile.close();

    return 0;
}

/*
 * Parsing strategies:
 *
 * 1. SIMPLE WHITESPACE-SEPARATED
 *    file >> word1 >> word2 >> number;
 *    Easy, but words can't contain spaces.
 *
 * 2. LINE BY LINE
 *    getline(file, line);
 *    Good for when you need the whole line, or for processing.
 *
 * 3. CUSTOM DELIMITER
 *    getline(file, field, ',');  // Read until comma
 *    Good for CSV or other delimited formats.
 *
 * 4. SKIP COMMENTS/HEADERS
 *    if (line[0] == '#') continue;
 *    Common pattern for data files with metadata.
 *
 * 5. STRING PARSING
 *    Use substr(), find(), stoi(), stod() to extract fields from a line.
 *    Most flexible but most complex.
 *
 * Choose the simplest approach that works for your data format!
 */
