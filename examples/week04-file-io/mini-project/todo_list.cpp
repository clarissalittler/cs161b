/*
 * Mini-Project: To-Do List Manager
 *
 * A persistent to-do list that saves to a file.
 * Your tasks survive between program runs!
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

// Function prototypes
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
        cin.ignore();  // Clear newline

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

// TODO: Implement this function
// Load tasks from FILENAME
// File format: each line is "[x] description" or "[ ] description"
// Returns the number of tasks loaded
int loadTasks(Task tasks[]) {
    ifstream inFile(FILENAME);

    // If file doesn't exist, that's okay - return 0 tasks
    if (!inFile) {
        return 0;
    }

    int count = 0;
    string line;

    // TODO: Read each line
    // Parse the [x] or [ ] to determine if completed
    // Extract the description (everything after the ] and space)
    // Store in tasks[count] and increment count

    while (getline(inFile, line) && count < MAX_TASKS) {
        // Hint: line format is "[x] description" or "[ ] description"
        // line[1] is either 'x' or ' '
        // description starts at index 4

    }

    inFile.close();
    return count;
}

// TODO: Implement this function
// Save tasks to FILENAME
// Write each task as "[x] description" or "[ ] description"
void saveTasks(Task tasks[], int count) {
    ofstream outFile(FILENAME);

    if (!outFile) {
        cerr << "Error: Could not save to " << FILENAME << endl;
        return;
    }

    // TODO: Write each task in the format "[x] desc" or "[ ] desc"


    outFile.close();
}

// TODO: Implement this function
// Display all tasks with numbers
// Format: "1. [x] Buy groceries" or "2. [ ] Call mom"
void displayTasks(Task tasks[], int count) {
    if (count == 0) {
        cout << "No tasks yet!" << endl;
        return;
    }

    cout << endl;
    // TODO: Loop through and print each task with its number


}

// TODO: Implement this function
// Prompt for a description and add a new (incomplete) task
void addTask(Task tasks[], int& count) {
    if (count >= MAX_TASKS) {
        cout << "Task list is full!" << endl;
        return;
    }

    cout << "Enter task description: ";
    // TODO: Read the description using getline
    // Set completed to false
    // Increment count

    cout << "Task added!" << endl;
}

// TODO: Implement this function
// Ask which task to mark complete, then mark it
void completeTask(Task tasks[], int count) {
    if (count == 0) {
        cout << "No tasks to complete." << endl;
        return;
    }

    displayTasks(tasks, count);
    cout << "Complete which task? ";

    int taskNum;
    cin >> taskNum;

    // TODO: Validate taskNum and mark tasks[taskNum-1].completed = true

}

// TODO: Implement this function
// Ask which task to delete, then remove it by shifting others down
void deleteTask(Task tasks[], int& count) {
    if (count == 0) {
        cout << "No tasks to delete." << endl;
        return;
    }

    displayTasks(tasks, count);
    cout << "Delete which task? ";

    int taskNum;
    cin >> taskNum;

    // TODO: Validate taskNum, shift all later tasks down, decrement count

}

/*
 * Hints:
 *
 * loadTasks:
 *   if (line.length() >= 4) {
 *       tasks[count].completed = (line[1] == 'x');
 *       tasks[count].description = line.substr(4);
 *       count++;
 *   }
 *
 * saveTasks:
 *   for (int i = 0; i < count; i++) {
 *       outFile << "[" << (tasks[i].completed ? "x" : " ") << "] ";
 *       outFile << tasks[i].description << endl;
 *   }
 *
 * displayTasks:
 *   for (int i = 0; i < count; i++) {
 *       cout << (i+1) << ". [" << (tasks[i].completed ? "x" : " ") << "] ";
 *       cout << tasks[i].description << endl;
 *   }
 *
 * addTask:
 *   getline(cin, tasks[count].description);
 *   tasks[count].completed = false;
 *   count++;
 *
 * completeTask:
 *   if (taskNum >= 1 && taskNum <= count) {
 *       tasks[taskNum-1].completed = true;
 *   }
 *
 * deleteTask:
 *   for (int i = taskNum-1; i < count-1; i++) {
 *       tasks[i] = tasks[i+1];
 *   }
 *   count--;
 */
