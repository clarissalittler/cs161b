/*
 * 02-stack.cpp
 * The Stack ADT: Last In, First Out (LIFO)
 *
 * Two implementations:
 * 1. Array-based
 * 2. Linked list-based
 */

#include <iostream>
using namespace std;

// ============================================================
// ARRAY-BASED STACK
// ============================================================

struct ArrayStack {
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int top;  // Index of top element (-1 if empty)
};

void initStack(ArrayStack& s) {
    s.top = -1;
}

bool isEmpty(const ArrayStack& s) {
    return s.top == -1;
}

bool isFull(const ArrayStack& s) {
    return s.top == ArrayStack::MAX_SIZE - 1;
}

void push(ArrayStack& s, int value) {
    if (isFull(s)) {
        cout << "Error: Stack overflow!" << endl;
        return;
    }
    s.top++;
    s.data[s.top] = value;
}

int pop(ArrayStack& s) {
    if (isEmpty(s)) {
        cout << "Error: Stack underflow!" << endl;
        return -1;
    }
    int value = s.data[s.top];
    s.top--;
    return value;
}

int peek(const ArrayStack& s) {
    if (isEmpty(s)) {
        cout << "Error: Stack is empty!" << endl;
        return -1;
    }
    return s.data[s.top];
}

void printStack(const ArrayStack& s) {
    cout << "Stack (top first): ";
    for (int i = s.top; i >= 0; i--) {
        cout << s.data[i] << " ";
    }
    cout << endl;
}

// ============================================================
// LINKED LIST-BASED STACK
// ============================================================

struct Node {
    int data;
    Node* next;
};

struct LinkedStack {
    Node* top;  // Pointer to top node (nullptr if empty)
};

void initStack(LinkedStack& s) {
    s.top = nullptr;
}

bool isEmpty(const LinkedStack& s) {
    return s.top == nullptr;
}

void push(LinkedStack& s, int value) {
    // Create new node pointing to current top
    Node* newNode = new Node{value, s.top};
    s.top = newNode;
}

int pop(LinkedStack& s) {
    if (isEmpty(s)) {
        cout << "Error: Stack underflow!" << endl;
        return -1;
    }
    Node* temp = s.top;
    int value = temp->data;
    s.top = s.top->next;
    delete temp;
    return value;
}

int peek(const LinkedStack& s) {
    if (isEmpty(s)) {
        cout << "Error: Stack is empty!" << endl;
        return -1;
    }
    return s.top->data;
}

void deleteStack(LinkedStack& s) {
    while (s.top != nullptr) {
        Node* temp = s.top;
        s.top = s.top->next;
        delete temp;
    }
}

void printStack(const LinkedStack& s) {
    cout << "Stack (top first): ";
    Node* current = s.top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// ============================================================
// DEMONSTRATION
// ============================================================

void demoArrayStack() {
    cout << "=== Array-Based Stack ===" << endl;

    ArrayStack s;
    initStack(s);

    cout << "Pushing 10, 20, 30:" << endl;
    push(s, 10);
    push(s, 20);
    push(s, 30);
    printStack(s);

    cout << "Peek: " << peek(s) << endl;

    cout << "Pop: " << pop(s) << endl;
    printStack(s);

    cout << "Pop: " << pop(s) << endl;
    printStack(s);

    cout << "Is empty? " << (isEmpty(s) ? "Yes" : "No") << endl;

    cout << "Pop: " << pop(s) << endl;
    cout << "Is empty? " << (isEmpty(s) ? "Yes" : "No") << endl;
    cout << endl;
}

void demoLinkedStack() {
    cout << "=== Linked List-Based Stack ===" << endl;

    LinkedStack s;
    initStack(s);

    cout << "Pushing 100, 200, 300:" << endl;
    push(s, 100);
    push(s, 200);
    push(s, 300);
    printStack(s);

    cout << "Peek: " << peek(s) << endl;

    cout << "Pop: " << pop(s) << endl;
    printStack(s);

    cout << "Pop: " << pop(s) << endl;
    printStack(s);

    cout << "Is empty? " << (isEmpty(s) ? "Yes" : "No") << endl;

    cout << "Pop: " << pop(s) << endl;
    cout << "Is empty? " << (isEmpty(s) ? "Yes" : "No") << endl;

    // Clean up
    deleteStack(s);
    cout << endl;
}

void demoReverseString() {
    cout << "=== Using Stack to Reverse a String ===" << endl;

    string input = "Hello";
    LinkedStack s;
    initStack(s);

    // Push each character
    for (char c : input) {
        push(s, c);
    }

    // Pop to get reversed
    cout << "Original: " << input << endl;
    cout << "Reversed: ";
    while (!isEmpty(s)) {
        cout << (char)pop(s);
    }
    cout << endl;
}

int main() {
    demoArrayStack();
    demoLinkedStack();
    demoReverseString();

    cout << "=== Comparison ===" << endl;
    cout << "Array Stack:" << endl;
    cout << "  + Simple, cache-friendly" << endl;
    cout << "  + O(1) all operations" << endl;
    cout << "  - Fixed maximum size" << endl;
    cout << endl;
    cout << "Linked Stack:" << endl;
    cout << "  + Grows dynamically" << endl;
    cout << "  + O(1) all operations" << endl;
    cout << "  - Extra memory for pointers" << endl;
    cout << "  - Must manage memory" << endl;

    return 0;
}
