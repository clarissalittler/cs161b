/*
 * 05-stack-array.cpp
 * A simple stack built on a fixed-size array.
 */

#include <iostream>
using namespace std;

const int MAX = 5;

bool push(int stack[], int& top, int value) {
    if (top >= MAX) {
        return false;
    }
    stack[top] = value;
    top++;
    return true;
}

bool pop(int stack[], int& top, int& value) {
    if (top <= 0) {
        return false;
    }
    top--;
    value = stack[top];
    return true;
}

int main() {
    int stack[MAX];
    int top = 0;

    push(stack, top, 10);
    push(stack, top, 20);
    push(stack, top, 30);

    int value;
    while (pop(stack, top, value)) {
        cout << "Popped: " << value << endl;
    }

    return 0;
}
