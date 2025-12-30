# Instructor's Guide

This guide outlines what to cover each week, which examples to point to, and short in-class activities to do together. It mirrors the structure of the repo and assignments.

Use `examples-from-videos/INDEX.md` as the full catalog.

## Week 0: Basics and program flow

Topics to include:
- Program structure (`#include`, `main`, `return 0`)
- Console I/O (`cout`, `cin`)
- Variables and types (`int`)
- Conditionals and loops (`if/else`, `for`, `while`, `do-while`)
- Arrays (fixed-size), indexing, and bounds
- Input validation with `cin.fail()`

Point to examples:
- `examples-from-videos/week0/hellocommented.cpp`
- `examples-from-videos/week0/cin1commented.cpp`
- `examples-from-videos/week0/cinWhilecommented.cpp`
- `examples-from-videos/week0/arrays1commented.cpp`
- `examples-from-videos/week0/guessingcommented.cpp`

In-class ideas:
- Live-code "Hello + name" and explain compile/run loop.
- Build a `readInt` function together and test it with bad input.
- Write a tiny loop that sums 5 inputs into an array and prints them back.
- Play the guessing game as a class: ask students what happens on each guess.

## Week 1: Pointers, references, and C-strings

Topics to include:
- Address-of and dereference (`&`, `*`)
- Pointer arithmetic and array equivalence
- References (`int&`) and pass-by-reference
- C-style strings and null terminators
- Manual string operations (`strlen`, `strcpy` style)

Point to examples:
- `examples-from-videos/week1/pointy1commented.cpp`
- `examples-from-videos/week1/pointy2commented.cpp`
- `examples-from-videos/week1/chararray2commented.cpp`
- `examples-from-videos/week1/hangedmancommented.cpp`

In-class ideas:
- Draw memory boxes for an array and show how `arr[i]` maps to `*(arr+i)`.
- Implement a `doubler(int&)` function live.
- Write `ourStrlen` together and test it on short inputs.
- Walk through the hangman loop, tracing the `partial` array changes.

## Week 2: 2D arrays and structs

Topics to include:
- 2D arrays and nested loops
- Row/column indexing and common mistakes
- Structs and arrays of structs
- Moving from parallel arrays to structs

Point to examples:
- `examples-from-videos/week2/multiarray1commented.cpp`
- `examples-from-videos/week2/pets1commented.cpp`
- `examples-from-videos/week2/pets2commented.cpp`

In-class ideas:
- Build a 5x5 grid and fill it with `i*10+j`, then print one row and one column.
- Start with parallel arrays for pets, then refactor to a `struct` in front of students.
- Ask students to locate an off-by-one bug in a 2D loop.

## Week 3: Functions + arrays consolidation

Topics to include:
- Breaking programs into functions (inputs/outputs)
- Array passing conventions (size + array)
- Defensive input and boundary checks
- Small test harnesses and incremental testing

Point to examples:
- `examples-from-videos/week0/arrays1commented.cpp`
- `examples-from-videos/week0/cinWhilecommented.cpp`
- `examples-from-videos/week2/pets2commented.cpp`

In-class ideas:
- Take `arrays1commented.cpp` and extract `readArray` and `printArray`.
- Write a `findMax` and `findMin` as a pair, then compare logic side-by-side.
- Build a tiny menu that calls two functions and exits cleanly.

## Week 4: Files + strings

Topics to include:
- `ifstream`/`ofstream` basics
- Line-based input with `getline`
- Simple file formats (CSV-like)
- Menu loops and function decomposition
- `cin >>` vs `getline` behavior
- Simple text processing workflows (count, filter, transform)
- Light refactoring: reuse functions across file programs

Point to examples:
- `examples-from-videos/week4/files1commented.cpp`
- `examples-from-videos/week4/reverseLinescommented.cpp`
- `examples-from-videos/week4/structFilescommented.cpp`
- `examples-from-videos/week4/pets.txt`
- `examples-from-videos/week1/chararray2commented.cpp`

In-class ideas:
- Read a file line-by-line and count lines.
- Reverse one line on the board, then show the program do it for all lines.
- Build a tiny menu (add/list/quit) for a struct array.
- Read a file, count words per line, and print counts.
- Show how `getline` consumes the trailing newline after `cin >>`.
- Take the reverse-lines program and add a filter (only reverse lines longer than N).

## Week 5: Integration studio

