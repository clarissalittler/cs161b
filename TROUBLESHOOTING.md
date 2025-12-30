# Troubleshooting Guide

This guide covers common errors you'll encounter while learning C++. Don't panic when you see these—every programmer sees them constantly!

## How to Use This Guide

1. **Copy the error message** you're seeing
2. **Search this document** (Ctrl+F) for key words from the error
3. **Read the explanation** and try the suggested fixes
4. **If still stuck**, add debug prints or ask for help

---

## Compilation Errors

These happen when you run `g++` and the compiler can't understand your code.

### Error: `error: expected ';' before '}'`

**What you'll see:**
```
program.cpp:15:5: error: expected ';' before '}'
```

**What it means:** You forgot a semicolon somewhere.

**Common causes:**
```cpp
int x = 5    // Missing semicolon!
cout << x << endl;
```

**How to fix:**
- Look at the line number mentioned (line 15 here)
- Also check the line **before** it—that's usually where the semicolon is missing
- Every statement in C++ needs a semicolon

---

### Error: `error: 'cout' was not declared in this scope`

**What you'll see:**
```
program.cpp:10:5: error: 'cout' was not declared in this scope
```

**What it means:** The compiler doesn't know what `cout` is.

**Common causes:**
1. Missing `#include <iostream>`
2. Missing `using namespace std;`

**How to fix:**
Make sure you have these at the top of your file:
```cpp
#include <iostream>
using namespace std;
```

If you don't want to use `using namespace std;`, write `std::cout` instead of just `cout`.

---

### Error: `error: expected ',' or ';' before 'int'`

**What you'll see:**
```
program.cpp:8:1: error: expected ',' or ';' before 'int'
```

**What it means:** Similar to missing semicolon, but the compiler is confused about what comes next.

**How to fix:**
Check the line **before** the error for a missing semicolon or brace.

---

### Error: `undefined reference to 'functionName'`

**What you'll see:**
```
/tmp/ccXXXXXX.o: In function `main':
program.cpp:(.text+0x5): undefined reference to 'FindMax(int*, int)'
```

**What it means:** You called a function but never wrote its body (implementation).

**Common causes:**
```cpp
int FindMax(int arr[], int size);  // Declaration only!

int main() {
    int nums[] = {1, 2, 3};
    FindMax(nums, 3);  // Error: where's the body?
}
// Missing: actual implementation of FindMax
```

**How to fix:**
Write the function body:
```cpp
int FindMax(int arr[], int size) {
    // Your implementation here
}
```

---

### Error: `error: invalid conversion from 'int' to 'char*'`

**What you'll see:**
```
program.cpp:12:15: error: invalid conversion from 'int' to 'char*'
```

**What it means:** You're trying to use the wrong type.

**Common causes:**
```cpp
char name[50];
cin >> name;
int length = strlen(name);  // strlen returns size_t, not int - usually fine

// But this is wrong:
char* ptr = 5;  // Can't assign int to char pointer!
```

**How to fix:**
- Make sure variable types match what the function expects
- Check function signatures carefully

---

### Error: `error: no match for 'operator>>' `

**What you'll see:**
```
error: no match for 'operator>>' (operand types are 'std::istream' and 'const int')
```

**What it means:** You're trying to read into something that can't be modified.

**Common causes:**
```cpp
const int MAX_SIZE = 100;
cin >> MAX_SIZE;  // Can't modify a const!

