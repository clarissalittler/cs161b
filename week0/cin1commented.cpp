// Preprocessor directive to include the input/output stream library
// This allows us to use cout (console output) and cin (console input)
#include <iostream>

// Allows us to use standard library elements without prefixing with std::
using namespace std;

// Main function - the entry point of the C++ program
int main() {
    // Declare an integer variable named num1 to store user input
    // At this point, num1 contains an undefined/garbage value
    int num1;

    // Print a prompt to the console, asking user to input something
    // The << operator is used to send output to the console
    cout << "Say somethin' will ya: ";

    // Read an integer input from the user and store it in num1
    // The >> operator reads input from the console
    // If user enters a non-integer, the program may behave unexpectedly
    cin >> num1;

    // Display the number the user just entered
    // endl adds a newline and flushes the output buffer
    cout << "You said: " << num1 << endl;

    // Prompt user to enter another number
    cout << "What was that again?: ";

    // Read another integer input, overwriting the previous value in num1
    cin >> num1;

    // Display the new number entered by the user
    cout << "You said: " << num1 << endl;
  
    // Return 0 to indicate successful program execution
    return 0;
}
