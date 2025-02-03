// Include necessary header files for input/output and string manipulation
#include <iostream>   // For standard input/output operations
#include <fstream>    // For file input/output operations
#include <cstring>    // For string manipulation functions like strlen()
using namespace std;  // Using standard namespace to avoid std:: prefixes

// Define a constant for maximum line length
const int lineLength = 256;  // Maximum characters per line in the file

/*
  Program Purpose:
  - Read a text file line by line into a 2D character array
  - Reverse each line of text
  - Write the reversed lines to a new output file
*/

// Function to reverse a null-terminated string
void reverseString(char str[], char reverse[]){
  // Calculate the length of the input string
  // strlen() returns the number of characters before the null terminator
  int i = strlen(str);

  // Reverse the string by copying characters from end to beginning
  // i now points to the end of the string (null terminator position)
  for(int j=0; j < i; j++){
    // Copy characters in reverse order
    // (i-1)-j ensures we start from the last character and move backwards
    reverse[j] = str[(i-1)-j];
  }
  
  // Add null terminator to the end of the reversed string
  // This is crucial to make it a valid C-style string
  reverse[i]='\0';
}

int main(){
  // Declare a 2D character array to store file contents
  // Can hold up to 100 lines, each up to lineLength characters long
  char fileData[100][lineLength];
  
  // Open input file for reading
  // "heck.txt" is the source file to be read
  ifstream inFile("heck.txt");
  
  // Open output file for writing
  // "kceh.txt" will be the file with reversed lines
  ofstream outFile("kceh.txt");
  
  // Keep track of current line number while reading
  int currLine = 0;
  
  // Read file line by line into fileData array
  // getline() reads until newline or maximum length is reached
  while(inFile.getline(fileData[currLine],lineLength)){
    currLine++;  // Increment line counter after each successful read
  }
  
  // Close input file after reading
  inFile.close();

  // Process and write each line to output file
  for(int i=0; i<currLine; i++){
    // Temporary array to store reversed line
    char reverseLine[lineLength];
    
    // Call reverseString to reverse current line
    reverseString(fileData[i], reverseLine);
    
    // Write reversed line to output file
    // endl adds a newline after each line
    outFile << reverseLine << endl;
  }
    
  // Program completed successfully
  return 0;
}
hello
world
olleh
dlrow
