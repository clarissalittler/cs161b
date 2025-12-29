// Include input/output stream library for console operations
#include <iostream>

// Using standard namespace to avoid prefixing std:: everywhere
using namespace std;

// Function to double all elements in a 2D integer array
// Uses double pointer to represent 2D array, with rows and columns as parameters
void doubler(int** arr, int rows, int columns){
  // Outer loop iterates through each row
  for(int i = 0; i = 0; i < rows; i++){
    // Inner loop iterates through each column in the current row
    for(int j = 0; j < columns; j++){
      // Multiply each array element by 2 in-place
      // Equivalent to arr[i][j] = arr[i][j] * 2
      arr[i][j] = 2*arr[i][j];
      
      // Commented alternative access method showing pointer arithmetic
      // arr[i][j] is equivalent to *( *(arr + i) + j)
    }
  }
}

int main(){
  // Declare a large 2D integer array with 50x50 elements
  // Statically allocated on the stack
  int arr[50][50];

  // Nested loops to initialize the entire array
  // Outer loop iterates through rows (0 to 49)
  for(int i = 0; i < 50; i++){
    // Inner loop iterates through columns (0 to 49)
    for(int j = 0; j < 50; j++){
      // Fill each element with a unique value based on row and column
      // Creates a pattern where each element is (row * 1000 + column)
      // E.g., arr[0][0] = 0, arr[1][2] = 1002, arr[10][5] = 10005
      arr[i][j] = i*1000 + j; 
    }
  }

  // Call doubler function to multiply all elements by 2
  // Passes the entire 2D array, with 50 rows and 50 columns
  doubler(arr,50,50);
  
  // Loop to print out all elements in the second row (index 1)
  // after the doubling operation
  for(int j = 0; j < 50; j++){
    // Prints the column index and the corresponding doubled value
    cout << "The " << j << "th element of row 1 is: " << arr[1][j] << endl;
  }
  
  // Successful program termination
  return 0;
}
