/*
LIBRARY FUNCTIONS USED:
std::cout : ostream& operator<<(const T& value)
    - Outputs values to console/terminal
std::endl : ostream& endl(ostream& os)
    - Outputs newline character and flushes output buffer

*/

#include <iostream>   // Include input/output stream library
using namespace std;  // Use standard namespace to avoid std:: prefix

// Function that doubles the value of its parameter
// Takes an integer reference parameter so it can modify the original value
void doubler(int& num){
    num = 2 * num;   // Multiply the referenced value by 2
}

int main(){
    // Initialize an integer variable with value 10
    int thing = 10;
    
    // Create a pointer to 'thing'
    // (Not used in this example but shows relationship between pointers and references)
    int* thingAddr = &thing;

    // Call doubler function with 'thing'
    // Since doubler takes a reference, 'thing' itself will be modified
    doubler(thing);
    
    // Output the new value of 'thing'
    // Will show 20 since the original value (10) was doubled
    cout << "Now thing is: " << thing << endl;
  
    return 0;   // Return successful program completion status
}
