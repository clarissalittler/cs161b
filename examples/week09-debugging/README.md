# Week 9: Debugging (Finding What's Broken)

Your program doesn't work. It compiles fine, but it's doing something wrong. Maybe it crashes. Maybe it gives the wrong answer. Maybe it hangs forever.

Welcome to debugging.

Debugging is a skill that improves with practice. This week, we'll cover strategies and tools to help you find and fix bugs.

## The Debugging Mindset

1. **Bugs are not random.** Computers do exactly what you tell them. If the output is wrong, your code told it to do the wrong thing.

2. **Read the error message.** Compiler errors, runtime errors, and crash messages contain clues. Read them carefully.

3. **Reproduce first.** Before fixing, make sure you can reliably reproduce the bug. Random "fixes" to unreproducible bugs just mask the problem.

4. **Isolate the problem.** Narrow down where the bug is. Which function? Which line? Which variable?

5. **Change one thing at a time.** If you change three things and the bug goes away, you don't know which change fixed it.

## Types of Bugs

### Compile-Time Errors
The compiler catches these. They're annoying but actually helpful.

Common causes:
- Typos in variable/function names
- Missing semicolons
- Type mismatches
- Missing includes

### Runtime Errors
The program crashes while running.

Common causes:
- Null pointer dereference
- Array out of bounds
- Division by zero
- Stack overflow (infinite recursion)

### Logic Errors
The program runs but gives wrong results.

Common causes:
- Off-by-one errors
- Wrong operator (< vs <=, = vs ==)
- Wrong order of operations
- Incorrect algorithm

## Debugging Strategies

### 1. Print Debugging (cout statements)

The simplest technique. Add print statements to see what's happening:

```cpp
cout << "DEBUG: x = " << x << endl;
cout << "DEBUG: Entering function foo()" << endl;
cout << "DEBUG: Array values: ";
for (int i = 0; i < n; i++) cout << arr[i] << " ";
cout << endl;
```

Remove them (or wrap in `#ifdef DEBUG`) before submitting.

### 2. Rubber Duck Debugging

Explain your code, line by line, to an inanimate object (or a patient friend). The act of explaining often reveals the bug.

"First I read the number... then I put it in the array... wait, I didn't increment the counter!"

### 3. Binary Search

If you have a lot of code, narrow down the bug's location:
1. Put a print statement in the middle
2. Does the bug happen before or after?
3. Repeat in the relevant half

### 4. Minimal Reproduction

Simplify the code until you have the smallest program that shows the bug. Often the bug becomes obvious in the minimal case.

### 5. Step Through with a Debugger

GDB (GNU Debugger) lets you:
- Run your program line by line
- Inspect variable values at any point
- Set breakpoints to stop at specific lines
- Watch variables change

Basic GDB commands:
```bash
g++ -g program.cpp -o program   # Compile with debug info
gdb ./program                    # Start debugger

(gdb) break main                 # Set breakpoint at main
(gdb) run                        # Start the program
(gdb) next                       # Execute next line
(gdb) step                       # Step into function call
(gdb) print x                    # Show value of x
(gdb) continue                   # Run until next breakpoint
(gdb) quit                       # Exit debugger
```

## Common Bug Patterns

### Off-by-One
```cpp
// Wrong: goes one past the end
for (int i = 0; i <= n; i++) {  // Should be i < n
    arr[i] = 0;
}
```

### Uninitialized Variables
```cpp
int sum;  // Random garbage value!
for (int i = 0; i < n; i++) {
    sum += arr[i];  // Adding to garbage
}
// Fix: int sum = 0;
```

### Wrong Comparison
```cpp
if (x = 5) {  // Assignment, not comparison!
    // This always "succeeds" and sets x to 5
}
// Fix: if (x == 5)
```

### Pointer Not Checked
```cpp
Node* ptr = findNode(value);
cout << ptr->data;  // Crash if ptr is nullptr!
// Fix: if (ptr != nullptr) { ... }
```

### Array Index Confusion
```cpp
for (int i = 1; i <= n; i++) {
    arr[i] = i;  // Off by one - what about arr[0]?
}
```

## The Examples

1. **01-common-bugs.cpp** - Examples of common bugs and their fixes
2. **02-gdb-practice.cpp** - A buggy program to practice debugging with GDB

## Exercises

### Basic
1. Find and fix the bug in `buggy1.cpp`
2. Add print statements to trace execution in a broken function

### Intermediate
3. Use GDB to find the bug in `buggy2.cpp`
4. Write a program with an intentional bug, then have a friend find it

### Challenge
5. Debug a program with multiple interconnected bugs

## Mini-Project: Bug Hunt

I've written a "working" sorting program that has exactly 5 bugs. Your mission: find and fix all of them.

The program should:
1. Read numbers from the user
2. Sort them in ascending order
3. Print the sorted result

But it doesn't work correctly. Use whatever debugging techniques you need.

The buggy program is in `mini-project/buggy_sort.cpp`. A working reference is in `mini-project/sort_solution.cpp` (but try to fix it yourself first!).

---

Everyone writes bugs. Good programmers learn to find them efficiently.

*Debug methodically, not randomly.*
