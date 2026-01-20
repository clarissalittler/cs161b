# Week 3: Functions (Advanced Patterns)

Here's a secret that experienced programmers know: the hardest part of programming isn't writing code. It's *organizing* code.

A program that works but is a tangled mess of 500 lines in `main()` is worse than one that's broken into clear, understandable pieces. Why? Because programs need to be *read* and *changed* after they're written. Usually by you, three months from now, when you've forgotten how it works.

This week still leans on **decomposition**, but it also adds some advanced function tools: recursion, overloading, default arguments, const references, and (briefly) function pointers.

## Why Functions?

Consider this code:

```cpp
// Calculate average of array
double sum = 0;
for (int i = 0; i < size; i++) {
    sum += arr[i];
}
double avg = sum / size;

// Later... calculate another average
double sum2 = 0;
for (int i = 0; i < size2; i++) {
    sum2 += arr2[i];
}
double avg2 = sum2 / size2;
```

See the duplication? Now imagine you have to calculate averages in ten different places. If you find a bug (say, dividing by zero when the array is empty), you have to fix it ten times.

With a function:

```cpp
double average(double arr[], int size) {
    if (size == 0) return 0;  // Fix once, works everywhere
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Now anywhere in your code:
double avg = average(scores, numScores);
double avg2 = average(prices, numPrices);
```

Functions let you:
- **Avoid repetition** (DRY: Don't Repeat Yourself)
- **Name your intentions** (`average` is clearer than a loop)
- **Test pieces independently**
- **Change implementations without breaking callers**

## The Anatomy of a Function

```cpp
return_type function_name(parameter_list) {
    // body
    return value;  // if not void
}
```

- **Return type**: What the function gives back (or `void` for nothing)
- **Name**: A verb or verb phrase describing what it does
- **Parameters**: The inputs the function needs
- **Body**: The code that does the work

## Function Design Principles

### 1. One Job Per Function

Each function should do *one thing*. If you find yourself putting "and" in the description ("calculates the sum *and* prints it *and* updates the counter"), that's probably multiple functions.

```cpp
// Bad: does too much
void processAndPrintResults(int data[], int size, int& total, bool& hasError) {
    // 50 lines of code doing multiple things
}

// Good: single responsibilities
int calculateTotal(int data[], int size);
void printResults(int total);
bool validateData(int data[], int size);
```

### 2. Meaningful Names

Functions should be named for what they *do*, not *how* they do it.

```cpp
// Meh: tells you the implementation
int loopAndAdd(int arr[], int size);

// Better: tells you the purpose
int sumArray(int arr[], int size);
```

### 3. Reasonable Size

If a function doesn't fit on one screen (about 30-40 lines), consider breaking it up. This isn't a hard rule, but long functions are often doing too much.

### 4. Minimize Side Effects

A function that only computes a value is easier to understand than one that also modifies global state, prints things, or changes its arguments unexpectedly.

When a function *does* modify something (like a pass-by-reference parameter), make it obvious from the name:

```cpp
void sortArray(int arr[], int size);  // Clearly modifies arr
int findMax(const int arr[], int size);  // const signals: won't modify
```

## Pass by Value vs. Pass by Reference

Remember from Week 1:

- **Pass by value**: Function gets a *copy*. Changes don't affect the original.
- **Pass by reference**: Function gets the *original*. Changes persist.

```cpp
void incrementCopy(int x) {
    x++;  // Changes the copy, original unchanged
}

void incrementOriginal(int& x) {
    x++;  // Changes the actual variable
}
```

Use references when:
1. You need to modify the original
2. The data is large and copying would be wasteful
3. You're "returning" multiple values (through reference parameters)

Use `const` references when you want efficiency without modification:

```cpp
void printStudent(const Student& s) {
    // s is not copied, but also can't be changed
    cout << s.name << endl;
}
```

## Refactoring: Making Code Better

**Refactoring** means improving code structure without changing its behavior. Some common refactorings:

### Extract Function

Take a chunk of code and turn it into a function:

```cpp
// Before
int main() {
    // ... 20 lines to validate input ...
    // ... 30 lines to process data ...
    // ... 15 lines to print results ...
}

// After
bool validateInput(...);
void processData(...);
void printResults(...);

int main() {
    if (!validateInput(...)) return 1;
    processData(...);
    printResults(...);
}
```

### Rename for Clarity

Give things better names:

```cpp
// Before
int x = calc(a, b, c);

// After
int discountedTotal = calculatePriceWithDiscount(basePrice, quantity, discountRate);
```

### Remove Duplication

Spot repeated patterns and extract them:

```cpp
// Before
cout << "Name: " << p1.name << endl;
cout << "Age: " << p1.age << endl;
cout << "Name: " << p2.name << endl;
cout << "Age: " << p2.age << endl;

// After
void printPerson(const Person& p) {
    cout << "Name: " << p.name << endl;
    cout << "Age: " << p.age << endl;
}
printPerson(p1);
printPerson(p2);
```

## Advanced Function Tools

- Function overloading
- Default arguments
- Const references
- Recursion
- Function pointers (a bit advanced)

## The Examples

1. **01-decomposition.cpp** - Breaking a complex task into functions
2. **02-refactoring.cpp** - Before/after examples of code improvement
3. **03-recursion-basics.cpp** - Basic recursion with base cases
4. **04-function-overloading.cpp** - Same name, different parameters
5. **05-default-arguments.cpp** - Defaults in function parameters
6. **06-const-references.cpp** - Read-only references to avoid copies
7. **07-function-pointers.cpp** - Function pointers (advanced topic)

## Exercises

### Basic
1. Write overloaded `max` functions for `int` and `double`
2. Write a `greet` function that uses a default argument for punctuation

### Intermediate
3. Write a recursive `sumToN(int n)` or `factorial(int n)`
4. Write a function `int countVowels(const string& s)` using a const reference

### Challenge
5. Build a mini-calculator using a function pointer to choose the operation

## Mini-Project: Grade Calculator

Build a grade calculation program with well-designed functions.

**Requirements:**
1. Read student scores from the user (name and grade)
2. Calculate letter grades based on score ranges
3. Compute class statistics (average, highest, lowest)
4. Display a formatted grade report

**Function decomposition:**
Your program should have (at minimum) these functions:
- `char getLetterGrade(double score)` - Convert numeric to letter
- `double calculateAverage(double scores[], int count)`
- `double findHighest(double scores[], int count)`
- `double findLowest(double scores[], int count)`
- `void printReport(...)` - Display the results

**Advanced features (optional but encouraged):**
- Use `const string&` for name parameters
- Add a default parameter for a curve (e.g., +5 points)

**Sample run:**
```
Enter number of students: 3
Student 1 name: Alice
Student 1 score: 92
Student 2 name: Bob
Student 2 score: 78
Student 3 name: Carol
Student 3 score: 85

=== Grade Report ===
Alice: 92 (A)
Bob: 78 (C)
Carol: 85 (B)

Class Statistics:
Average: 85.0
Highest: 92
Lowest: 78
```

A starter file is in `mini-project/grade_calculator.cpp`.

---

Good function design is a skill that grows with practice. Don't expect to get it perfect the first time. Write the code, see what feels awkward, and refactor.

*Your future self will thank you.*
