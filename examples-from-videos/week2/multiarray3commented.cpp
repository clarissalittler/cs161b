// Include the input/output stream library for console operations
#include <iostream>

// Using the standard namespace to avoid writing std:: before cout, endl, etc.
using namespace std;

int main(){
  // Declare a 2D integer array with 40 rows and 50 columns
  // This creates a large matrix-like data structure in memory
  // The first bracket represents rows, the second represents columns
  int arr[40][50];

  // Nested loops to initialize the entire array
  // Outer loop (i) iterates through rows (0 to 39)
  for(int i=0; i < 40; i++){
    // Inner loop (j) iterates through columns (0 to 49)
    for(int j=0; j < 50; j++){
      // Fill each element with a unique value:
      // 1000 * row number + column number
      // This creates a pattern where:
      // - Elements in the same row differ by column index
      // - Elements in different rows differ by 1000
      arr[i][j] = 1000*i + j;
    }
  }

  // Another loop to print out all elements in the 5th row (index 4)
  // Note: Array indices start at 0, so 5th row is actually index 4
  for(int j=0; j < 40; j++){
    // Print each element in the 5th row
    // This will show the pattern created in the previous initialization
    cout << "The jth element of the 5th row is: " << arr[5][j] << endl;
  }
  
  // Indicates successful program completion
  return 0;
}
