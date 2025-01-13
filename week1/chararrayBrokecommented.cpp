/*
LIBRARY FUNCTIONS USED:
cout << (std::ostream&) - Outputs data to console
endl (std::ostream& (*)(std::ostream&)) - Outputs newline and flushes stream

Note: Both cout and endl are part of the iostream library
*/

#include <iostream>  // Include input/output stream library
using namespace std; // Using standard namespace to avoid std:: prefix

int main(){
    // In C-style strings, null terminator (\0) marks string end
    // \n represents newline character

    // The array can store 49 actual characters plus null terminator
    // Even though we declare size 50, one byte must be reserved for \0
    char msg[50] = "Hey there I'm silly"; // Initialize char array with string literal
    
    // Starting from position 19 (after our initial message)
    // Fill the rest of the array with 'x' characters
    for(int i = 19; i < 50; i++){
        msg[i] = 'x';
    }
    
    // Output the string to console
    // Note: This will print until it hits a null terminator
    cout << msg << endl;

    /*
    // Commented out code showing alternative printing method
    // This would print every character with underscore separator
    // including any null terminators or garbage values
    for(int i = 0; i < 50; i++){
        cout << msg[i] << "_";
    }
    */
    
    // null-terminated iteration would be another way to print
    // it would stop at first \0 character
    
    return 0; // End program with success code
}
