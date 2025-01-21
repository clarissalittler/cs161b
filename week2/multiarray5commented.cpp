#include <iostream>  // Include input/output stream library
using namespace std;  // Use standard namespace to avoid std:: prefix

// Function to double all elements in a 2D dynamic array
// Takes a pointer to a pointer (2D array), number of rows, and number of columns
void doubler(int** arr, int row, int col){
    // Nested loops to iterate through each element of the 2D array
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            // Multiply each element by 2
            arr[i][j] = 2 * arr[i][j];
        }
    }
}

int main(){
    // Dynamically allocate a 2D array of 40 rows
    // First, create an array of pointers, each will point to a row
    int** arr = new int*[40];

    // For each row pointer, allocate an array of 50 integers
    for(int i = 0; i < 40; i++){
        arr[i] = new int[50];
    }
  
    // Initialize the array with a pattern:
    // Each element is 1000 * row_index + column_index
    // This creates a unique value for each array element
    for(int i = 0; i < 40; i++){
        for(int j = 0; j < 50; j++){
            arr[i][j] = 1000 * i + j;
        }
    }

    // Call the doubler function to multiply all elements by 2
    // Pass the 2D array, number of rows, and number of columns
    doubler(arr, 40, 50);
  
    // Print out all elements of the modified array
    // Shows the result after doubling each element
    for(int i = 0; i < 40; i++){
        for(int j = 0; j < 50; j++){
            // Print each element with its array indices
            cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;
        }
        cout << endl;  // Add a blank line between rows for readability
    }
  
    // Properly deallocate the dynamically allocated memory
    // First, delete each row array
    for(int i = 0; i < 40; i++){
        delete[] arr[i];
    }
    // Then delete the array of row pointers
    delete[] arr;
  
    return 0;  // Indicate successful program completion
}
