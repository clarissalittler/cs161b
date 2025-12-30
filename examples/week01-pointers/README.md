# Week 1: Pointers (Don't Panic)

Ah, pointers. The topic that makes students break out in a cold sweat.

Here's the thing: pointers are not *complicated*. They're just *unfamiliar*. Once you get the mental model right, they're actually quite logical. So let's build that mental model together.

## The Big Picture

Remember that your computer's memory is like a giant wall of numbered cubbyholes. Each cubbyhole has an address (its number) and can hold a value.

When you declare a variable like `int x = 42;`, you're saying "find me a cubbyhole, put 42 in it, and let me call that cubbyhole 'x'."

A **pointer** is a variable that holds an *address*—the number of a cubbyhole, rather than the actual data in it. It's like having a sticky note that says "look in cubbyhole 1000" instead of "42".

Why would you want that? Patience, dear reader. We'll get there.

## The Syntax

Two new operators to learn:

- `&` (address-of): "What cubbyhole is this variable in?"
- `*` (dereference): "What's in the cubbyhole at this address?"

```cpp
int x = 42;
int* p = &x;    // p holds the address of x

cout << x;      // Prints 42 (the value)
cout << &x;     // Prints something like 0x7fff5fbff8ac (the address)
cout << p;      // Same address as above
cout << *p;     // Prints 42 (follow the pointer, get the value)
```

The `*` in the declaration (`int* p`) means "p is a pointer to an int." The `*` when using the pointer (`*p`) means "follow this pointer and give me what's there."

Yes, the same symbol means two different things depending on context. C++ is like that sometimes.

## Why Bother?

Good question. Here are three reasons pointers matter:

### 1. Passing by Reference (Efficiently)

When you pass an array to a function, you're not copying the whole array—you're passing a pointer to its first element. This is fast, even for huge arrays.

### 2. Dynamic Memory

Later, we'll ask the operating system for memory at runtime. It will give us an address (a pointer). Without pointers, we couldn't use that memory.

### 3. Data Structures

Linked lists, trees, graphs—all the cool data structures use pointers to connect nodes together.

## The Array Connection

Here's something that might blow your mind: in C++, arrays and pointers are deeply connected.

When you use an array name by itself (without brackets), it *decays* into a pointer to the first element:

```cpp
int arr[5] = {10, 20, 30, 40, 50};
int* p = arr;    // p points to arr[0]

cout << *p;      // 10
cout << *(p+1);  // 20
cout << *(p+2);  // 30
```

That `*(p+1)` business is called **pointer arithmetic**. When you add 1 to a pointer, it doesn't move by one byte—it moves by the size of whatever the pointer points to. So `p+1` points to the next integer, not the next byte.

This is why `arr[i]` and `*(arr+i)` mean exactly the same thing. The bracket notation is just friendlier syntax for pointer arithmetic.

## C-Style Strings

Remember how strings in C are just arrays of characters ending with a null character (`'\0'`)? That's why they're called "null-terminated strings."

```cpp
char greeting[] = "Hello";  // Actually stores: H e l l o \0
```

Functions like `strlen` work by starting at the address you give them and counting characters until they hit that `'\0'`. If the null terminator is missing, the function will wander off into random memory looking for one. Hilarity (or crashes) ensue.

## References: The Friendly Alternative

C++ has a gentler way to work with addresses: **references**.

```cpp
int x = 42;
int& ref = x;   // ref is another name for x

ref = 100;      // This changes x!
cout << x;      // Prints 100
```

A reference is like a pointer that automatically dereferences itself. You don't need `*` to use it, and it can never be null. Think of it as an alias—another name for the same cubbyhole.

References are especially useful in function parameters:

```cpp
void triple(int& n) {
    n = n * 3;  // Modifies the original!
}

int x = 5;
triple(x);
cout << x;  // Prints 15
```

Without the `&`, the function would get a *copy* of x, and the original would be unchanged.

## The Examples

1. **01-pointer-basics.cpp** - Address-of, dereference, pointer declaration
2. **02-references.cpp** - The friendlier alternative
3. **03-pointer-arithmetic.cpp** - Arrays and pointers, the connection
4. **04-cstrings.cpp** - C-style strings and their quirks

## Exercises

### Basic
1. Declare an integer, a pointer to it, and print both the value and address
2. Write a function that swaps two integers using reference parameters

### Intermediate
3. Write a function that takes a pointer to an array and its size, and returns the sum
4. Create a C-string and write a loop that prints each character using pointer arithmetic

### Challenge
5. Implement your own `strlen` function that takes a `const char*` and returns the length

## Mini-Project: String Toolkit

Build a set of C-string utilities without using the standard library functions.

**Your program should implement:**
1. `int myStrlen(const char* s)` - Return the length of the string
2. `void myStrcpy(char* dest, const char* src)` - Copy src into dest
3. `int myStrcmp(const char* a, const char* b)` - Return 0 if equal, negative if a < b, positive if a > b
4. `void myReverse(char* s)` - Reverse the string in place

**Sample run:**
```
Enter a string: hello

Length: 5
Reversed: olleh
Enter another string to compare: world
"hello" comes before "world" alphabetically
Copied string: hello
```

A starter file is in `mini-project/string_toolkit.cpp`.

---

Pointers feel weird at first. That's normal. The fog will lift.

Next week, we bundle related data together with structs. It's a nice break before we combine structs *with* pointers later on.

*One step at a time.*
