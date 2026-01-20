# Week 10: Templates and STL (Generic Programming)

You've written a function to find the maximum of two integers:

```cpp
int max(int a, int b) {
    return (a > b) ? a : b;
}
```

Now someone wants the same thing for doubles. And for strings. And for custom types. Do you copy-paste the function ten times?

This week, we learn about **templates**—a way to write code that works with *any* type.

## Function Templates

A template is a blueprint for a function:

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

The `T` is a placeholder for a type. When you call `max(3, 5)`, the compiler creates a version for `int`. When you call `max(3.14, 2.71)`, it creates one for `double`.

```cpp
int x = max(3, 5);           // T = int
double y = max(3.14, 2.71);  // T = double
string z = max("hello", "world");  // T = string (compares lexicographically)
```

The compiler figures out the type from the arguments. You can also specify explicitly:

```cpp
auto result = max<double>(3, 3.14);  // Force T = double
```

## Template Syntax

```cpp
template <typename T>    // or: template <class T> (same thing)
T functionName(T param) {
    // Use T as a type
    T localVar;
    // ...
}
```

You can have multiple type parameters:

```cpp
template <typename T, typename U>
void printPair(T first, U second) {
    cout << first << ", " << second << endl;
}
```

## The Standard Template Library (STL)

C++ comes with a rich library of template-based containers and algorithms. The three pillars:

1. **Containers** - Data structures (vector, list, map, set, ...)
2. **Iterators** - A way to traverse containers
3. **Algorithms** - Sort, find, transform, ...

### std::vector

The most commonly used container. It's a dynamic array that grows as needed:

```cpp
#include <vector>

vector<int> numbers;        // Empty vector of ints
numbers.push_back(10);      // Add elements
numbers.push_back(20);
numbers.push_back(30);

cout << numbers[0];         // Access by index
cout << numbers.size();     // How many elements?

for (int n : numbers) {     // Range-based for loop
    cout << n << " ";
}
```

Unlike C arrays:
- Knows its own size (`.size()`)
- Grows automatically (`.push_back()`)
- Handles memory for you
- Passes by value correctly

### Iterators

Iterators are generalized pointers that work with any container:

```cpp
vector<int> v = {1, 2, 3, 4, 5};

// Iterator-based loop
for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}

// Or with auto (C++11)
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}
```

### Algorithms

The `<algorithm>` header provides many useful functions:

```cpp
#include <algorithm>

vector<int> v = {3, 1, 4, 1, 5, 9};

sort(v.begin(), v.end());           // Sort ascending
reverse(v.begin(), v.end());        // Reverse
auto it = find(v.begin(), v.end(), 4);  // Find element
int count = count(v.begin(), v.end(), 1);  // Count occurrences
```

## Why Templates Matter

1. **Code reuse** - Write once, use with any type
2. **Type safety** - Errors caught at compile time
3. **Performance** - No runtime overhead (code generated at compile time)
4. **Foundation of STL** - Most of the standard library is templates

## The Examples

1. **01-function-templates.cpp** - Writing generic functions
2. **02-class-templates.cpp** - Template structs (preview of classes)
3. **03-stl-intro.cpp** - Using vector, iterators, and algorithms
4. **04-template-max.cpp** - A minimal function template
5. **05-template-swap.cpp** - Swapping values with a template
6. **06-stl-vector-basics.cpp** - Basic `std::vector` usage

## Exercises

### Basic
1. Write a template function `swap(T& a, T& b)` that swaps any two values
2. Use a vector to store and print 10 user-entered numbers

### Intermediate
3. Write a template function `printArray(T arr[], int size)` for any type
4. Use `std::sort` to sort a vector of strings alphabetically

### Challenge
5. Create a template struct `Pair<T, U>` that holds two values of different types

## Mini-Project: Generic Statistics Library

Build a set of template functions that work with any numeric type.

**Required functions:**
1. `T minimum(vector<T>& v)` - Find smallest element
2. `T maximum(vector<T>& v)` - Find largest element
3. `double average(vector<T>& v)` - Calculate mean
4. `T sum(vector<T>& v)` - Sum all elements
5. `void printStats(vector<T>& v)` - Print all statistics

**Sample usage:**
```cpp
vector<int> integers = {1, 5, 3, 9, 2};
printStats(integers);
// Output:
// Min: 1
// Max: 9
// Sum: 20
// Average: 4

vector<double> doubles = {1.5, 2.5, 3.5};
printStats(doubles);
// Output:
// Min: 1.5
// Max: 3.5
// Sum: 7.5
// Average: 2.5
```

A starter file is in `mini-project/stats_library.cpp`.

---

Templates are a deep topic—there's much more to explore in CS162 and beyond (template specialization, variadic templates, concepts in C++20).

For now, know that they exist, understand the basic syntax, and use `std::vector` instead of raw arrays when you can.

*Congratulations on finishing CS161B! You've come a long way.*
