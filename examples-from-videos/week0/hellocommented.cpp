// This is a preprocessor directive that includes the input/output stream library
// It allows us to use input and output operations like cout
#include <iostream>

// This line allows us to use standard namespace elements without prefixing them with std::
// It means we can write cout instead of std::cout
using namespace std;

// The main() function is the entry point of any C++ program
// When the program runs, it starts executing from this function
int main() {
    // cout is the standard output stream object
    // << is the stream insertion operator that sends data to the output stream
    // "Hello, world!" is a string literal that will be printed to the console
    // endl is a stream manipulator that adds a newline character and flushes the output buffer
    cout << "Hello, world!" << endl;

    // This return statement indicates that the program has completed successfully
    // The value 0 is a conventional way to signal no errors occurred
    return 0;
}
