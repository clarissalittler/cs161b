/*
 * 05-default-arguments.cpp
 * Default values for parameters.
 */

#include <iostream>
#include <string>
using namespace std;

void greet(const string& name = "friend", const string& punctuation = "!") {
    cout << "Hello, " << name << punctuation << endl;
}

int main() {
    greet();
    greet("Ada");
    greet("Grace", "!!!");

    return 0;
}
