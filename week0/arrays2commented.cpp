// Include the input/output stream library for console input and output
#include <iostream>

// Use the standard namespace to avoid writing std:: before cout, endl, etc.
using namespace std;

// Main function - entry point of the program
int main(){
  // Declare an integer array named 'num' with 5 elements
  // The array is uninitialized at this point, so it contains random values
  int num[5];

  // First loop: Fill the array with squared values
  // This loop will iterate 5 times (0 to 4)
  for(int i = 0; i < 5; i++){
    // Store the square of the current index in each array element
    // num[0] = 0*0 = 0
    // num[1] = 1*1 = 1
    // num[2] = 2*2 = 4
    // num[3] = 3*3 = 9
    // num[4] = 4*4 = 16
    num[i] = i*i;
  }

  // Second loop: Print out each element of the array
  for(int i = 0; i < 5; i++){
    // Print the index and its corresponding squared value
    // This will output: 
    // The 0th number is: 0
    // The 1st number is: 1
    // The 2nd number is: 4
    // The 3rd number is: 9
    // The 4th number is: 16
    cout << "The " << i << "th number is: " << num[i] << endl;
  }

  // DANGEROUS: Attempt to access an out-of-bounds array index
  // This will cause undefined behavior and likely a runtime error
  // Arrays in C++ do not have built-in bounds checking
  cout << "And num[6] is " << num[6] << endl;

  // Print the memory address of the array
  // This will output the memory location where the array is stored
  cout << "num itself is " << num << endl;
  
  // Indicate successful program termination
  return 0;
}
