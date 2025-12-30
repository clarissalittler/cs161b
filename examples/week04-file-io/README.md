# Week 4: File I/O (Programs That Remember)

So far, all our programs have been *ephemeral*. You run them, interact with them, and when they end... everything's gone. The data evaporates like morning dew.

This week, we give our programs memory. Real memory. The kind that survives turning off the computer.

## The Basic Idea

Files are just sequences of bytes stored on disk. We can:
- **Read** from files (get data into our program)
- **Write** to files (save data from our program)

C++ provides two main types for this:
- `ifstream` - Input file stream (for reading)
- `ofstream` - Output file stream (for writing)

Both are in the `<fstream>` header.

## Reading from Files

```cpp
#include <fstream>
using namespace std;

ifstream inFile;
inFile.open("data.txt");

if (!inFile) {
    cout << "Error: couldn't open file" << endl;
    return 1;
}

string word;
while (inFile >> word) {
    cout << word << endl;
}

inFile.close();
```

Notice anything familiar? We use `>>` just like with `cin`. That's because `ifstream` and `cin` are both *input streams*—they work the same way, just from different sources.

### Reading Line by Line

If you want whole lines (not just whitespace-separated words):

```cpp
string line;
while (getline(inFile, line)) {
    cout << line << endl;
}
```

### Checking for Success

Always check if the file opened:

```cpp
if (!inFile) {
    // Handle error
}
```

And remember that reading can fail too. The `>>` and `getline` operations return something that's "falsy" when there's nothing left to read, which is why they work as loop conditions.

## Writing to Files

```cpp
ofstream outFile;
outFile.open("output.txt");

if (!outFile) {
    cout << "Error: couldn't create file" << endl;
    return 1;
}

outFile << "Hello, file!" << endl;
outFile << "The answer is " << 42 << endl;

outFile.close();
```

Again, `<<` works just like with `cout`. The difference is where the output goes.

### Appending vs. Overwriting

By default, `ofstream` *overwrites* the file. If you want to add to an existing file:

```cpp
outFile.open("log.txt", ios::app);  // append mode
```

## Common Patterns

### Pattern 1: Read Until Empty

```cpp
int number;
while (inFile >> number) {
    sum += number;
    count++;
}
```

### Pattern 2: Read Structured Data

If your file has a known format (like name, age, score on each line):

```cpp
string name;
int age;
double score;

while (inFile >> name >> age >> score) {
    // Process this record
}
```

### Pattern 3: Read, Process, Write

A common task: read a file, transform it, write the result:

```cpp
ifstream in("input.txt");
ofstream out("output.txt");

string line;
while (getline(in, line)) {
    // Transform line somehow
    out << transformedLine << endl;
}
```

## Error Handling

File operations can fail. Common issues:
- File doesn't exist (for reading)
- No permission to write
- Disk is full
- Path is wrong

Always check if operations succeeded:

```cpp
inFile.open("data.txt");
if (!inFile.is_open()) {
    cerr << "Failed to open data.txt" << endl;
    return 1;
}
```

## A Word About Paths

When you open a file with just a filename (`"data.txt"`), the program looks in the *current working directory*—usually where you ran the program from.

For more control, use full paths:
```cpp
inFile.open("/home/student/data/input.txt");
```

Or relative paths:
```cpp
inFile.open("../data/input.txt");  // Up one directory, then into data/
```

## The Examples

1. **01-reading-files.cpp** - Basic file reading patterns
2. **02-writing-files.cpp** - Creating and writing to files
3. **03-parsing.cpp** - Reading structured data

Sample data files are in the `data/` subfolder.

## Exercises

### Basic
1. Write a program that reads a file and counts the lines
2. Write a program that creates a file with the numbers 1-100

### Intermediate
3. Read a file of numbers and write their sum to an output file
4. Create a program that copies one file to another

### Challenge
5. Build a simple "search in file" utility: read a file and print only lines containing a search term

## Mini-Project: To-Do List Manager

Build a persistent to-do list that survives between runs.

**Requirements:**
1. Save tasks to a file (`todos.txt`)
2. Load tasks when the program starts
3. Menu options:
   - View all tasks
   - Add a task
   - Mark a task as complete
   - Delete a task
   - Quit (saves automatically)

**File format:**
```
[ ] Buy groceries
[x] Finish homework
[ ] Call mom
```

**Sample run:**
```
Loaded 3 tasks from todos.txt

=== To-Do List ===
1. [ ] Buy groceries
2. [x] Finish homework
3. [ ] Call mom

1. View tasks
2. Add task
3. Complete task
4. Delete task
5. Quit

Choice: 3
Complete which task? 1

1. [x] Buy groceries
2. [x] Finish homework
3. [ ] Call mom

Choice: 5
Saved 3 tasks to todos.txt
Goodbye!
```

A starter file is in `mini-project/todo_list.cpp`.

---

Once your programs can read and write files, whole new possibilities open up. Configuration files, data processing, log files, save games...

*The world is your filesystem.*
