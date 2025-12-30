/*
 * grade_book.cpp
 * A student grade management system.
 *
 * Another example of an integrated program combining
 * all the concepts from weeks 0-4.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// =============== DATA STRUCTURES ===============

const int MAX_STUDENTS = 50;
const int MAX_ASSIGNMENTS = 10;

struct Student {
    string name;
    int studentId;
    double scores[MAX_ASSIGNMENTS];
    int numScores;
};

const string FILENAME = "gradebook.dat";

// =============== FUNCTION PROTOTYPES ===============

// Core operations
int loadStudents(Student students[]);
void saveStudents(Student students[], int count);
void printMenu();

// Student management
void listStudents(Student students[], int count);
void addStudent(Student students[], int& count);
int findStudent(Student students[], int count, int id);

// Grade operations
void addGrade(Student students[], int count);
void viewGrades(Student students[], int count);

// Calculations and reports
double calculateAverage(const Student& s);
char getLetterGrade(double avg);
void classReport(Student students[], int count);

// =============== MAIN ===============

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = loadStudents(students);

    cout << "=== Grade Book ===" << endl;
    cout << "Loaded " << studentCount << " students." << endl << endl;

    int choice;
    do {
        printMenu();
        cin >> choice;
        cin.ignore();
        cout << endl;

        switch (choice) {
            case 1: listStudents(students, studentCount); break;
            case 2: addStudent(students, studentCount); break;
            case 3: addGrade(students, studentCount); break;
            case 4: viewGrades(students, studentCount); break;
            case 5: classReport(students, studentCount); break;
            case 6:
                saveStudents(students, studentCount);
                cout << "Grades saved. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
        cout << endl;

    } while (choice != 6);

    return 0;
}

void printMenu() {
    cout << "1. List students" << endl;
    cout << "2. Add student" << endl;
    cout << "3. Add grade" << endl;
    cout << "4. View student grades" << endl;
    cout << "5. Class report" << endl;
    cout << "6. Save and quit" << endl;
    cout << "Choice: ";
}

// =============== FILE I/O ===============

int loadStudents(Student students[]) {
    ifstream inFile(FILENAME);
    if (!inFile) return 0;

    int count = 0;
    while (count < MAX_STUDENTS) {
        // Read ID and number of scores
        if (!(inFile >> students[count].studentId >> students[count].numScores)) {
            break;
        }
        inFile.ignore();

        // Read name
        getline(inFile, students[count].name);

        // Read scores
        for (int i = 0; i < students[count].numScores; i++) {
            inFile >> students[count].scores[i];
        }

        count++;
    }

    inFile.close();
    return count;
}

void saveStudents(Student students[], int count) {
    ofstream outFile(FILENAME);
    if (!outFile) {
        cerr << "Error: Could not save grade book." << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        // Write ID, numScores, name
        outFile << students[i].studentId << " "
                << students[i].numScores << " "
                << students[i].name << endl;

        // Write scores on next line
        for (int j = 0; j < students[i].numScores; j++) {
            outFile << students[i].scores[j];
            if (j < students[i].numScores - 1) outFile << " ";
        }
        if (students[i].numScores > 0) outFile << endl;
    }

    outFile.close();
}

// =============== STUDENT MANAGEMENT ===============

void listStudents(Student students[], int count) {
    if (count == 0) {
        cout << "No students in grade book." << endl;
        return;
    }

    cout << setw(8) << "ID" << " | " << "Name" << endl;
    cout << "---------+---------------------" << endl;

    for (int i = 0; i < count; i++) {
        cout << setw(8) << students[i].studentId << " | "
             << students[i].name << endl;
    }
}

void addStudent(Student students[], int& count) {
    if (count >= MAX_STUDENTS) {
        cout << "Class is full!" << endl;
        return;
    }

    cout << "Enter student ID: ";
    cin >> students[count].studentId;
    cin.ignore();

    // Check if ID exists
    if (findStudent(students, count, students[count].studentId) != -1) {
        cout << "Error: Student ID already exists." << endl;
        return;
    }

    cout << "Enter student name: ";
    getline(cin, students[count].name);

    students[count].numScores = 0;  // No grades yet

    count++;
    cout << "Student added!" << endl;
}

int findStudent(Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].studentId == id) {
            return i;
        }
    }
    return -1;
}

// =============== GRADE OPERATIONS ===============

void addGrade(Student students[], int count) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    int index = findStudent(students, count, id);
    if (index == -1) {
        cout << "Student not found." << endl;
        return;
    }

    if (students[index].numScores >= MAX_ASSIGNMENTS) {
        cout << "Maximum grades reached for this student." << endl;
        return;
    }

    cout << "Enter grade (0-100): ";
    cin >> students[index].scores[students[index].numScores];

    students[index].numScores++;
    cout << "Grade added!" << endl;
}

void viewGrades(Student students[], int count) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    int index = findStudent(students, count, id);
    if (index == -1) {
        cout << "Student not found." << endl;
        return;
    }

    Student& s = students[index];
    cout << endl;
    cout << "=== Grades for " << s.name << " ===" << endl;

    if (s.numScores == 0) {
        cout << "No grades recorded yet." << endl;
        return;
    }

    for (int i = 0; i < s.numScores; i++) {
        cout << "  Assignment " << (i + 1) << ": "
             << fixed << setprecision(1) << s.scores[i] << endl;
    }

    double avg = calculateAverage(s);
    cout << endl;
    cout << "Average: " << fixed << setprecision(1) << avg
         << " (" << getLetterGrade(avg) << ")" << endl;
}

// =============== CALCULATIONS ===============

double calculateAverage(const Student& s) {
    if (s.numScores == 0) return 0;

    double sum = 0;
    for (int i = 0; i < s.numScores; i++) {
        sum += s.scores[i];
    }
    return sum / s.numScores;
}

char getLetterGrade(double avg) {
    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}

void classReport(Student students[], int count) {
    if (count == 0) {
        cout << "No students to report on." << endl;
        return;
    }

    cout << "=== Class Report ===" << endl << endl;

    double classSum = 0;
    int studentsWithGrades = 0;
    double highest = 0;
    double lowest = 100;
    string topStudent, bottomStudent;

    cout << setw(20) << left << "Name"
         << setw(10) << right << "Average"
         << setw(8) << "Grade" << endl;
    cout << string(38, '-') << endl;

    for (int i = 0; i < count; i++) {
        double avg = calculateAverage(students[i]);

        cout << setw(20) << left << students[i].name;

        if (students[i].numScores > 0) {
            cout << setw(10) << right << fixed << setprecision(1) << avg
                 << setw(8) << getLetterGrade(avg);

            classSum += avg;
            studentsWithGrades++;

            if (avg > highest) {
                highest = avg;
                topStudent = students[i].name;
            }
            if (avg < lowest) {
                lowest = avg;
                bottomStudent = students[i].name;
            }
        } else {
            cout << setw(10) << right << "N/A" << setw(8) << "-";
        }
        cout << endl;
    }

    if (studentsWithGrades > 0) {
        cout << endl;
        cout << "Class average: " << fixed << setprecision(1)
             << (classSum / studentsWithGrades) << endl;
        cout << "Highest: " << topStudent << " (" << highest << ")" << endl;
        cout << "Lowest: " << bottomStudent << " (" << lowest << ")" << endl;
    }
}
