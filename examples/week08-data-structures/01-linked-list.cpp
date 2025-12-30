/*
 * 01-linked-list.cpp
 * Introduction to linked lists.
 *
 * A linked list stores elements as separate "nodes" connected by pointers.
 * Unlike arrays, the elements aren't contiguous in memory.
 */

#include <iostream>
using namespace std;

// A node in our linked list
struct Node {
    int data;       // The value stored
    Node* next;     // Pointer to the next node
};

// ============================================================
// HELPER FUNCTIONS
// ============================================================

// Print the entire list
void printList(Node* head) {
    cout << "List: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << " -> nullptr" << endl;
}

// Count elements in the list
int listLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Insert at the beginning (returns new head)
Node* insertFront(Node* head, int value) {
    Node* newNode = new Node{value, head};
    return newNode;
}

// Insert at the end
void insertEnd(Node* head, int value) {
    // Find the last node
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    // Create new node and link it
    current->next = new Node{value, nullptr};
}

// Delete the entire list
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Search for a value
bool contains(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

// ============================================================
// MAIN
// ============================================================

int main() {
    cout << "=== Linked List Basics ===" << endl << endl;

    // Create an empty list
    Node* head = nullptr;
    cout << "Empty list:" << endl;
    printList(head);
    cout << endl;

    // Insert at front (builds list backwards)
    cout << "=== Inserting at front ===" << endl;
    head = insertFront(head, 30);
    printList(head);
    head = insertFront(head, 20);
    printList(head);
    head = insertFront(head, 10);
    printList(head);
    cout << "Length: " << listLength(head) << endl;
    cout << endl;

    // Insert at end
    cout << "=== Inserting at end ===" << endl;
    insertEnd(head, 40);
    printList(head);
    insertEnd(head, 50);
    printList(head);
    cout << "Length: " << listLength(head) << endl;
    cout << endl;

    // Search
    cout << "=== Searching ===" << endl;
    cout << "Contains 30? " << (contains(head, 30) ? "Yes" : "No") << endl;
    cout << "Contains 99? " << (contains(head, 99) ? "Yes" : "No") << endl;
    cout << endl;

    // Manual traversal with modification
    cout << "=== Doubling all values ===" << endl;
    Node* current = head;
    while (current != nullptr) {
        current->data *= 2;
        current = current->next;
    }
    printList(head);
    cout << endl;

    // Clean up
    cout << "=== Cleanup ===" << endl;
    deleteList(head);
    cout << "After deleteList, head = " << head << endl;
    printList(head);

    return 0;
}

/*
 * Key points:
 *
 * 1. A linked list is made of nodes connected by pointers
 *
 * 2. We only store the "head" pointer - the first node
 *
 * 3. To traverse: start at head, follow next pointers until nullptr
 *
 * 4. Insert at front is O(1) - just update head
 *
 * 5. Insert at end is O(n) - must traverse to find the end
 *
 * 6. Always clean up by deleting all nodes!
 *
 * 7. nullptr marks the end of the list
 */
