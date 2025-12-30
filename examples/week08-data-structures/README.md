# Week 8: Data Structures (Beyond Arrays)

Arrays are great, but they have limitations:
- Fixed size (or awkward resizing)
- Inserting/removing in the middle is expensive (shift everything!)
- Can't easily grow and shrink

This week, we meet **linked lists**—a different way to organize data. From linked lists, we'll build **stacks** and **queues**, two fundamental data structures.

## The Linked List Idea

Instead of storing elements contiguously in memory, we connect them with pointers:

```
[ data | next ] ---> [ data | next ] ---> [ data | next ] ---> nullptr
```

Each element (called a "node") contains:
1. The data we want to store
2. A pointer to the next node

```cpp
struct Node {
    int data;
    Node* next;
};
```

Yes, a struct can contain a pointer to its own type. This is called a **self-referential structure**.

## Why Linked Lists?

| Operation | Array | Linked List |
|-----------|-------|-------------|
| Access element i | O(1) - instant | O(n) - must traverse |
| Insert at beginning | O(n) - shift all | O(1) - instant |
| Insert at end | O(1) if space | O(n) unless we track tail |
| Insert in middle | O(n) - shift | O(1) once you're there |
| Memory | Contiguous block | Scattered nodes |

Linked lists shine when you frequently insert/remove at the front, or when you don't know the size ahead of time.

## Building a Linked List

```cpp
// Create nodes
Node* first = new Node{10, nullptr};
Node* second = new Node{20, nullptr};
Node* third = new Node{30, nullptr};

// Link them
first->next = second;
second->next = third;

// Traverse
Node* current = first;
while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
}
// Output: 10 20 30
```

## Abstract Data Types

An **Abstract Data Type (ADT)** defines *what* operations are available, not *how* they're implemented.

### Stack (LIFO - Last In, First Out)

Think of a stack of plates:
- **push**: Add to top
- **pop**: Remove from top
- **peek/top**: Look at top without removing
- **isEmpty**: Check if empty

```
push(1): [1]
push(2): [1, 2]
push(3): [1, 2, 3]
pop():   [1, 2] (returns 3)
peek():  returns 2 (stack unchanged)
```

### Queue (FIFO - First In, First Out)

Think of a line at a store:
- **enqueue**: Add to back
- **dequeue**: Remove from front
- **front**: Look at front
- **isEmpty**: Check if empty

```
enqueue(1): [1]
enqueue(2): [1, 2]
enqueue(3): [1, 2, 3]
dequeue():  [2, 3] (returns 1)
front():    returns 2 (queue unchanged)
```

## Implementations

The cool thing about ADTs: you can implement them different ways!

**Stack:**
- Array-based: Use an array with a "top" index
- Linked list: Push/pop at the head

**Queue:**
- Array-based: Circular buffer with front/back indices
- Linked list: Enqueue at tail, dequeue from head

We'll explore both implementations to understand the tradeoffs.

## The Examples

1. **01-linked-list.cpp** - Building and traversing a linked list
2. **02-stack.cpp** - Stack implementations (array and linked list)
3. **03-queue.cpp** - Queue implementations

## Exercises

### Basic
1. Create a linked list of 5 integers and print them
2. Implement `isEmpty()` for a stack

### Intermediate
3. Write a function to find the length of a linked list
4. Use a stack to reverse a string
5. Use a queue to implement a simple "take a number" system

### Challenge
6. Implement a function to reverse a linked list in place
7. Use two stacks to implement a queue

## Mini-Project: Expression Evaluator

Build a calculator that evaluates postfix (Reverse Polish Notation) expressions using a stack.

**Postfix notation:**
Instead of `3 + 4`, we write `3 4 +`.
Instead of `(3 + 4) * 2`, we write `3 4 + 2 *`.

**Algorithm:**
1. Read tokens left to right
2. If number: push onto stack
3. If operator: pop two numbers, apply operator, push result
4. At end: the stack contains the answer

**Examples:**
- `5 3 +` → 8
- `4 2 *` → 8
- `3 4 + 2 *` → 14
- `10 2 / 3 +` → 8

A starter file is in `mini-project/postfix_calculator.cpp`.

---

Data structures are the foundation of computer science. Understanding how to build them—not just use them—makes you a better programmer.

*Next: we'll practice debugging the inevitable bugs.*
