#include <vector>
#include <iostream>
#include <fstream>    // For file input/output operations
#include <cstring>    // For string comparison functions

using namespace std;

// Define a structure to hold image data
// P1 is a simple binary image format (black and white only)
struct P1 {
    int width;                        // Width of the image in pixels
    int height;                       // Height of the image in pixels
    vector<vector<int>> pixels;       // 2D vector to store pixel values (0 or 1)
    // This is a 2D vector - essentially a vector where each element is another vector
    // This allows us to create a matrix-like structure for our image data
};

// Function to read pixel values from file into the image structure
void parseFile(P1 &img, ifstream &f) {
    // Note: we pass the image by reference (&img) so we can modify the original image
    // Loop through each row of the image
    for(int i = 0; i < img.height; i++) {
        // Loop through each column of the current row
        for(int j = 0; j < img.width; j++) {
            // Read the next value from the file into our pixels array
            f >> img.pixels[i][j];
            // This reads whitespace-separated integers from the file
        }
        // Skip any remaining characters on the current line
        // This ensures we start fresh on the next line
        f.ignore(256, '\n');
    }
}

// Function to display the image contents
void printImage(const P1 &img) {
    // Note: we pass the image as const reference to indicate we won't modify it
    // Loop through each row
    for(int i = 0; i < img.height; i++) {
        // Loop through each column in the current row
        for(int j = 0; j < img.width; j++) {
            // Print the pixel value followed by a space
            cout << img.pixels[i][j] << " ";
        }
        // After printing a complete row, move to the next line
        cout << endl;
    }
}

// Function to invert the image (change 0s to 1s and vice versa)
void invertImage(P1 &img) {
    // Loop through each row
    for(int i = 0; i < img.height; i++) {
        // Loop through each column in the current row
        for(int j = 0; j < img.width; j++) {
            // The ! operator performs logical NOT:
            // If pixel is 0, !pixel becomes 1
            // If pixel is 1, !pixel becomes 0
            img.pixels[i][j] = !img.pixels[i][j];
        }
    }
}

int main() {
    char preface[50];                   // Buffer to store file format identifier
    ifstream inputFile("test.ppm");     // Open the image file
    // ifstream creates an input file stream that reads from the specified file

    // Check if the file was successfully opened
    if (!inputFile.is_open()) {
        cerr << "Could not open the file 'test.ppm'." << endl;
        // cerr is the standard error stream, used for error messages
        return 1;  // Return error code
    }

    P1 image;                            // Declare image structure
  
    inputFile.getline(preface, 50);      // Read first line (should be "P1")
    // strcmp compares two strings and returns 0 if they are identical
    if (strcmp(preface, "P1") == 0) {
        cout << "This is an image file so let's process it!" << endl;

        // Read image width and height from the file
        inputFile >> image.width;
        inputFile >> image.height;
        
        // Skip to the next line to prepare for reading pixel data
        inputFile.ignore(256, '\n');

        // Allocate memory for 2D vector - THIS IS A CRITICAL STEP!
        // resize() changes the size of the vector to match the specified dimensions
        // Here's what's happening:
        // 1. image.pixels.resize(image.height, ...) - Sets the outer vector to have 'height' elements
        // 2. vector<int>(image.width, 0) - Each of those elements is itself a vector of integers
        //    - This creates a vector of width 'width'
        //    - Each element is initialized to 0
        // This effectively creates a 2D array of zeros with dimensions height × width
        image.pixels.resize(image.height, vector<int>(image.width, 0));
        
        // Process the image
        parseFile(image, inputFile);   // Read pixel data from file into our image structure
        invertImage(image);            // Invert the image (0s become 1s and vice versa)
        printImage(image);             // Display the result to console
    }
    else {
        cout << "Whoops, this isn't a P1 image file, bye!" << endl;
    }

    // When using std::vector, we don't have to worry about manually freeing memory.
    // The vector destructor automatically deallocates memory when it goes out of scope.
    // This is one of the big advantages of using vectors instead of raw arrays.

    return 0;  // Return success code
}
