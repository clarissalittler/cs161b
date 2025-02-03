// Include necessary header files for input/output operations and file handling
#include <iostream>   // Provides input/output stream functionality
#include <fstream>    // Provides file input/output stream capabilities
using namespace std;  // Allows use of standard library elements without std:: prefix

// Define a constant for the maximum line length to be read from the file
const int lineLength = 256;  // Limits the number of characters that can be read per line

int main() {
    // Attempt to open a file named "heck.txt" for reading
    // ifstream creates an input file stream object to read from the file
    ifstream ourFile("heck.txt");

    // Create a character array to store each line read from the file
    // This will temporarily hold the content of each line
    char line[lineLength];
    
    // Check if the file was successfully opened
    // If the file doesn't exist or can't be read, the condition will be true
    if(!ourFile) {
        // Print an error message if file opening fails
        cout << "Whoops, didn't find that??" << endl;
        // Exit the program with an error code (1 indicates an error occurred)
        return 1;
    }

    // Inform the user that the file contents will be displayed
    cout << "The contents of the file were: " << endl;

    // Read the file line by line using a while loop
    // getline() reads a line from the file into the 'line' array
    // It continues until end of file or max line length is reached
    while(ourFile.getline(line, lineLength)) {
        // Print each line to the console as it's read
        cout << line << endl;
    }

    // Close the file stream (good practice to explicitly close file streams)
    ourFile.close();
    
    // Return 0 to indicate successful program execution
    return 0;
}
