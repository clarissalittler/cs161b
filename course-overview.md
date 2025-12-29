# CS161B Course Overview (with examples)

This is a long-form, conversational walk through the course, paired to the examples in this repo. The vibe is: read a section, open the linked example, then poke it until it makes sense.

If you want a quick skim: the course moves from basic I/O and loops, to arrays and functions, then pointers and C-style strings, then files and structs, and ends with dynamic memory, data structures, and a taste of templates/STL.

## How to use this

- Each section links to one or more example files under `examples-from-videos/`.
- Code snippets below are pulled straight from those examples (sometimes just the relevant slice).
- Use the assignments as checkpoints; they're in `assignments/`.
- If a section feels fast, open the linked file and trace it line by line; most of the learning happens there.

---

## Week 0: First programs, I/O, loops, and arrays

### Hello, world (because tradition)

Example: `examples-from-videos/week0/hellocommented.cpp`

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
```

This is the smallest possible C++ program that does something observable. You learn the basic shape of a program: include a library, define `main`, print output, return a status code.
Think of this as your template: almost everything you write this term will look like this with more stuff inside.

### `cin` input and variables

Example: `examples-from-videos/week0/cin1commented.cpp`

```cpp
int main() {
    int num1;
    cout << "Say somethin' will ya: ";
    cin >> num1;
    cout << "You said: " << num1 << endl;
    return 0;
}
```

The big idea: input is just data moving into variables. Once it is stored, it is yours to do math with, compare, or re-print.
Also: `cin` is picky about types. If you ask for an `int` and the user gives you a word, you have to handle the mess.

### Loops and input validation

Example: `examples-from-videos/week0/cinWhilecommented.cpp`

```cpp
int readInt(string prompt){
  int tempInt;
  cout << prompt;
  cin >> tempInt;

  while(cin.fail()){
    cin.clear(); 
    cin.ignore(256,'\n');
    cout << prompt;
    cin >> tempInt;
  }
  return tempInt;
}
```

This is your first strong hint that real input is messy. You do not trust it. You ask for it, check it, and ask again if it's invalid.
In practice, this "loop until input is valid" pattern shows up all semester.

### The guessing game

Example: `examples-from-videos/week0/guessingcommented.cpp`

A simple `do { ... } while(...)` loop plus comparisons gives you game logic. This is an early taste of what programming really is: state + rules.
You also see how random numbers, loops, and branching glue together into something that feels like a program instead of a demo.

### Arrays, for-loops, and repetition

Example: `examples-from-videos/week0/arrays1commented.cpp`

```cpp
int num[5];
for(int i = 0; i < 5; i++){
  cout << "Enter the " << i << "th number: ";
  cin >> num[i];
}

for(int i = 0; i < 5; i++){
  cout << "The " << i << "th number is: " << num[i] << endl;
}
```

Arrays are the first big leap: you stop writing "num1, num2, num3" and start saying "num[i]". If this feels mind-bending at first, good. You are leveling up.
Remember: arrays start at index 0, and the last valid index is `size - 1`.

---

## Week 1: Pointers, references, and C-style strings

### Arrays as pointers (a.k.a. pointer arithmetic)

Example: `examples-from-videos/week1/pointy1commented.cpp`

```cpp
int arr[10];
for(int i = 0; i < 10; i++){
  arr[i] = i*i+100;
}

for(int i = 0; i < 10; i++){
  cout << "arr[i] is: " << arr[i] << endl;
  cout << "*(arr+i) is: " << *(arr+i) << endl;
}
```

This is the same data accessed two ways. `arr[i]` is a friendly wrapper. `*(arr+i)` is the bare metal version. Knowing they are the same is huge for understanding C++.
Arrays are stored contiguously in memory, so pointer math is literally "move over one box."

### References as "aliases"

Example: `examples-from-videos/week1/pointy2commented.cpp`

```cpp
void doubler(int& num){
  num = 2 * num;
}

int main(){
  int thing = 10;
  doubler(thing);
  cout << "Now thing is: " << thing << endl;
}
```

If a pointer is an explicit address, a reference is the quiet version: another name for the same variable.
References are the common way to let a function modify something without returning it.

### C-style strings (char arrays)

Example: `examples-from-videos/week1/chararray2commented.cpp`

```cpp
void ourStrcpy(char dest[],char src[]){
  int i = 0;
  while(src[i] != '\0'){
    dest[i] = src[i];
    i++;
  }
  dest[i] = src[i];
}
```

C-style strings are just arrays of characters ending in `\0`. The null terminator is the entire trick.
This also means you have to manage the size yourself; there is no automatic bounds checking.

### A mini game with char arrays

Example: `examples-from-videos/week1/hangedmancommented.cpp`

This shows a full looped game: partial word state, guesses, comparison, and win/lose logic. If you can read this file start-to-finish, you're ready for Assignment 2.
Notice how most of the "game feel" is just repeated input + small updates to state.

---

## Week 2: 2D arrays and struct-based data

### 2D arrays and nested loops

Example: `examples-from-videos/week2/multiarray1commented.cpp`

```cpp
int arr[50][50];
for(int i = 0; i < 50; i++){
  for(int j = 0; j < 50; j++){
    arr[i][j] = i*1000 + j; 
  }
}
```

Two-dimensional arrays are just arrays of arrays. You loop rows, then columns. (And yes, it feels like a lot at first.)
Think of a grid: row index first, column index second, and make a habit of labeling them when you debug.

### A pet database with parallel arrays

Example: `examples-from-videos/week2/pets1commented.cpp`

You store names, species, and ages in three parallel arrays. This works, but you can already feel the structure begging for a `struct`.
Parallel arrays are fine for small programs, but they are easy to get out of sync.

### A pet database with structs

Example: `examples-from-videos/week2/pets2commented.cpp`

```cpp
struct Pet {
  string name;
  string species;
  int age;
};

