/*
 * Mini-Project: To-Do List Manager (Solution)
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;
const string FILENAME = "todos.txt";

struct Task {
    string description;
    bool completed;
};

int loadTasks(Task tasks[]);
void saveTasks(Task tasks[], int count);
void displayTasks(Task tasks[], int count);
void addTask(Task tasks[], int& count);
void completeTask(Task tasks[], int count);
void deleteTask(Task tasks[], int& count);
void printMenu();

int main() {
    Task tasks[MAX_TASKS];
    int count = loadTasks(tasks);

    cout << "=== To-Do List Manager ===" << endl;
    if (count > 0) {
        cout << "Loaded " << count << " tasks from " << FILENAME << endl;
    } else {
        cout << "No existing tasks found. Starting fresh!" << endl;
    }
    cout << endl;

    int choice;
    do {
        printMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                displayTasks(tasks, count);
                break;
            case 2:
                addTask(tasks, count);
                break;
            case 3:
                completeTask(tasks, count);
                break;
            case 4:
                deleteTask(tasks, count);
                break;
            case 5:
                saveTasks(tasks, count);
                cout << "Saved " << count << " tasks to " << FILENAME << endl;
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
        cout << endl;
    } while (choice != 5);

    return 0;
}

void printMenu() {
    cout << "1. View tasks" << endl;
    cout << "2. Add task" << endl;
    cout << "3. Complete task" << endl;
    cout << "4. Delete task" << endl;
    cout << "5. Save and quit" << endl;
    cout << "Choice: ";
}

int loadTasks(Task tasks[]) {
    ifstream inFile(FILENAME);
    if (!inFile) {
        return 0;
    }

    int count = 0;
    string line;

    while (getline(inFile, line) && count < MAX_TASKS) {
        if (line.length() < 4) {
            continue;
        }
        tasks[count].completed = (line[1] == 'x' || line[1] == 'X');
        tasks[count].description = line.substr(4);
        count++;
    }

    inFile.close();
    return count;
}

void saveTasks(Task tasks[], int count) {
    ofstream outFile(FILENAME);

    if (!outFile) {
        cerr << "Error: Could not save to " << FILENAME << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        outFile << "[" << (tasks[i].completed ? "x" : " ") << "] ";
        outFile << tasks[i].description << endl;
    }

    outFile.close();
}

void displayTasks(Task tasks[], int count) {
    if (count == 0) {
        cout << "No tasks yet!" << endl;
        return;
    }

    cout << endl;
    for (int i = 0; i < count; i++) {
        cout << (i + 1) << ". [" << (tasks[i].completed ? "x" : " ") << "] ";
        cout << tasks[i].description << endl;
    }
}

void addTask(Task tasks[], int& count) {
    if (count >= MAX_TASKS) {
        cout << "Task list is full!" << endl;
        return;
    }

    cout << "Enter task description: ";
    getline(cin, tasks[count].description);
    tasks[count].completed = false;
    count++;

    cout << "Task added!" << endl;
}

void completeTask(Task tasks[], int count) {
    if (count == 0) {
        cout << "No tasks to complete." << endl;
        return;
    }

    displayTasks(tasks, count);
    cout << "Complete which task? ";

    int taskNum;
    cin >> taskNum;

    if (taskNum < 1 || taskNum > count) {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks[taskNum - 1].completed = true;
}

void deleteTask(Task tasks[], int& count) {
    if (count == 0) {
        cout << "No tasks to delete." << endl;
        return;
    }

    displayTasks(tasks, count);
    cout << "Delete which task? ";

    int taskNum;
    cin >> taskNum;

    if (taskNum < 1 || taskNum > count) {
        cout << "Invalid task number." << endl;
        return;
    }

    for (int i = taskNum - 1; i < count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    count--;
}
