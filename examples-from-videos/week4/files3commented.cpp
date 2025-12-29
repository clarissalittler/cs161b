// Include necessary header files
#include <iostream>   // For input/output operations
#include <fstream>    // For file stream operations
#include <cstring>    // For string comparison functions like strcmp()
using namespace std;  // Use standard namespace to avoid std:: prefix

// Define a constant for maximum line length to prevent buffer overflow
const int lineLength = 256;

int main(){
  // Open the file "outheck.txt" with multiple modes:
  // ios::app - append mode (write to the end of the file)
  // ios::in - input mode (allow reading from the file)
  // ios::out - output mode (allow writing to the file)
  fstream myFile("outheck.txt", ios::app | ios::in | ios::out);
  
  // Declare a character array to store a line read from the file
  char line[lineLength];
  
  // Check if file opening was unsuccessful
  if(!myFile){
    // Print error message if file couldn't be opened
    cout << "Whoopsy doodle!" << endl;
    // Exit the program with an error code
    return 1;
  }

  // Try to read the first line from the file
  if(myFile.getline(line,lineLength)){
    // If a line was successfully read...

    // Compare the line with the specific text using strcmp()
    // strcmp() returns 0 if strings are exactly equal
    if(strcmp(line,"Who's the chump writing this text?") == 0){
      // If the line matches exactly, append the new line
      myFile << "Me. I'm the chump!" << endl;
    }
    else{
      // If the line doesn't match, print an error message
      cout << "Sorry, wrong file!" << endl;
    }
  }
  else{
    // If no line could be read (empty file)...

    // Clear any error flags on the file stream
    // This is necessary after a failed read operation
    myFile.clear();

    // Write the initial text to the file
    myFile << "Who's the chump writing this text?" << endl;
  }

  // Program completed successfully
  return 0;
}
