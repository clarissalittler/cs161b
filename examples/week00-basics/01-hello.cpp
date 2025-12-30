/*
 * 01-hello.cpp
 * The classic first program.
 *
 * Every C++ program needs a main() function - that's where execution begins.
 * This one just says hello and exits.
 */

#include <iostream>
using namespace std;

int main() {
    // cout is the "character output" stream - it prints to the terminal
    // << is the insertion operator - it pushes data into the stream
    // endl ends the line and flushes the buffer

    cout << "Hello, world!" << endl;

    // Returning 0 tells the operating system "everything went fine"
    return 0;
}
