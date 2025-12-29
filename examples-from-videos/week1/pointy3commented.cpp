#include <iostream>
using namespace std;

/*
Library Functions Used:
cout (std::ostream&) - Output stream object for printing to console
    Signature: std::ostream& cout
    Description: Standard output stream that prints text/values to console

endl (std::ostream& (*)(std::ostream&)) - Stream manipulator
    Signature: std::ostream& endl(std::ostream& os)
    Description: Outputs newline character and flushes the output buffer
*/

// Function to double all elements in an array using pointer arithmetic
// Parameters: num - pointer to integer array, l - length of array
void doubler(int* num, int l){
    // Iterate through array using pointer arithmetic
    for(int i = 0; i < l; i++){
        // *(num+i) dereferences the memory location (num + i)
        // Multiply the value at that location by 2
        *(num+i) = 2*(*(num + i));
    }  
}

/* Alternative array notation version:
void doubler(int num[], int l){
    for(int i = 0; i < l; i++){
        num[i] = 2*num[i];
    }  
}
*/

int main(){
    // Declare an integer array of size 10
    int thing[10];

    // Initialize array with values 0 through 9
    for(int i = 0; i< 10; i++){
        thing[i] = i;
    }
    
    // Call doubler function to multiply each element by 2
    // Note: array name 'thing' decays to pointer to first element
    doubler(thing, 10);

    // Print out all elements of the modified array
    for(int i = 0; i < 10; i++){
        // Format: "thing[index]: value"
        cout << "thing[" << i << "]: " << thing[i] << endl; 
    }
    
    // Return 0 to indicate successful program execution
    return 0;
}
