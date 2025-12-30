/*
 * Mini-Project: Number Cruncher
 *
 * A simple statistics calculator.
 *
 * Your task:
 * 1. Ask the user how many numbers they want to enter (max 100)
 * 2. Read that many numbers into an array
 * 3. Calculate and display: sum, average, largest, smallest
 */

#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    double numbers[MAX_SIZE];
    int count;

    // Step 1: Ask how many numbers
    cout << "How many numbers? ";
    cin >> count;

    // Make sure count is valid
    if (count < 1 || count > MAX_SIZE) {
        cout << "Please enter a number between 1 and " << MAX_SIZE << endl;
        return 1;
    }

    // Step 2: Read the numbers into the array
    // TODO: Write a loop that reads 'count' numbers into the 'numbers' array
    //       Print "Enter number X: " for each one (where X is 1, 2, 3...)




    // Step 3: Calculate the sum
    // TODO: Loop through the array and add up all the numbers
    double sum = 0;



    // Step 4: Calculate the average
    // TODO: Divide the sum by the count
    double average = 0;



    // Step 5: Find the largest number
    // TODO: Start with the first element, then check each one
    double largest = 0;



    // Step 6: Find the smallest number
    // TODO: Same idea as largest, but look for smaller values
    double smallest = 0;



    // Step 7: Display the results
    cout << endl;
    cout << "Results:" << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Largest: " << largest << endl;
    cout << "Smallest: " << smallest << endl;

    return 0;
}

/*
 * Hints:
 *
 * - For reading numbers: numbers[i] is the i-th element
 * - For finding largest: if (numbers[i] > largest) { largest = numbers[i]; }
 * - Remember that arrays are zero-indexed!
 *
 * Test your program with these inputs:
 * - 5 numbers: 10, 25, 8, 42, 15 (expect sum=100, avg=20, max=42, min=8)
 * - 3 numbers: 5, 5, 5 (expect sum=15, avg=5, max=5, min=5)
 * - 1 number: 7 (expect sum=7, avg=7, max=7, min=7)
 */
