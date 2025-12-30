/*
 * Mini-Project: Grade Calculator
 *
 * A grade calculation program with well-designed functions.
 * Focus on clean decomposition - each function should have one job.
 */

#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 50;

struct Student {
    string name;
    double score;
};

// TODO: Implement these functions

// Convert a numeric score to a letter grade
// 90-100 = A, 80-89 = B, 70-79 = C, 60-69 = D, below 60 = F
char getLetterGrade(double score) {
    // TODO: Implement this

    return 'F';
}

// Calculate the average of an array of scores
double calculateAverage(const double scores[], int count) {
    // TODO: Implement this

    return 0.0;
}

// Find the highest score in the array
double findHighest(const double scores[], int count) {
    // TODO: Implement this

    return 0.0;
}

// Find the lowest score in the array
double findLowest(const double scores[], int count) {
    // TODO: Implement this

    return 0.0;
}

// Print the grade report for all students
void printReport(const Student students[], int count) {
    cout << endl;
    cout << "=== Grade Report ===" << endl;

    // TODO: Print each student's name, score, and letter grade
    // Format: "Alice: 92 (A)"



    cout << endl;
}

// Print class statistics
void printStatistics(const double scores[], int count) {
    cout << "Class Statistics:" << endl;

    // TODO: Print average, highest, and lowest
    // Use the helper functions you implemented above



}

int main() {
    Student students[MAX_STUDENTS];
    double scores[MAX_STUDENTS];  // Parallel array for easier statistics
    int count;

    // Get number of students
    cout << "Enter number of students: ";
    cin >> count;
    cin.ignore();

    if (count < 1 || count > MAX_STUDENTS) {
        cout << "Invalid number of students." << endl;
        return 1;
    }

    // Read student data
    for (int i = 0; i < count; i++) {
        cout << "Student " << (i + 1) << " name: ";
        getline(cin, students[i].name);

        cout << "Student " << (i + 1) << " score: ";
        cin >> students[i].score;
        cin.ignore();

        scores[i] = students[i].score;  // Copy to scores array
    }

    // Print reports
    printReport(students, count);
    printStatistics(scores, count);

    return 0;
}

/*
 * Hints:
 *
 * getLetterGrade:
 *   if (score >= 90) return 'A';
 *   else if (score >= 80) return 'B';
 *   ... etc.
 *
 * calculateAverage:
 *   Sum all scores, divide by count.
 *   Remember to handle count == 0!
 *
 * findHighest/findLowest:
 *   Start with the first element, compare with each other element.
 *
 * printReport:
 *   for (int i = 0; i < count; i++) {
 *       cout << students[i].name << ": " << students[i].score;
 *       cout << " (" << getLetterGrade(students[i].score) << ")" << endl;
 *   }
 *
 * Test with:
 *   Alice: 92 -> A
 *   Bob: 78 -> C
 *   Carol: 85 -> B
 *   Average should be 85.0, Highest 92, Lowest 78
 */
