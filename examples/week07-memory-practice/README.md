# Week 7: Memory Practice (Not Leaking Everything)

Last week you learned to allocate and free memory. This week, we practice *not messing it up*.

Dynamic memory is powerful, but it comes with responsibilities. Get it wrong, and your program might:
- Leak memory (slowly consuming all available RAM)
- Crash from accessing freed memory
- Behave unpredictably due to corrupted data

Let's look at common pitfalls and how to avoid them.

## The Rogues' Gallery of Memory Bugs

### 1. Memory Leaks

Memory you allocate but never free:

```cpp
void processData() {
    int* data = new int[1000];
    // Do stuff with data...

    if (errorCondition) {
        return;  // LEAK! We never deleted data
    }

    delete[] data;  // Only reached if no error
}
```

**The fix:** Ensure every path through the function frees the memory.

### 2. Use After Free (Dangling Pointers)

Using memory after you've freed it:

```cpp
int* ptr = new int(42);
delete ptr;
cout << *ptr;  // DANGER: ptr is now dangling!
```

**The fix:** Set pointers to `nullptr` after deleting, and check before using.

### 3. Double Free

Freeing the same memory twice:

```cpp
int* ptr = new int(42);
delete ptr;
delete ptr;  // CRASH (probably)
```

**The fix:** Set to `nullptr` after deleting. `delete nullptr` is safe (does nothing).

### 4. Mismatched new/delete

Using `delete` for `new[]` or vice versa:

```cpp
int* arr = new int[10];
delete arr;  // WRONG! Should be delete[]
```

**The fix:** Be consistent. `new` pairs with `delete`, `new[]` pairs with `delete[]`.

### 5. Returning Local Stack Addresses

Returning a pointer to a local variable:

```cpp
int* badFunction() {
    int local = 42;
    return &local;  // DANGER: local disappears when function returns!
}
```

**The fix:** Return dynamically allocated memory (caller must free), or return by value.

## Defensive Programming Patterns

### Pattern 1: Initialize to nullptr

```cpp
int* ptr = nullptr;  // Start as null
// ... later ...
ptr = new int[size];
// ... use ptr ...
if (ptr != nullptr) {
    delete[] ptr;
    ptr = nullptr;
}
```

### Pattern 2: Check Before Use

```cpp
if (ptr != nullptr) {
    cout << *ptr << endl;
} else {
    cout << "Pointer is null!" << endl;
}
```

### Pattern 3: Resource Acquisition Is Initialization (RAII) - Preview

In more advanced C++, we wrap resources in objects that clean up automatically:

```cpp
// Smart pointer (C++11) - we'll see this in CS162
std::unique_ptr<int[]> arr(new int[100]);
// Automatically deleted when arr goes out of scope
```

For now, just be aware this exists. We'll stick to manual memory management to learn the fundamentals.

### Pattern 4: Single Owner Principle

Have one clear owner for each piece of memory:
- The owner allocates
- The owner frees
- Others just borrow (receive pointers, but don't delete)

## Debugging Memory Issues

### Symptoms of Memory Bugs

- Program works sometimes, crashes other times
- Strange values appearing in variables
- Program slows down over time (memory leak)
- Crash on exit

### Using Valgrind

On Linux, `valgrind` is a tool that detects memory errors:

```bash
g++ -g program.cpp -o program
valgrind ./program
```

It will report:
- Memory leaks
- Invalid reads/writes
- Use of uninitialized memory

Learn to use valgrind. It will save you hours of debugging.

## The Examples

1. **01-memory-pitfalls.cpp** - Common mistakes demonstrated (safely)
2. **02-cleanup-patterns.cpp** - Patterns for reliable memory management
3. **03-nullptr-after-delete.cpp** - Setting a pointer to `nullptr` after delete
4. **04-early-return-cleanup.cpp** - Cleaning up before an early return

## Exercises

### Basic
1. Write a function that allocates an array, but has multiple return paths. Ensure no leaks.
2. Practice using valgrind on a simple program.

### Intermediate
3. Write a "safe array" set of functions:
   - `int* createArray(int size)`
   - `void freeArray(int*& arr)` - sets arr to nullptr after freeing
4. Create a program with an intentional memory leak, then fix it.

### Challenge
5. Implement a simple "memory pool": pre-allocate a large block, and hand out pieces of it.

## Mini-Project: Memory-Safe Dynamic String

Build a set of functions for handling dynamically-allocated strings safely.

**Requirements:**
1. `char* createString(int capacity)` - Allocate a string buffer
2. `void freeString(char*& str)` - Free and set to nullptr
3. `char* copyString(const char* src)` - Allocate and copy
4. `char* concatenate(const char* a, const char* b)` - Allocate and combine
5. `void resizeString(char*& str, int newCapacity)` - Grow/shrink the buffer

**Important:** Every function should handle edge cases:
- Null pointer inputs
- Zero-size requests
- Ensuring null termination

Test with valgrind to verify no leaks!

A starter file is in `mini-project/safe_strings.cpp`.

---

Memory management is a skill that takes practice. Make mistakes, use valgrind, learn from the errors.

*The computer forgives nothing, but you'll get better.*