void readArray(const int arr[], int size) {
    cin >> arr[0];  // Can't modify const array!
}
```

**How to fix:**
Remove `const` if you need to modify the variable.

---

## Runtime Errors

These happen when the program compiles but crashes while running.

### Error: `Segmentation fault (core dumped)`

**What it means:** Your program tried to access memory it shouldn't.

This is the **most common** error for beginners. It's scary but fixable!

**Common causes:**

#### 1. Array out of bounds
```cpp
int arr[5];
arr[10] = 100;  // Boom! Array only has indices 0-4
```

**Fix:** Check your loop conditions and array indices.

#### 2. Uninitialized pointer
```cpp
int* ptr;
*ptr = 5;  // Boom! ptr doesn't point anywhere valid
```

**Fix:** Initialize pointers before using them:
```cpp
int x = 0;
int* ptr = &x;  // Now it points to x
*ptr = 5;  // OK!
```

#### 3. Null pointer dereference
```cpp
int* ptr = nullptr;
cout << *ptr;  // Boom! Can't dereference null
```

**Fix:** Always check before dereferencing:
```cpp
if (ptr != nullptr) {
    cout << *ptr;
}
```

#### 4. Accessing deleted memory
```cpp
int* arr = new int[10];
delete[] arr;
arr[0] = 5;  // Boom! Memory was freed
```

**Fix:** Don't use memory after deleting it.

#### 5. C-string not null-terminated
```cpp
char name[5] = {'H', 'e', 'l', 'l', 'o'};  // No \0!
cout << name;  // Might crash or print garbage
```

**Fix:** Always null-terminate C-strings:
```cpp
char name[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
// Or just: char name[] = "Hello";
```

**Debugging segfaults:**
1. Add print statements before the crash to narrow down the line
2. Check all array accesses near that line
3. Check all pointer dereferences
4. Use `gdb` (see Week 9 debugging materials)

---

### Error: Program hangs / infinite loop

**What it means:** Your loop never ends.

**Common causes:**

#### 1. Wrong loop condition
```cpp
int i = 0;
while (i < 10) {
    cout << i << endl;
    // Forgot to increment i!
}
```

**Fix:** Make sure the loop variable changes:
```cpp
while (i < 10) {
    cout << i << endl;
    i++;  // Now it will eventually reach 10
}
```

#### 2. Off-by-one in condition
```cpp
int i = 0;
while (i != 10) {  // What if you increment by 2?
    i += 2;  // i goes 0, 2, 4, 6, 8, 10... wait, never equals 10!
}
```

**Fix:** Use `<` instead of `!=` for numeric loops.

---

### Error: `Aborted (core dumped)` or assertion failure

**What it means:** The program detected something wrong and stopped itself.

**Common causes:**
```cpp
#include <cassert>
assert(x > 0);  // If x is not > 0, program aborts
```

**How to fix:**
The assertion is telling you what's wrong. Check why the condition failed.

---

## Logic Errors

The program runs but gives wrong results.

### Problem: Wrong output from array operations

**Symptoms:**
- FindMax returns 0 when all numbers are negative
- CalculateAverage is wrong
- Array seems to have garbage values

**Common causes:**

#### 1. Not initializing variables
```cpp
int max;  // Garbage value!
for (int i = 0; i < size; i++) {
    if (arr[i] > max) {  // Comparing to garbage
        max = arr[i];
    }
}
```

**Fix:**
```cpp
int max = arr[0];  // Start with first element
for (int i = 1; i < size; i++) {  // Start from index 1
    if (arr[i] > max) {
        max = arr[i];
    }
}
```

#### 2. Integer division
```cpp
int sum = 85 + 90 + 78;
int avg = sum / 3;  // avg is 84, not 84.333...
```

**Fix:** Use `double` for one operand:
```cpp
double avg = sum / 3.0;  // Now it's 84.333...
// Or cast: double avg = (double)sum / 3;
```

---

### Problem: C-string functions don't work

**Symptoms:**
- `strlen` returns huge number
- String comparison always fails
- String copy crashes

**Common cause:** Forgot null terminator

```cpp
char word[10];
word[0] = 'h';
word[1] = 'i';
// Forgot to add '\0'!

cout << strlen(word);  // Huge random number!
```

**Fix:**
```cpp
word[0] = 'h';
word[1] = 'i';
word[2] = '\0';  // Add null terminator
```

Or use `cin.getline` which adds it automatically:
```cpp
cin.getline(word, 10);  // Automatically null-terminated
```

---

### Problem: File won't open

**Symptoms:**
- `ifstream` fails to open
- Nothing reads from file

**Common causes:**

#### 1. Wrong file path
```cpp
ifstream file("data.txt");  // Looking in current directory
```

**Fix:** Check where the file actually is:
```bash
ls  # See what files are in current directory
pwd # See what directory you're in
```

Use relative path if needed:
```cpp
ifstream file("../data/data.txt");
```

#### 2. File doesn't exist
**Fix:** Create it first, or check the filename spelling.

#### 3. Typo in filename
```cpp
ifstream file("data.txt");  // File is actually "Data.txt" (capital D)
```

**Fix:** Filenames are case-sensitive on Linux!

**Always check if file opened:**
```cpp
ifstream file("data.txt");
if (!file) {
    cout << "Error: could not open file!" << endl;
    return 1;
}
```

---

### Problem: Menu keeps looping even after choosing quit

**Common cause:** Wrong loop condition or not updating the choice

```cpp
int choice = -1;
while (choice != 0) {
    // ... display menu ...
    // Forgot to read choice again!
}
```

**Fix:** Make sure you read the new choice inside the loop:
```cpp
while (choice != 0) {
    cout << "Choice: ";
    cin >> choice;  // Read new choice each time
    // Handle choice...
}
```

---

### Problem: 2D array all zeros or garbage

**Common cause:** Not initializing before using

```cpp
int grid[10][10];  // Garbage values!
cout << grid[0][0];  // Random number
```

**Fix:** Initialize with a loop:
```cpp
int grid[10][10];
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        grid[i][j] = 0;  // Now it's zeros
    }
}
```

Or initialize on declaration:
```cpp
int grid[10][10] = {0};  // All zeros
```

---

## Input/Output Issues

### Problem: `cin` skips input or reads wrong

**Symptoms:**
- Program doesn't wait for input
- Reads empty string or newline

**Common cause:** Leftover newline in input buffer

```cpp
int age;
char name[50];

