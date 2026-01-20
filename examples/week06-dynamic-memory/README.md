# Week 6: Dynamic Memory (Asking for Memory at Runtime)

Up to now, all our arrays have been "static"—their size is fixed at compile time:

```cpp
int scores[100];  // Always 100 elements, whether we use them or not
```

But what if you don't know how many elements you need until the program runs? What if the user could have 10 items or 10,000?

This week, we learn to ask the operating system for memory *while the program is running*. This is called **dynamic memory allocation**.

## The Problem with Static Arrays

```cpp
const int MAX = 100;
int data[MAX];
int count;

cout << "How many numbers? ";
cin >> count;  // What if they say 200? Or 5?
```

With static arrays:
- If they need more than MAX, you're stuck
- If they need much less, you're wasting memory
- The size is baked into your code

## `new` and `delete`: The Dynamic Duo

In C++, we request memory with `new` and release it with `delete`:

```cpp
// Request memory for one integer
int* ptr = new int;
*ptr = 42;
cout << *ptr << endl;  // 42

// Release the memory when done
delete ptr;
```

For arrays, use `new[]` and `delete[]`:

```cpp
// Request memory for n integers
int n = 100;
int* arr = new int[n];

// Use it like a regular array
arr[0] = 10;
arr[99] = 20;

// Release the memory
delete[] arr;
```

**Critical:** Every `new` needs a matching `delete`. Every `new[]` needs a matching `delete[]`. Forget this, and you have a **memory leak**—memory that's reserved but never returned.

## Why Pointers?

When you use `new`, the operating system finds a chunk of memory somewhere and gives you its address. That's why `new` returns a pointer—it's telling you "I found memory for you; here's where it is."

You access the memory through that pointer. And when you're done, you use `delete` to tell the OS "I'm done with this memory; you can reuse it."

## Dynamic Arrays in Practice

```cpp
int size;
cout << "How many scores? ";
cin >> size;

// Allocate exactly what we need
int* scores = new int[size];

// Use the array
for (int i = 0; i < size; i++) {
    cout << "Score " << (i + 1) << ": ";
    cin >> scores[i];
}

// Process it
int sum = 0;
for (int i = 0; i < size; i++) {
    sum += scores[i];
}
cout << "Average: " << (double)sum / size << endl;

// Don't forget to clean up!
delete[] scores;
```

## 2D Dynamic Arrays

Here's where it gets interesting. A 2D dynamic array is actually an array of pointers, each pointing to a row:

```cpp
int rows = 3;
int cols = 4;

// Allocate the row pointers
int** grid = new int*[rows];

// Allocate each row
for (int i = 0; i < rows; i++) {
    grid[i] = new int[cols];
}

// Use it: grid[row][col]
grid[1][2] = 42;

// Clean up (in reverse order!)
for (int i = 0; i < rows; i++) {
    delete[] grid[i];  // Delete each row first
}
delete[] grid;  // Then delete the row pointers
```

Yes, this is more complex than static 2D arrays. But now your grid can be any size, determined at runtime.

## The Golden Rules

1. **Every `new` needs a `delete`**
   Forget and you leak memory.

2. **Every `new[]` needs a `delete[]`**
   Using `delete` on a `new[]` result is undefined behavior.

3. **Don't use memory after deleting it**
   The pointer becomes invalid. This is called a "dangling pointer."

4. **Don't delete the same memory twice**
   Also undefined behavior. Usually crashes.

5. **Set pointers to `nullptr` after deleting**
   Helps prevent accidents:
   ```cpp
   delete ptr;
   ptr = nullptr;  // Now clearly invalid
   ```

## When Things Go Wrong

### Memory Leak
```cpp
void leaky() {
    int* data = new int[1000];
    // Oops, we return without deleting!
    // The memory is lost forever (until program ends)
}
```

### Dangling Pointer
```cpp
int* ptr = new int(42);
delete ptr;
cout << *ptr;  // DANGER: ptr points to freed memory!
```

### Double Delete
```cpp
int* ptr = new int(42);
delete ptr;
delete ptr;  // CRASH (probably)
```

## The Examples

1. **01-new-delete.cpp** - Basic dynamic allocation
2. **02-dynamic-arrays.cpp** - Arrays of runtime-determined size
3. **03-2d-dynamic.cpp** - Two-dimensional dynamic arrays
4. **04-new-initialize.cpp** - Initializing values with `new`
5. **05-dynamic-array-average.cpp** - Average from a dynamic array
6. **06-resize-array.cpp** - Resizing by allocating and copying

## Exercises

### Basic
1. Allocate a single integer dynamically, set its value, print it, and delete it
2. Create a dynamic array of 5 doubles, fill it with user input, and compute the average

### Intermediate
3. Write a function that takes a size, allocates an array, fills it with random numbers, and returns the pointer
4. Create a 3x3 dynamic grid and fill it with a multiplication table

### Challenge
5. Write a function that "resizes" a dynamic array (allocate new, copy old, delete old)

## Mini-Project: Dynamic Image (P2 Format)

Build a program that loads, manipulates, and saves grayscale images in P2 (PGM) format.

**P2 Format:**
```
P2
# Optional comment
width height
maxval
pixel values...
```

**Requirements:**
1. Load a P2 image into a dynamically allocated 2D array
2. Implement at least two operations:
   - Invert (newval = maxval - oldval)
   - Flip horizontal
3. Save the result to a new file

**Sample P2 file (tiny.pgm):**
```
P2
4 3
255
100 150 200 250
50 75 100 125
200 175 150 125
```

The key skill here: creating a 2D array whose size isn't known until you read the file header.

A starter file is in `mini-project/image_processor.cpp`.

---

Dynamic memory is powerful, but with power comes responsibility. Keep track of what you allocate, and always clean up.

*Next week: more practice with memory, and what happens when things go wrong.*
