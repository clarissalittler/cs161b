// Include the input/output stream library
#include <iostream>

// Using the standard namespace to avoid typing std:: repeatedly
using namespace std;

int main(){
    // Declare an integer variable to store user input
    int num1;
    
    // Prompt the user to enter a number
    cout << "Say somethin' will ya: ";
    
    // Read an integer input from the user
    // If the input is not an integer, this will set the fail flag
    cin >> num1;

    // Display the number the user entered
    cout << "You said: " << num1 << endl;

    // Check if the input operation failed (e.g., user entered a non-integer)
    if(cin.fail()){
        // Clear the error flag so we can use cin again
        cin.clear(); 
        
        // Ignore (discard) up to 256 characters or until a newline is found
        // This removes the invalid input from the input stream
        cin.ignore(256,'\n');
        
        // Prompt user to try again
        cout << "What was that again?: ";
        
        // Try to read input again
        cin >> num1;

        // Display the new input
        cout << "You said: " << num1 << endl;
    }

    // Second attempt to handle potential input errors
    // (Mostly redundant in this example, but shows a possible error handling approach)
    if(cin.fail()){
        // Clear the error flag again
        cin.clear(); 
        
        // Ignore invalid input again
        cin.ignore(256,'\n');
        
        // Prompt user to try again
        cout << "What was that again?: ";
        
        // Try to read input once more
        cin >> num1;

        // Display the new input
        cout << "You said: " << num1 << endl;
    }

    // Indicate successful program completion
    return 0;
}
