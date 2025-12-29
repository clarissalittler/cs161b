/*
LIBRARY FUNCTIONS USED:
cout << (std::ostream&) - Outputs data to console
endl (std::ostream& (*)(std::ostream&)) - Outputs newline and flushes stream
static_cast<type>(expression) - C++ type conversion operator

*/

#include <iostream>  // Include input/output stream library
using namespace std;  // Use standard namespace to avoid std:: prefix

int main(){
    // In C-style strings, null terminator (\0) marks string end
    // \n represents newline character

    // Character array can store 49 actual characters plus null terminator
    // So the answer to the quiz is 49 characters max
    char msg[50] = "Hey there I'm silly";  // Declare and initialize char array
    
    string silly = "Hi I'm a 0";  // Declare and initialize C++ string object
    
    /*
    // Original for loop approach (commented out)
    // This would print ALL 50 elements, including garbage after null terminator
    for(int i = 0; i < 50; i++){
        cout << msg[i] << "_";
    }
    */

    // Better approach: iterate until null terminator found
    int i=0;  // Initialize counter
    while(msg[i] != '\0'){  // Continue until null terminator reached
        // Convert each character to its ASCII integer value and print
        cout << static_cast<int>(msg[i]) << "_";
        i++;  // Increment counter
    }
    cout << endl;  // Print newline

    // Demonstrate where null terminator was found
    // Will print the index where \0 was found and its ASCII value (0)
    cout << "The " << i << "th indexed element of the array is: " 
         << static_cast<int>(msg[i]) << endl;
  
    return 0;  // End program with success code
}
