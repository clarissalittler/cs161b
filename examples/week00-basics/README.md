# Week 0: The Basics (A Refresher)

Welcome back to C++, dear reader.

If you've taken CS161A, most of this week will feel familiar—and that's the point. We're warming up, shaking off the rust, and making sure we're all starting from the same place before we venture into the thornier territory of pointers and memory.

## What We're Covering

- Program structure (the `main` function and friends)
- Input and output with `cin` and `cout`
- Loops (`for`, `while`, and why we need both)
- Arrays (your first taste of managing multiple values)

## The Shape of a C++ Program

Every C++ program has a `main` function. It's where execution begins. Here's the simplest possible program:

```cpp
int main() {
    return 0;
}
```

This program does nothing, but it does nothing *successfully*. The `return 0` tells the operating system "everything went fine."

Of course, a program that does nothing isn't very useful. Let's say hello.

## Output: Talking to the User

To print things, we use `cout` (pronounced "see-out"—it stands for "character output"). Think of it as a pipe that flows from your program to the screen.

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
```

The `<<` operator pushes things into the output stream. You can chain them:

```cpp
cout << "The answer is " << 42 << endl;
```

The `endl` sends a newline *and* flushes the buffer. (Don't worry about what "flushing the buffer" means yet. Just know that `endl` ends the line.)

## Input: Listening to the User

If `cout` is the mouth, `cin` is the ear. It reads input from the keyboard:

```cpp
int age;
cout << "How old are you? ";
cin >> age;
cout << "You are " << age << " years old." << endl;
```

Note that `>>` points the other direction—data flows *from* `cin` *into* your variable.

### A Word of Caution

`cin` is trusting. If you ask for an integer and the user types "banana", `cin` will fail silently and leave your variable in a weird state. We'll deal with input validation later. For now, just assume your users are cooperative.

## Loops: Doing Things Repeatedly

You remember these from 161A, but let's review.

### The `for` Loop

Use this when you know how many times you want to loop:

```cpp
for (int i = 0; i < 10; i++) {
    cout << i << endl;
}
```

This prints 0 through 9. Note that we start at 0 and go *up to but not including* 10. This is a pattern you'll see constantly in C++.

### The `while` Loop

Use this when you don't know how many iterations you need:

```cpp
int guess;
while (guess != secretNumber) {
    cout << "Guess: ";
    cin >> guess;
}
```

The loop continues until the condition becomes false.

### Quick Check

What's the difference between these two?

```cpp
// Version A
int i = 0;
while (i < 5) {
    cout << i << endl;
    i++;
}

// Version B
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

Answer: They do the same thing! The `for` loop just bundles the initialization, condition, and increment into one line.

## Arrays: Many Values, One Name

So far, we've used individual variables:

```cpp
int score1 = 85;
int score2 = 92;
int score3 = 78;
```

But what if you have 100 scores? You don't want 100 variable names. This is where arrays come in:

```cpp
int scores[100];
```

This creates a block of 100 integers, accessed by index:

```cpp
scores[0] = 85;   // First element
scores[1] = 92;   // Second element
scores[99] = 78;  // Last element (not 100!)
```

### The Off-by-One Zone

Arrays are *zero-indexed*. An array of size N has valid indices 0 through N-1. This will trip you up at least once. Probably more than once. It's a rite of passage.

### Looping Through Arrays

Arrays and `for` loops are best friends:

```cpp
int scores[5] = {85, 92, 78, 95, 88};

for (int i = 0; i < 5; i++) {
    cout << "Score " << i << ": " << scores[i] << endl;
}
```

Notice how the loop condition (`i < 5`) matches the array size. This is not a coincidence.

## The Examples

Work through these in order:

1. **01-hello.cpp** - The classic starting point
2. **02-input-output.cpp** - Getting data from the user
3. **03-loops.cpp** - Repeating actions
4. **04-arrays.cpp** - Working with collections

## Exercises

### Basic
1. Modify `01-hello.cpp` to print your name instead of "world"
2. Write a program that asks for two numbers and prints their sum

### Intermediate
3. Write a program that prints the numbers 1 to 20, but prints "fizz" for multiples of 3
4. Create an array of 5 names and print them in reverse order

### Challenge
5. Write a program that reads numbers until the user enters -1, then prints the average

## Mini-Project: Number Cruncher

Let's build a simple statistics calculator.

**Your program should:**
1. Ask the user how many numbers they want to enter (max 100)
2. Read that many numbers into an array
3. Calculate and display:
   - The sum
   - The average
   - The largest number
   - The smallest number

**Sample run:**
```
How many numbers? 5
Enter number 1: 10
Enter number 2: 25
Enter number 3: 8
Enter number 4: 42
Enter number 5: 15

Results:
Sum: 100
Average: 20
Largest: 42
Smallest: 8
```

A starter file is provided in `mini-project/number_cruncher.cpp`. Fill in the `TODO` sections.

---

Once you're comfortable with these basics, you're ready for Week 1, where we'll meet pointers—one of C++'s most powerful (and most confusing) features.

*Don't worry. We'll take it slow.*
