# Assignment 4: Implementing a Stack with Arrays and Linked Lists in C++

## Objective

In this assignment, you will explore two fundamental data structures: **arrays** and **linked lists**, by implementing a stack using both methods. This is an extension of things I've already shown you how to do in class and you can re-use a lot of examples provided in the course repo, but you're going to be combining them in new ways! The purpose of this assignment is to:

1. Deepen your understanding of stack operations (push, pop, peek, and isEmpty).
2. Compare and contrast array-based and linked-list-based implementations of stacks.
3. Practice writing clean, modular C++ code.

## Tasks

You are required to complete the following tasks:

### Part 1: Array-Based Stack Implementation

1. **Define a `Stack` struct** that uses a fixed-size array to store stack elements.

2. Implement the following functions:
   - `void push(Stack &stack, int value)`: Add an element to the top of the stack. Print an error message if the stack is full.
   - `int pop(Stack &stack)`: Remove and return the top element of the stack. Print an error message if the stack is empty.
   - `int peek(Stack stack)`: Return the top element of the stack without removing it. Print an error message if the stack is empty.
   - `bool isEmpty(Stack stack)`: Return `true` if the stack is empty, otherwise return `false`.
   - `bool isFull(Stack stack)`: Return `true` if the stack is full, otherwise return `false`.

3. Test your implementation by:
   - Initializing a stack of size 10.
   - Performing a sequence of operations (e.g., pushing, popping, and peeking).

### Part 2: Linked-List-Based Stack Implementation

1. **Define a `Stack` struct** with two members:
   - `int value`: The data stored in the node.
   - `Stack* next`: A pointer to the next node in the stack.

2. Implement the following functions:
   - `void push(Stack&* stack, int value)`: Add an element to the top of the stack.
   - `int pop(Stack&* stack)`: Remove and return the top element of the stack. Print an error message if the stack is empty.
   - `int peek(const Stack* stack)`: Return the top element of the stack without removing it. Print an error message if the stack is empty.
   - `bool isEmpty(const Stack* stack)`: Return `true` if the stack is empty, otherwise return `false`.

3. Test your implementation by:
   - Performing a sequence of operations on the stack (e.g., pushing, popping, and peeking).

## Hints (examples in the repo)

- Array-backed queue structure (adapt to stack): [examples-from-videos/week8/arrayQueue.cpp](../examples-from-videos/week8/arrayQueue.cpp)
- Linked-list queue structure (adapt to stack): [examples-from-videos/week8/listQueue.cpp](../examples-from-videos/week8/listQueue.cpp)
- Stack/queue notes from lecture: [examples-from-videos/week8/agenda.org](../examples-from-videos/week8/agenda.org)

## Reflection Questions

Include answers to the following reflection questions as part of your submission. A couple of sentences per question is sufficient.

1. **Initial Approach:**
   - *How did you begin working on this assignment—did you plan or sketch out a design first, or did you jump straight into coding? Briefly explain why you took that approach.*

2. **Challenges & Problem-Solving:**
   - *What was the most challenging aspect of the assignment, and how did you address it?*

3. **Testing & Debugging:**
   - *How did you test your code, and can you describe one example of a bug you discovered and how you fixed it?*

4. **Design & Structure Improvements:**
   - *If you had more time, what would you change in your code's structure or style to improve clarity or maintainability?*

5. **Conceptual Understanding:**
   - *Compare and contrast what was difficult to implement for array-based stacks and for list-based stacks!*

## Grading Policy

This assignment will be graded out of 4:

- **4**: The assignment is bug-free, meets all requirements, and includes completed reflection questions.
- **3**: The assignment meets requirements but may include minor bugs or does not include completed reflection questions.
- **2**: The assignment is incomplete or contains significant errors.
- **1**: The submission shows minimal effort or is largely non-functional.
- **0**: No submission.

If the reflection questions are not turned in, the **highest grade you can receive is a 3**.

Good luck, and happy coding!
