/*
 * 05-struct-initialization.cpp
 * Two common ways to initialize a struct.
 */

#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    int pages;
};

int main() {
    Book first;
    first.title = "Intro to C++";
    first.pages = 350;

    Book second = {"Data Structures", 520};

    cout << first.title << " has " << first.pages << " pages." << endl;
    cout << second.title << " has " << second.pages << " pages." << endl;

    return 0;
}
