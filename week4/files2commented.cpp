// Include the input/output stream library for basic I/O operations
#include <iostream>

// Include the file stream library for file handling operations
#include <fstream>

// Using standard namespace to avoid typing std:: before cout, endl, etc.
using namespace std;

int main(){
    // Create an output file stream object named myFile
    // "outheck.txt" is the name of the file to be created/opened
    // ios::app flag means append mode - new content will be added to the end of the file
    ofstream myFile("outheck.txt", ios::app);

    // Check if the file was successfully opened
    // If file opening fails, !myFile will be true
    if(!myFile){
        // Print error message if file couldn't be opened
        cout << "Couldn't open the file for writing?!" << endl;
        
        // Return 1 to indicate an error occurred
        return 1;
    }

    // Write the string "Me, I'm the chump!" to the file
    // endl adds a newline character after the text
    myFile << "Me, I'm the chump!" << endl;

    // Close the file stream
    // This is important to ensure all data is written and resources are released
    myFile.close();
    
    // Return 0 to indicate successful program execution
    return 0;
}
