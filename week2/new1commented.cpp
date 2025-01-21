// Include the input/output stream library for console operations
#include <iostream>

// Using standard namespace to avoid writing std:: before cout, endl, etc.
using namespace std;

// Define a structure to represent a rectangle
// Structures are similar to classes but have public members by default
struct Rect {
    // Width of the rectangle
    int w;
    // Height of the rectangle
    int h;
};

int main(){
    // Dynamically allocate memory for a Rect object on the heap
    // 'new' keyword allocates memory and returns a pointer to that memory
    Rect* r = new Rect;

    // Two equivalent ways to access and set structure members via a pointer:
    // 1. Dereference pointer and use dot notation: (*r).w = 10;
    // 2. Use arrow operator (preferred): r->w = 10;
    r->w = 10;  // Set width to 10
    r->h = 20;  // Set height to 20

    // Print rectangle dimensions
    // (*r).w dereferences the pointer and accesses the width member
    // endl adds a newline and flushes the output buffer
    cout << (*r).w << " " << (*r).h << endl;

    // Free the dynamically allocated memory to prevent memory leaks
    // 'delete' is used for single objects allocated with 'new'
    delete r;

    // Example of dynamic array allocation (commented out)
    // int* stuff = new int[10];  // Allocate array of 10 integers
    // delete[] stuff;  // Free array memory (note the [] for arrays)
  
    return 0;  // Indicate successful program completion
}
