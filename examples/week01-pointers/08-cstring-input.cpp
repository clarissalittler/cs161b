/*
 * 08-cstring-input.cpp
 * Reading a C-string with getline.
 */

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int MAX_LEN = 50;
    char name[MAX_LEN];

    cout << "Enter your name: ";
    cin.getline(name, MAX_LEN);

    cout << "Hello, " << name << "!" << endl;
    cout << "Length: " << strlen(name) << endl;

    return 0;
}
