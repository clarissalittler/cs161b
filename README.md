# CS161B - C++ Programming

Welcome to CS161B! This repository contains all the learning materials, examples, and assignments for the course.

## Quick Start

### First Time Setup

1. **Check your environment**
   ```bash
   g++ --version   # Should show g++ compiler version
   ```
   If this doesn't work, see [UBUNTU_VIRTUALBOX_SETUP.md](UBUNTU_VIRTUALBOX_SETUP.md) or [LINUX_C_CPP_TUTORIAL.md](LINUX_C_CPP_TUTORIAL.md)

2. **Clone this repository** (if you haven't already)
   ```bash
   git clone <repository-url>
   cd cs161b
   ```

3. **Try your first program**
   ```bash
   cd examples/week00-basics
   g++ -Wall -o hello 01-hello.cpp
   ./hello
   ```

   You should see "Hello, World!" printed to your console. If so, you're ready to go!

### Compiling C++ Programs

The basic compilation command:
```bash
g++ -Wall -o program_name source_file.cpp
```

- `g++` - The C++ compiler
- `-Wall` - Show all warnings (helpful for catching bugs!)
- `-o program_name` - Name the output executable
- `source_file.cpp` - Your source code file

**Example:**
```bash
g++ -Wall -o my_game mini_dungeon.cpp
./my_game
```

### Using the Makefiles

Many example folders include a `Makefile` for convenience:
```bash
cd examples/week01-pointers
make              # Compile all programs
./01-pointer-basics   # Run a program
make clean        # Remove compiled programs
```

## Repository Structure

```
cs161b/
├── assignments/          # 5 programming assignments
├── examples/            # Weekly structured examples (44 programs)
│   ├── week00-basics/
│   ├── week01-pointers/
│   └── ...
├── examples-from-videos/ # Examples from lecture videos
├── course-overview.md    # Conversational course walkthrough
├── practice-exercises.md # Hour-scale practice problems
├── TESTING_GUIDE.md     # How to test your code
└── INSTRUCTORS_GUIDE.md # For instructors
```

## How to Learn from This Repository

1. **Read the weekly README** - Each `examples/weekXX-topic/README.md` explains concepts in friendly terms
2. **Type out the examples** - Don't copy-paste! Your fingers need to learn too
3. **Do the practice exercises** - See `practice-exercises.md` for hour-scale problems
4. **Complete the assignments** - Found in `assignments/`
5. **Test your code** - See [TESTING_GUIDE.md](TESTING_GUIDE.md) for strategies

## Assignments

| # | Name | Topics | Due |
|---|------|--------|-----|
| 1 | Score Manager | Functions, arrays, menus | Week 2 |
| 2 | Mini Text Dungeon | C-strings, 2D arrays, game logic | Week 4 |
| 3 | Image Transformer | Structs, dynamic memory, file I/O | Week 7 |
| 4 | Stack Implementation | Data structures, arrays & linked lists | Week 9 |
| 5 | Refactoring | Improve prior work | Finals week |

All assignments include reflection questions worth 1 point out of 4.

## Getting Help

### When You're Stuck

1. **Read the error message carefully** - It usually tells you what's wrong
2. **Check the examples** - There's probably a similar example in the weekly folder
3. **Use print statements** - `cout << "DEBUG: x = " << x << endl;`
4. **Start small** - Get one function working before moving to the next
5. **See [TROUBLESHOOTING.md](TROUBLESHOOTING.md)** - Common errors and solutions

### Resources

- **Course Overview**: [course-overview.md](course-overview.md) - Long-form guide to all concepts
- **Practice Problems**: [practice-exercises.md](practice-exercises.md) - Hour-scale exercises
- **Testing Guide**: [TESTING_GUIDE.md](TESTING_GUIDE.md) - How to verify your code works
- **Troubleshooting**: [TROUBLESHOOTING.md](TROUBLESHOOTING.md) - Common errors and how to fix them
- **Setup Help**: [UBUNTU_VIRTUALBOX_SETUP.md](UBUNTU_VIRTUALBOX_SETUP.md)

## Course Philosophy

This course emphasizes:
- **Learning by doing** - Every concept has runnable examples
- **Progressive complexity** - Each week builds on the last
- **Reflection** - Understanding *why* your code works matters as much as *that* it works
- **Practical skills** - You'll build real programs (games, image processors, data structures)

## Weekly Topics

| Week | Topic | The Big Idea |
|------|-------|--------------|
| 0 | Basics | Hello World, I/O, loops, arrays |
| 1 | Pointers | Memory has addresses we can use |
| 2 | Structures | Bundle related data together |
| 3 | Functions | Break problems into pieces |
| 4 | File I/O | Programs that remember things |
| 5 | Integration | Putting it all together |
| 6 | Dynamic Memory | Asking for memory at runtime |
| 7 | Memory Practice | Not leaking memory |
| 8 | Data Structures | Stacks, queues, linked lists |
| 9 | Debugging | Finding and fixing bugs |
| 10 | Templates & STL | Code that works with any type |

## A Note on Style

These examples use `using namespace std;` for readability while learning. In larger projects, you'd typically avoid this, but for now, we're keeping things simple so you can focus on the concepts.

---

**Ready to start?** Head to [examples/week00-basics/README.md](examples/week00-basics/README.md) or jump straight into [course-overview.md](course-overview.md).

*Type the code. Break things. Learn from the errors. That's how you become a programmer.*
