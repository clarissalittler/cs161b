/*
 * 02-class-templates.cpp
 * Template structs (a preview of template classes).
 *
 * Just like function templates, we can make structs work with any type.
 */

#include <iostream>
#include <string>
using namespace std;

// ============================================================
// SIMPLE TEMPLATE STRUCT: PAIR
// ============================================================

// A pair holds two values of potentially different types
template <typename T, typename U>
struct Pair {
    T first;
    U second;
};

// Functions that work with Pair
template <typename T, typename U>
void printPair(const Pair<T, U>& p) {
    cout << "(" << p.first << ", " << p.second << ")" << endl;
}

template <typename T, typename U>
Pair<T, U> makePair(T a, U b) {
    Pair<T, U> p;
    p.first = a;
    p.second = b;
    return p;
}

// ============================================================
// TEMPLATE STRUCT: DYNAMIC ARRAY
// ============================================================

// A simple dynamic array that works with any type
template <typename T>
struct DynamicArray {
    T* data;
    int size;
    int capacity;
};

template <typename T>
void initArray(DynamicArray<T>& arr, int cap) {
    arr.data = new T[cap];
    arr.size = 0;
    arr.capacity = cap;
}

template <typename T>
void freeArray(DynamicArray<T>& arr) {
    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
    arr.capacity = 0;
}

template <typename T>
void append(DynamicArray<T>& arr, T value) {
    if (arr.size < arr.capacity) {
        arr.data[arr.size] = value;
        arr.size++;
    } else {
        cout << "Array is full!" << endl;
    }
}

template <typename T>
T get(const DynamicArray<T>& arr, int index) {
    if (index >= 0 && index < arr.size) {
        return arr.data[index];
    }
    return T();  // Default value
}

template <typename T>
void printArray(const DynamicArray<T>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i];
        if (i < arr.size - 1) cout << ", ";
    }
    cout << "] (size=" << arr.size << ", capacity=" << arr.capacity << ")" << endl;
}

// ============================================================
// TEMPLATE STRUCT: LINKED LIST NODE
// ============================================================

template <typename T>
struct Node {
    T data;
    Node<T>* next;  // Note: Node<T>*, not just Node*
};

template <typename T>
Node<T>* createNode(T value) {
    Node<T>* n = new Node<T>;
    n->data = value;
    n->next = nullptr;
    return n;
}

template <typename T>
void printList(Node<T>* head) {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

template <typename T>
void deleteList(Node<T>*& head) {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

// ============================================================
// DEMONSTRATION
// ============================================================

int main() {
    cout << "=== Template Structs ===" << endl << endl;

    // Pair example
    cout << "=== Pair<T, U> ===" << endl;

    Pair<int, string> student;
    student.first = 12345;
    student.second = "Alice";
    cout << "Student: ";
    printPair(student);

    Pair<string, double> product = makePair(string("Widget"), 19.99);
    cout << "Product: ";
    printPair(product);
    cout << endl;

    // DynamicArray example
    cout << "=== DynamicArray<T> ===" << endl;

    DynamicArray<int> intArray;
    initArray(intArray, 5);

    append(intArray, 10);
    append(intArray, 20);
    append(intArray, 30);
    cout << "Int array: ";
    printArray(intArray);
    cout << "Element at index 1: " << get(intArray, 1) << endl;
    freeArray(intArray);
    cout << endl;

    DynamicArray<string> strArray;
    initArray(strArray, 3);

    append(strArray, string("apple"));
    append(strArray, string("banana"));
    cout << "String array: ";
    printArray(strArray);
    freeArray(strArray);
    cout << endl;

    // Linked list example
    cout << "=== Node<T> (Linked List) ===" << endl;

    Node<int>* intList = createNode(10);
    intList->next = createNode(20);
    intList->next->next = createNode(30);
    cout << "Int list: ";
    printList(intList);
    deleteList(intList);

    Node<char>* charList = createNode('A');
    charList->next = createNode('B');
    charList->next->next = createNode('C');
    cout << "Char list: ";
    printList(charList);
    deleteList(charList);

    return 0;
}

/*
 * Key points:
 *
 * 1. Template structs work like template functions
 *
 * 2. When declaring variables, specify the type:
 *    DynamicArray<int> arr;
 *    Node<string>* head;
 *
 * 3. Member functions must also be templates
 *
 * 4. Self-referential templates use the full type:
 *    Node<T>* next;  (not just Node*)
 *
 * 5. This is a preview of template classes (CS162)
 *    Classes add: constructors, destructors, encapsulation
 */
