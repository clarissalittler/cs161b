#include <iostream>   // Input/output stream library
#include <fstream>    // File stream library for file handling
#include <cstring>    // C-style string manipulation functions
using namespace std;  // Using standard namespace to avoid std:: prefix

// Constant to define maximum line length for the input file
const int lineLength = 256;

/*
  This program will read in a file line by line
  into a two-dimensional array and *then* write out the file with each line reversed 
  (but still with the null characters in the right place)
*/

// Function to reverse a null-terminated character array (string)
void reverseString(char str[]){
  // null-terminated strings
  int i = 0;
  // Temporary array to hold the reversed string
  char temp[lineLength];

  // Find the length of the string by counting until null terminator
  while(str[i] != '\0'){
    i++; // Increment index until end of string is reached
  }
  // Here, i now points to the end of the string (null terminator)

  // Copy characters in reverse order to temporary array
  for(int j=0; j < i; j++){
    // Take characters from the end, placing them at the beginning
    temp[j] = str[(i-1)-j]; 
  }

  // Copy the reversed string back to the original array
  for(int j=0; j < i; j++){
    str[j] = temp[j];
  }
}

int main(){
  // 2D character array to store file contents
  // Can store up to 100 lines, each up to lineLength characters long
  char fileData[100][lineLength];

  // Open input file for reading
  // "heck.txt" is the input file to be read
  ifstream inFile("heck.txt");

  // Open output file for writing
  // "kceh.txt" will be the output file with reversed lines
  ofstream outFile("kceh.txt");

  // Counter to keep track of number of lines read
  int currLine = 0;
  
  // Read file line by line into fileData array
  // getline() reads until newline or max length is reached
  while(inFile.getline(fileData[currLine],lineLength)){
    currLine++; // Increment line counter after each successful read
  }
  // Close input file after reading
  inFile.close();

  // Process and write out each line
  for(int i=0; i<currLine; i++){
    // Reverse the current line in-place
    reverseString(fileData[i]);
    
    // Write the reversed line to output file
    // endl adds a newline after each line
    outFile << fileData[i] << endl;
  }
    
  // Successful program completion
  return 0;
}
