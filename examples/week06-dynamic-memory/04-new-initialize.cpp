/*
 * 04-new-initialize.cpp
 * Initializing values directly with new.
 */

#include <iostream>
using namespace std;

int main() {
    int* count = new int(5);
    double* rate = new double(2.5);

    cout << "count = " << *count << endl;
    cout << "rate = " << *rate << endl;

    delete count;
    delete rate;

    return 0;
}