Topics to include:
- Reviewing arrays + structs + file I/O together
- Function boundaries and incremental testing
- Debugging strategies for input-heavy programs
- Previewing Assignment 3 data formats (P1/P3) without dynamic allocation yet

Point to examples:
- `examples-from-videos/week4/structFilescommented.cpp`
- `examples-from-videos/week4/reverseLinescommented.cpp`
- `examples-from-videos/week2/pets2commented.cpp`
- `examples-from-videos/week6/test.ppm`

In-class ideas:
- Add one new menu option to the pets database (e.g., filter by age).
- Read a small file and summarize its stats (lines, chars, longest line).
- Walk through the P1 header format and identify width/height on the board.

## Week 6: Dynamic memory and images

Topics to include:
- `new`/`delete` and dynamic 2D arrays
- Structs that hold dynamically allocated data
- Simple image formats (P1/P3)
- Memory leaks and cleanup

Point to examples:
- `examples-from-videos/week6/p1commented.cpp`
- `examples-from-videos/week6/test.ppm`

In-class ideas:
- Draw the dynamic 2D allocation as "array of row pointers." 
- Live-code allocation and deletion for a small grid.
- Parse the P1 header on the board, then show reading pixel data.

## Week 7: Dynamic memory practice

Topics to include:
- Ownership and cleanup (when to `delete[]`)
- Building and resizing dynamic arrays
- Passing dynamically allocated arrays into functions
- Common bugs: leaks, double-free, uninitialized pointers

Point to examples:
- `examples-from-videos/week6/p1commented.cpp`
- `examples-from-videos/week2/multiarray1commented.cpp`

In-class ideas:
- Start with a fixed array, then refactor to a dynamic one.
- Have students identify where `delete[]` must go in an example.
- Write a simple “growable list” that doubles capacity.

## Week 8: Linked lists, stacks, and queues + ADT practice

Topics to include:
- Linked list node structure
- Queue operations and their list/array versions
- Converting a queue to a stack (LIFO vs FIFO)
- Memory cleanup for lists
- Abstract data types (stack/queue interface)
- Error handling for empty/full operations
- Time complexity discussion at an intuitive level
- Debugging pointer-heavy code

Point to examples:
- `examples-from-videos/week8/arrayQueue.cpp`
- `examples-from-videos/week8/listQueue.cpp`
- `examples-from-videos/week8/agenda.org`

In-class ideas:
- Build a 3-node linked list on the board and trace `enqueue`.
- Ask students to identify what changes when turning a queue into a stack.
- Have students predict pointer updates for `dequeue`.
- Compare array vs list stack implementations on the board.
- Trace a buggy pop and ask students to fix it.
- Write a `peek` function and discuss preconditions.

## Week 9: Project studio and review (Assignment 4 focus)

Topics to include:
- Catch-up and consolidation for Assignment 4
- Debugging strategies for pointer-heavy code
- Building small test harnesses for stack operations
- Comparing array vs list stack behavior (edge cases)

Point to examples:
- `examples-from-videos/week8/arrayQueue.cpp`
- `examples-from-videos/week8/listQueue.cpp`
- `examples-from-videos/week8/agenda.org`

In-class ideas:
- Compare array vs list stack implementations on the board.
- Run a “code clinic” on common Assignment 4 mistakes (empty pop, memory leaks).
- Have students write a tiny tester for `push`/`pop`/`peek`.
- Do a live bug hunt in a linked-list stack implementation.

## Week 10: Templates and STL preview

Topics to include:
- Template functions and type parameters
- When templates fail (type mismatch)
- Intro to `std::vector` and nested vectors
- Iterators vs range-based loops

Point to examples:
- `examples-from-videos/week10/templates.cpp`
- `examples-from-videos/week10/templates2.cpp`
- `examples-from-videos/week10/stl1.cpp`
- `examples-from-videos/week10/p1vector.cpp`

In-class ideas:
- Write `swappy` once, then use it with `int` and `float`.
- Convert a fixed array sum to a template sum.
- Build a 2D `vector` and print it with range-based loops.

## Assignment alignment and due weeks

- Assignment 1 (due end of Week 2): arrays + functions + menus (Weeks 0-2)
- Assignment 2 (due end of Week 4): C-strings + 2D arrays + game loop (Weeks 1-4)
- Assignment 3 (due end of Week 7): structs + dynamic memory + file I/O (Weeks 4-7)
- Assignment 4 (due end of Week 9): stacks via arrays/lists (Week 9)
- Assignment 5 (due end of Week 11/finals): refactor a prior project (all weeks)
