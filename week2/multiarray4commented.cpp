// Include input/output stream library for console operations
#include <iostream>

// Use standard namespace to avoid prefixing std:: everywhere
using namespace std;

// Function to double all elements in a 2D array
// Parameters:
// - arr: 2D integer array with a fixed column size of 50
// - row: number of rows to process
void doubler(int arr[][50], int row){
  // Outer loop iterates through rows
  for(int i = 0; i < row; i++){
    // Inner loop iterates through columns
    for(int j = 0; j < 50; j++){
      // Multiply each array element by 2
      arr[i][j] = 2 * arr[i][j];
    }
  }
}

int main(){
  // Declare a 2D integer array with 40 rows and 50 columns
  // This allows for a large matrix-like data structure
  int arr[40][50];

  // Nested loops to initialize the array
  // Outer loop iterates through rows (0 to 39)
  for(int i = 0; i < 40; i++){
    // Inner loop iterates through columns (0 to 49)
    for(int j = 0; j < 50; j++){
      // Fill array with a unique value based on row and column
      // Formula creates a pattern: 1000 * row + column
      // Example: 
      // arr[0][0] = 0
      // arr[0][1] = 1
      // arr[1][0] = 1000
      // arr[1][1] = 1001
      arr[i][j] = 1000 * i + j;
    }
  }

  // Call doubler function to multiply all array elements by 2
  // Passes the entire array and number of rows to process
  doubler(arr, 40);
  
  // Nested loops to print out the modified array
  // Similar structure to initialization loops
  for(int i = 0; i < 40; i++){
    for(int j = 0; j < 50; j++){
      // Print each array element with its row and column indices
      cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;
    }
    // Print blank line between rows for readability
    cout << endl;
  }

  // Indicate successful program completion
  return 0;
}
