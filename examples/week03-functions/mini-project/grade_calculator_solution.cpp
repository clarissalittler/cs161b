/*
 * Mini-Project: Grade Calculator (Solution)
 */

#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 50;

struct Student {
    string name;
    double score;
};

char getLetterGrade(double score) {
    if (score >= 90) return 'A';
    if (score >= 80) return 'B';
    if (score >= 70) return 'C';
    if (score >= 60) return 'D';
    return 'F';
}

double calculateAverage(const double scores[], int count) {
    if (count <= 0) return 0.0;
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += scores[i];
    }
    return total / count;
}

double findHighest(const double scores[], int count) {
    if (count <= 0) return 0.0;
    double high = scores[0];
    for (int i = 1; i < count; i++) {
        if (scores[i] > high) {
            high = scores[i];
        }
    }
    return high;
}

double findLowest(const double scores[], int count) {
    if (count <= 0) return 0.0;
    double low = scores[0];
    for (int i = 1; i < count; i++) {
        if (scores[i] < low) {
            low = scores[i];
        }
    }
    return low;
}

void printReport(const Student students[], int count) {
    cout << endl;
    cout << "=== Grade Report ===" << endl;

    for (int i = 0; i < count; i++) {
        cout << students[i].name << ": " << students[i].score;
        cout << " (" << getLetterGrade(students[i].score) << ")" << endl;
    }

    cout << endl;
}

void printStatistics(const double scores[], int count) {
    cout << "Class Statistics:" << endl;
    cout << "Average: " << calculateAverage(scores, count) << endl;
    cout << "Highest: " << findHighest(scores, count) << endl;
    cout << "Lowest: " << findLowest(scores, count) << endl;
}

int main() {
    Student students[MAX_STUDENTS];
    double scores[MAX_STUDENTS];
    int count;

    cout << "Enter number of students: ";
    cin >> count;
    cin.ignore();

    if (count < 1 || count > MAX_STUDENTS) {
        cout << "Invalid number of students." << endl;
        return 1;
    }

    for (int i = 0; i < count; i++) {
        cout << "Student " << (i + 1) << " name: ";
        getline(cin, students[i].name);

        cout << "Student " << (i + 1) << " score: ";
        cin >> students[i].score;
        cin.ignore();

        scores[i] = students[i].score;
    }

    printReport(students, count);
    printStatistics(scores, count);

    return 0;
}