Pet readPet(){
  Pet p;
  cout << "Name: ";
  cin >> p.name;
  cout << "Species: ";
  cin >> p.species;
  cout << "Age: ";
  cin >> p.age; 
  return p;
}
```

Structs let you bundle related data. Your code becomes smaller, cleaner, and easier to modify.
You can pass a `Pet` around as one unit instead of juggling three separate arrays.

---

## Week 4: Files, strings, and menu-driven programs

### Reading a file line by line

Example: `examples-from-videos/week4/files1commented.cpp`

```cpp
ifstream ourFile("heck.txt");
char line[256];

while(ourFile.getline(line, 256)) {
  cout << line << endl;
}
```

The file stream (`ifstream`) behaves a lot like `cin`, but for files instead of the keyboard.
If you can read from `cin`, you can read from a file; the syntax is almost identical.

### Processing file lines as data

Example: `examples-from-videos/week4/reverseLinescommented.cpp`

You read all lines into a 2D char array, reverse each one, and write them back out. This is a nice mix of file I/O + string handling.
This is also where you really feel the difference between line-based input and word-based input.

### A menu-driven pets database

Example: `examples-from-videos/week4/structFilescommented.cpp`

This is the first "real program" feel: structs, a menu loop, file input, and file output. It is a direct warm-up for Assignment 1.
Menus are just loops with a `switch` or `if` chain, but they're a great way to practice organizing code into functions.

---

## Week 6: Dynamic memory and image formats

### P1 image parsing + dynamic 2D arrays

Example: `examples-from-videos/week6/p1commented.cpp`

```cpp
struct P1 {
  int width;
  int height;
  int** pixels;
};

image.pixels = new int*[image.height];
for(int i=0; i < image.height; i++){
  image.pixels[i] = new int[image.width];
}
```

This is your first real taste of dynamic memory: arrays created at runtime. It is also the mental model you use for Assignment 3 (P3 image transformer).
Dynamic memory means you must also clean up after yourself; `new` without `delete` leaks.

The file `examples-from-videos/week6/test.ppm` is a tiny P1 image if you want to inspect the format.
P1 is black-and-white; P3 (your assignment) is color, but the file shape is the same idea.

---

## Week 8: Data structures (queues as a stepping stone to stacks)

### Array-backed queue

Example: `examples-from-videos/week8/arrayQueue.cpp`

```cpp
struct queue {
  int data[maxSize];
  int current = 0;
};

void enqueue(int v,queue &q){
  if(q.current < maxSize){
    for(int i = q.current-1; i >= 0; i--){
      q.data[i+1] = q.data[i];
    }
    q.data[0] = v;
    q.current++;
  }
}
```

The array version shows how to track size, insert, and remove. You can turn this into a stack by pushing and popping from the same end.
The tradeoff here is speed: shifting elements is simple to understand, but it costs time.

### Linked-list queue

Example: `examples-from-videos/week8/listQueue.cpp`

```cpp
struct queue{
  int head;
  queue* tail;
};

void enqueue(int v,queue*& q){
  queue* newFront = new queue;
  newFront->head = v;
  newFront->tail = q;
  q = newFront;
}
```

Linked lists are a different mental model: each node points to the next. This is the cleanest route to a stack implementation.
The upside is easy inserts at the front; the downside is more pointer management.

---

## Week 10: Templates and a peek at the STL

### Generic functions with templates

Example: `examples-from-videos/week10/templates.cpp`

```cpp
template <typename T>
void swappy(T& a, T& b){
  T temp = a;
  a = b;
  b = temp;  
}
```

Templates let you write one function that works for many types. The big idea is not the syntax, it's the mindset: "the shape of the code stays the same, only the type changes."
If the compiler can't make the code make sense for a type, you get a compile error instead of a runtime surprise.

### A generic sum

Example: `examples-from-videos/week10/templates2.cpp`

```cpp
template <typename T>
T sum(T arr[], int l){
  T acc = 0;
  for(int i =0; i < l; i++){
    acc += arr[i];
  }
  return acc;
}
```

### STL vectors and iterators

Example: `examples-from-videos/week10/stl1.cpp`

```cpp
vector<vector<int>> twoD = {{1,2,3},{4,5,6}};

for(auto i = twoD.begin(); i != twoD.end(); i++){
  for(auto j = i->begin(); j != i->end(); j++){
    cout << *j << " ";
  }
  cout << endl;
}
```

You do not have to fall in love with the STL, but this is the first hint that C++ has modern conveniences if you want them.
It is fine to treat this as a preview and stick to arrays for now.

---

## Assignments (what each one is really practicing)

- Assignment 1 (`assignments/assignment1.md`): functions + arrays + menu loops.
- Assignment 2 (`assignments/assignment2.md`): C-style strings, 2D arrays, basic game logic.
- Assignment 3 (`assignments/assignment3.md`): structs + dynamic memory + file I/O (P3 images).
- Assignment 4 (`assignments/assignment4.md`): stacks via arrays and linked lists.
- Assignment 5 (`assignments/assignment5.md`): refactoring, polishing, making old code better.
Reflection questions are part of the grade; the goal is to practice describing your design decisions in plain language.

---

## A final note on learning

Every example here is small on purpose. The real learning happens when you:

- change a variable name and watch it break,
- add a new feature and realize you have to refactor,
- debug a bug caused by input that was weird.

So: tweak the examples, re-run them, and break things on purpose. That is the course.
If you're unsure where to start, pick any example and try to add one small feature to it.

---
