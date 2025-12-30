/*
 * 03-queue.cpp
 * The Queue ADT: First In, First Out (FIFO)
 *
 * Two implementations:
 * 1. Array-based (circular buffer)
 * 2. Linked list-based
 */

#include <iostream>
using namespace std;

// ============================================================
// ARRAY-BASED QUEUE (Circular Buffer)
// ============================================================

struct ArrayQueue {
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int front;  // Index of front element
    int back;   // Index of next insertion point
    int count;  // Number of elements
};

void initQueue(ArrayQueue& q) {
    q.front = 0;
    q.back = 0;
    q.count = 0;
}

bool isEmpty(const ArrayQueue& q) {
    return q.count == 0;
}

bool isFull(const ArrayQueue& q) {
    return q.count == ArrayQueue::MAX_SIZE;
}

void enqueue(ArrayQueue& q, int value) {
    if (isFull(q)) {
        cout << "Error: Queue is full!" << endl;
        return;
    }
    q.data[q.back] = value;
    q.back = (q.back + 1) % ArrayQueue::MAX_SIZE;  // Wrap around
    q.count++;
}

int dequeue(ArrayQueue& q) {
    if (isEmpty(q)) {
        cout << "Error: Queue is empty!" << endl;
        return -1;
    }
    int value = q.data[q.front];
    q.front = (q.front + 1) % ArrayQueue::MAX_SIZE;  // Wrap around
    q.count--;
    return value;
}

int front(const ArrayQueue& q) {
    if (isEmpty(q)) {
        cout << "Error: Queue is empty!" << endl;
        return -1;
    }
    return q.data[q.front];
}

void printQueue(const ArrayQueue& q) {
    cout << "Queue (front to back): ";
    for (int i = 0; i < q.count; i++) {
        int index = (q.front + i) % ArrayQueue::MAX_SIZE;
        cout << q.data[index] << " ";
    }
    cout << endl;
}

// ============================================================
// LINKED LIST-BASED QUEUE
// ============================================================

struct Node {
    int data;
    Node* next;
};

struct LinkedQueue {
    Node* frontPtr;  // Where we dequeue
    Node* backPtr;   // Where we enqueue
};

void initQueue(LinkedQueue& q) {
    q.frontPtr = nullptr;
    q.backPtr = nullptr;
}

bool isEmpty(const LinkedQueue& q) {
    return q.frontPtr == nullptr;
}

void enqueue(LinkedQueue& q, int value) {
    Node* newNode = new Node{value, nullptr};

    if (isEmpty(q)) {
        // First element
        q.frontPtr = newNode;
        q.backPtr = newNode;
    } else {
        // Add to back
        q.backPtr->next = newNode;
        q.backPtr = newNode;
    }
}

int dequeue(LinkedQueue& q) {
    if (isEmpty(q)) {
        cout << "Error: Queue is empty!" << endl;
        return -1;
    }

    Node* temp = q.frontPtr;
    int value = temp->data;
    q.frontPtr = q.frontPtr->next;

    // If queue is now empty, update backPtr too
    if (q.frontPtr == nullptr) {
        q.backPtr = nullptr;
    }

    delete temp;
    return value;
}

int front(const LinkedQueue& q) {
    if (isEmpty(q)) {
        cout << "Error: Queue is empty!" << endl;
        return -1;
    }
    return q.frontPtr->data;
}

void deleteQueue(LinkedQueue& q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

void printQueue(const LinkedQueue& q) {
    cout << "Queue (front to back): ";
    Node* current = q.frontPtr;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// ============================================================
// DEMONSTRATION
// ============================================================

void demoArrayQueue() {
    cout << "=== Array-Based Queue (Circular Buffer) ===" << endl;

    ArrayQueue q;
    initQueue(q);

    cout << "Enqueue 10, 20, 30:" << endl;
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);

    cout << "Front: " << front(q) << endl;

    cout << "Dequeue: " << dequeue(q) << endl;
    printQueue(q);

    cout << "Enqueue 40, 50:" << endl;
    enqueue(q, 40);
    enqueue(q, 50);
    printQueue(q);

    cout << "Dequeue all:" << endl;
    while (!isEmpty(q)) {
        cout << "  " << dequeue(q) << endl;
    }
    cout << "Is empty? " << (isEmpty(q) ? "Yes" : "No") << endl;
    cout << endl;
}

void demoLinkedQueue() {
    cout << "=== Linked List-Based Queue ===" << endl;

    LinkedQueue q;
    initQueue(q);

    cout << "Enqueue 100, 200, 300:" << endl;
    enqueue(q, 100);
    enqueue(q, 200);
    enqueue(q, 300);
    printQueue(q);

    cout << "Front: " << front(q) << endl;

    cout << "Dequeue: " << dequeue(q) << endl;
    printQueue(q);

    cout << "Enqueue 400, 500:" << endl;
    enqueue(q, 400);
    enqueue(q, 500);
    printQueue(q);

    cout << "Dequeue all:" << endl;
    while (!isEmpty(q)) {
        cout << "  " << dequeue(q) << endl;
    }
    cout << "Is empty? " << (isEmpty(q) ? "Yes" : "No") << endl;

    deleteQueue(q);  // Safe even if already empty
    cout << endl;
}

void demoTicketQueue() {
    cout << "=== Simulation: Ticket Queue ===" << endl;

    LinkedQueue q;
    initQueue(q);

    // People take numbers
    cout << "Customers arriving and taking numbers:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "  Customer takes ticket #" << i << endl;
        enqueue(q, i);
    }
    printQueue(q);

    // Service some customers
    cout << "Serving customers:" << endl;
    for (int i = 0; i < 3; i++) {
        int ticket = dequeue(q);
        cout << "  Now serving ticket #" << ticket << endl;
    }
    printQueue(q);

    // More arrive
    cout << "More customers arrive:" << endl;
    enqueue(q, 6);
    enqueue(q, 7);
    printQueue(q);

    deleteQueue(q);
}

int main() {
    demoArrayQueue();
    demoLinkedQueue();
    demoTicketQueue();

    cout << "=== Comparison ===" << endl;
    cout << "Array Queue (Circular Buffer):" << endl;
    cout << "  + Simple, cache-friendly" << endl;
    cout << "  + O(1) all operations" << endl;
    cout << "  - Fixed maximum size" << endl;
    cout << "  - Slightly tricky wrap-around logic" << endl;
    cout << endl;
    cout << "Linked Queue:" << endl;
    cout << "  + Grows dynamically" << endl;
    cout << "  + O(1) all operations (with tail pointer)" << endl;
    cout << "  - Extra memory for pointers" << endl;
    cout << "  - Must manage memory" << endl;

    return 0;
}