cin >> age;          // User types: 25<ENTER>
cin.getline(name, 50);  // Reads the leftover <ENTER>!
```

**Fix:** Clear the buffer:
```cpp
cin >> age;
cin.ignore(256, '\n');  // Ignore leftover newline
cin.getline(name, 50);  // Now works correctly
```

---

### Problem: Can't read names with spaces

**Wrong:**
```cpp
char name[50];
cin >> name;  // Only reads until first space
// User types "John Doe" → only gets "John"
```

**Fix:**
```cpp
char name[50];
cin.getline(name, 50);  // Reads whole line including spaces
```

---

## Memory Issues

### Problem: Memory leak

**What it means:** You allocated memory but never freed it.

**Won't crash immediately**, but the program uses more and more memory.

**Common cause:**
```cpp
for (int i = 0; i < 1000; i++) {
    int* arr = new int[100];
    // Use arr...
    // Never delete it!
}
// Lost 1000 arrays worth of memory!
```

**Fix:** Always `delete` what you `new`:
```cpp
int* arr = new int[100];
// Use arr...
delete[] arr;  // Free it!
```

For 2D arrays:
```cpp
int** grid = new int*[rows];
for (int i = 0; i < rows; i++) {
    grid[i] = new int[cols];
}

// Later, free in reverse order:
for (int i = 0; i < rows; i++) {
    delete[] grid[i];
}
delete[] grid;
```

---

### Problem: Double free or corruption

**What you'll see:**
```
*** Error in `./program': double free or corruption
```

**What it means:** You tried to delete the same memory twice.

**Common cause:**
```cpp
int* ptr = new int[10];
delete[] ptr;
delete[] ptr;  // Boom! Already deleted
```

**Fix:**
- Only delete each allocation once
- Set pointer to `nullptr` after deleting:
```cpp
delete[] ptr;
ptr = nullptr;  // Now safe to delete again (does nothing)
```

---

## Environment Issues

### Problem: `bash: ./program: Permission denied`

**What it means:** The file isn't executable.

**Fix:**
```bash
chmod +x program
./program
```

Or just recompile—that makes it executable:
```bash
g++ -Wall -o program program.cpp
./program
```

---

### Problem: `g++: command not found`

**What it means:** The C++ compiler isn't installed.

**Fix:**
See [UBUNTU_VIRTUALBOX_SETUP.md](UBUNTU_VIRTUALBOX_SETUP.md) or install with:
```bash
sudo apt-get update
sudo apt-get install g++
```

---

### Problem: `No such file or directory`

**What you'll see:**
```
program.cpp:1:10: fatal error: iostream: No such file or directory
```

**What it means:** Can't find the header file (probably a compiler installation issue).

**Fix:**
```bash
sudo apt-get install build-essential
```

---

## General Debugging Strategy

When you're stuck:

1. **Read the error message carefully** - It usually tells you what's wrong
2. **Look at the line number** - But also check lines around it
3. **Add print statements** - See what values variables actually have
4. **Simplify** - Comment out code until it works, then add back piece by piece
5. **Take a break** - Fresh eyes spot bugs faster
6. **Explain it to someone** (or a rubber duck) - Often you'll spot the bug while explaining

## Getting More Help

If you've tried the above and you're still stuck:

1. Write down:
   - What you're trying to do
   - What you expected to happen
   - What actually happened
   - The exact error message (copy-paste it)
   - The code that's causing the problem

2. Check the examples in the `examples/` folder for similar code

3. Review the relevant week's README

4. Ask for help with your written-down information from step 1

---

**Remember:** Every error is a learning opportunity. The more bugs you fix, the faster you'll recognize them next time.

*Errors are not failures—they're feedback.*
