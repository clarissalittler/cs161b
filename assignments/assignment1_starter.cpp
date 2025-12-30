/*
 * Assignment 1: Score Manager - Starter Code
 *
 * This is minimal scaffolding to help you get started.
 * You need to:
 * 1. Implement all the function bodies
 * 2. Complete the menu loop
 * 3. Add input handling
 *
 * Feel free to modify this structure if you have a better approach!
 */

#include <iostream>
using namespace std;

// TODO: Implement this function
// Prints all scores in a neat format
void PrintScores(int arr[], int size) {
    // Your code here
}

// TODO: Implement this function
// Returns the highest score in the array
int FindMax(int arr[], int size) {
    // Your code here
    return 0;  // Replace with actual return
}

// TODO: Implement this function
// Returns the lowest score in the array
int FindMin(int arr[], int size) {
    // Your code here
    return 0;  // Replace with actual return
}

// TODO: Implement this function
// Calculates and returns the average score as a double
double CalculateAverage(int arr[], int size) {
    // Your code here
    return 0.0;  // Replace with actual return
}

// TODO: Implement this function
// Counts and returns how many scores are above the threshold
int CountAboveThreshold(int arr[], int size, int threshold) {
    // Your code here
    return 0;  // Replace with actual return
}

int main() {
    const int MAX_SIZE = 100;
    int scores[MAX_SIZE];
    int numScores = 0;

    // TODO: Prompt for how many scores
    cout << "How many scores do you want to enter? ";
    // Your input code here

    // TODO: Read scores into the array using a loop
    // Your code here

    // Menu loop
    int choice = -1;
    while (choice != 0) {
        // TODO: Display menu
        cout << "\n=== Menu ===" << endl;
        cout << "1. Print all scores" << endl;
        // ... add rest of menu options ...
        cout << "0. Quit" << endl;
        cout << "Choice: ";
        cin >> choice;

        // TODO: Handle each menu choice
        // Your code here using if/else or switch
    }

    cout << "Goodbye!" << endl;
    return 0;
}
