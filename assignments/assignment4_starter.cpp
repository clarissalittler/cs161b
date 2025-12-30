/*
 * Assignment 4: Stack Implementation - Starter Code
 *
 * This file shows the structure for BOTH implementations.
 * You can put them in the same file or separate files - your choice!
 *
 * Part 1: Array-based stack
 * Part 2: Linked-list-based stack
 */

#include <iostream>
using namespace std;

// ============================================
// PART 1: ARRAY-BASED STACK
// ============================================

const int MAX_STACK_SIZE = 10;

// TODO: Define your Stack struct for array-based implementation
struct ArrayStack {
    // Your members here
    // Hint: You need the array and a way to track how many elements
};

// TODO: Implement these functions for array-based stack

void push(ArrayStack& stack, int value) {
    // Your code here
    // Remember to check if stack is full!
}

int pop(ArrayStack& stack) {
    // Your code here
    // Remember to check if stack is empty!
    return -1;  // Placeholder
}

int peek(ArrayStack stack) {
    // Your code here
    return -1;  // Placeholder
}

bool isEmpty(ArrayStack stack) {
    // Your code here
    return true;  // Placeholder
}

bool isFull(ArrayStack stack) {
    // Your code here
    return false;  // Placeholder
}

// ============================================
// PART 2: LINKED-LIST-BASED STACK
// ============================================

// TODO: Define your Stack struct for linked-list implementation
struct ListStack {
    // Your members here
    // Hint: Think about what a node contains
};

// TODO: Implement these functions for linked-list stack

void push(ListStack*& stack, int value) {
    // Your code here
    // Remember to allocate new memory with 'new'
}

int pop(ListStack*& stack) {
    // Your code here
    // Remember to check if empty and free memory with 'delete'
    return -1;  // Placeholder
}

int peek(const ListStack* stack) {
    // Your code here
    return -1;  // Placeholder
}

bool isEmpty(const ListStack* stack) {
    // Your code here
    return true;  // Placeholder
}

// ============================================
// TESTING CODE
// ============================================

void testArrayStack() {
    cout << "=== Testing Array-Based Stack ===" << endl;
    ArrayStack s;
    // TODO: Initialize your stack

    // TODO: Test your stack operations
    // - Push some values
    // - Peek at top
    // - Pop values
    // - Test empty/full conditions

    cout << "Array stack tests complete!" << endl;
}

void testListStack() {
    cout << "\n=== Testing Linked-List-Based Stack ===" << endl;
    ListStack* s = nullptr;  // Start with empty stack

    // TODO: Test your stack operations
    // Same tests as array version

    cout << "List stack tests complete!" << endl;
}

int main() {
    testArrayStack();
    testListStack();

    return 0;
}
