# Learning C++: A Friendly Journey

Welcome, dear reader, to what I hope will be a pleasant stroll through C++.

If you're here, you probably already survived CS161A (or its equivalent) and have a general sense of what programming *is*. You've written loops, made decisions with `if` statements, and maybe even created a function or two. Wonderful! We're going to build on all of that.

## What This Folder Contains

This is a **week-by-week progression** through the core concepts of C++. Each week has:

1. **A README** explaining the concepts in (hopefully) human terms
2. **Numbered examples** you can compile and run
3. **A mini-project** to tie everything together

The idea is that you can work through these at your own pace, or alongside the course lectures. Either way, *type the code yourself*. I know, I know, copy-paste is right there. But your fingers need to learn this language too, and they won't if you don't let them practice.

## The Journey Ahead

| Week | Topic | The Big Idea |
|------|-------|--------------|
| 0 | Basics | Remembering how to say hello |
| 1 | Pointers | Memory has addresses, and we can use them |
| 2 | Structures | Bundling related data together |
| 3 | Functions | Breaking problems into smaller pieces |
| 4 | File I/O | Programs that remember things |
| 5 | Integration | Putting it all together (first time) |
| 6 | Dynamic Memory | Asking for memory at runtime |
| 7 | Memory Practice | Not leaking all that memory we asked for |
| 8 | Data Structures | Linked lists, stacks, and queues |
| 9 | Debugging | Finding and fixing the inevitable bugs |
| 10 | Templates & STL | Writing code that works with any type |

## How to Use This

Each week's folder has its own README. Start there. Read the explanations, then look at the examples, then try the exercises. When you feel ready, tackle the mini-project.

If something doesn't make sense, that's okay. Programming is learned through confusion—the fog lifts gradually, not all at once. Re-read, re-type, and give your brain time to absorb.

## Compiling the Examples

Every example can be compiled with:

```bash
g++ -Wall -o programname programname.cpp
```

The `-Wall` flag asks the compiler to warn you about suspicious things. These warnings are your friends. Read them.

If you're in a week's folder and want to build everything, there's a Makefile. Just type:

```bash
make
```

To clean up all the compiled programs:

```bash
make clean
```

## A Note on Style

You'll notice I use `using namespace std;` in these examples. In professional code, this is often frowned upon—it pulls *everything* from the standard library into your namespace, which can cause name collisions in larger projects.

But we're learning here, and `std::cout` everywhere makes the code harder to read when you're just trying to understand loops and pointers. So we'll use the training wheels for now. Just know that they're training wheels.

## Quick Check: Is Your Environment Ready?

Before diving in, make sure you can:

1. Open a terminal
2. Navigate to this folder (`cd examples`)
3. Compile a simple program
4. Run it

If any of those steps are mysterious, check out the `LINUX_C_CPP_TUTORIAL.md` in the main course folder.

---

Ready? Let's start with Week 0.

*Onwards!*
