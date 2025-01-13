/*
LIBRARY FUNCTIONS USED:
iostream functions:
- cout.operator<<(const char*) : Outputs a string to console
- cout.operator<<(char) : Outputs a character to console
- cout.operator<<(endl) : Outputs newline and flushes buffer
- cin.operator>>(char[]) : Reads space-delimited string from console

cstring functions:
- None directly used, but this example demonstrates manual string copying
  similar to strcpy(char* dest, const char* src)
*/

#include <iostream>
#include <cstring>
using namespace std;

// Implementation of string copy function similar to standard strcpy
void ourStrcpy(char dest[],char src[]){
    int i = 0;
    // Copy characters one by one until null terminator is found
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i]; // Copy the null terminator too
}

int main(){
    // Declare two character arrays (C-style strings)
    char msg1[50];     // Will hold user input
    char oldMsg[50] = "beepity boopity boppity ba-blam";  // Initialize with string literal
    
    // First input prompt
    cout << "Say something: ";
    cin >> msg1;       // Read user input into msg1
    cout << msg1 << endl;  // Echo input back to user
    
    // Copy contents of msg1 into oldMsg using our custom copy function
    ourStrcpy(oldMsg,msg1);
    
    // Second input prompt
    cout << "Say something else: ";
    cin >> msg1;       // Read new input into msg1
    cout << msg1 << endl;    // Echo new input
    cout << oldMsg << endl;  // Show what was copied earlier
    
    // Debug loop to show full contents of oldMsg array
    // This will show any remaining characters after the null terminator
    for(int i = 0; i < 50; i++){
        cout << oldMsg[i] << '_';  // Print each character followed by underscore
    }
    cout << endl;
    
    return 0;
}
