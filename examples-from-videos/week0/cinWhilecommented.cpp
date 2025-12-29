// Preprocessor directive to include input/output stream library
#include <iostream>

// Using standard namespace to avoid typing std:: before cout, cin, etc.
using namespace std;

// Function to safely read an integer input with error handling
// Takes a prompt string as an argument to guide user input
int readInt(string prompt){
  // Declare a temporary integer to store user input
  int tempInt;

  // Display the input prompt to the user
  cout << prompt;

  // Attempt to read an integer from user input
  cin >> tempInt;

  // Enter a loop to handle potential input errors
  while(cin.fail()){
    // Clear the error flag on the input stream
    // This resets the stream after an invalid input
    cin.clear(); 

    // Discard up to 256 characters or until a newline 
    // This removes the invalid input from the stream
    cin.ignore(256,'\n');

    // Re-display the prompt
    cout << prompt;

    // Try reading the input again
    cin >> tempInt;
  }

  // Return the successfully read integer
  return tempInt;
}

// Main function - entry point of the program
int main(){
  // Declare an integer variable to store user input
  int num1;

  // Call readInt function with a prompt, store result in num1
  // This handles input validation and error checking
  num1 = readInt("Say somethin' will ya: ");

  // Output the number the user entered
  cout << "You said: " << num1 << endl;

  // Return 0 to indicate successful program execution
  return 0;
}
