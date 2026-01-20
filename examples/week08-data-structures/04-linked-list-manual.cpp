/*
 * 04-linked-list-manual.cpp
 * Manually linking nodes in a simple list.
 */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* first = new Node{1, nullptr};
    Node* second = new Node{2, nullptr};
    Node* third = new Node{3, nullptr};

    first->next = second;
    second->next = third;

    cout << "List: ";
    for (Node* current = first; current != nullptr; current = current->next) {
        cout << current->data << " ";
    }
    cout << endl;

    delete third;
    delete second;
    delete first;

    return 0;
}
