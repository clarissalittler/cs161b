/*
Library Functions Used:
cout (std::ostream&) - Output stream object for console output
    - Defined in <iostream>
    - Used with << operator for output formatting
endl (std::ostream& (*)(std::ostream&)) - Stream manipulator
    - Defined in <iostream>
    - Outputs newline character and flushes the stream
*/

#include <iostream>   // Include input/output stream library
using namespace std;  // Use standard namespace to avoid std:: prefix

int main(){
    // Declare an integer variable and initialize it to 10
    int thing = 10;
    
    // Create a pointer to thing using the address-of operator (&)
    // thingAddr now holds the memory address where 'thing' is stored
    int* thingAddr = &thing;

    // Declare an array of 10 integers
    int arr[10];

    // Initialize array with values using formula i*i+100
    // This will fill array with: 100, 101, 104, 109, 116, 125, 136, 149, 164, 181
    for(int i = 0; i < 10; i++){
        arr[i] = i*i+100;
    }
    
    // Demonstrate that array indexing is equivalent to pointer arithmetic
    for(int i = 0; i < 10; i++){
        // arr[i] syntax - traditional array indexing
        cout << "arr[i] is: " << arr[i] << endl;
        
        // *(arr+i) syntax - pointer arithmetic
        // arr is the base address, +i moves i positions forward
        // * dereferences that address to get the value
        cout << "*(arr+i) is: " << *(arr+i) << endl;
    }
    
    return 0;  // Return 0 to indicate successful program completion
}
