// Include the input/output stream library, which allows us to use cin and cout
#include <iostream>

// Using the standard namespace to avoid typing std:: before cin, cout, etc.
using namespace std;

// Main function - the entry point of the program
int main(){
  // Declare an integer array named 'num' with a size of 5
  // This creates an array that can hold 5 integer values
  int num[5];

  // First loop to input numbers into the array
  // 'i' starts at 0 and goes up to 4 (5 iterations total)
  for(int i = 0; i < 5; i++){
    // Prompt the user to enter a number
    // 'i' is used to show which position in the array we're filling
    cout << "Enter the " << i << "th number: ";
    
    // Read the input from the user and store it in the array
    // num[i] means we're storing the input at index 'i' in the array
    cin >> num[i];
  }

  // Second loop to print out the numbers that were entered
  // This loop is similar to the input loop, but now we're displaying the values
  for(int i = 0; i < 5; i++){
    // Print out each number in the array
    // Shows the index and the value stored at that index
    cout << "The " << i << "th number is: " << num[i] << endl;
  }
  
  // Return 0 to indicate the program completed successfully
  return 0;
}
