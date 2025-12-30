# Week 5: Integration (Putting It All Together)

Congratulations! You've learned arrays, pointers, structs, functions, and file I/O. Separately, these are just tools in a toolbox. Together, they let you build *real programs*.

This week, there's no new syntax to learn. Instead, we focus on **combining** what you know into complete, useful programs. Think of it as a studio week—time to practice and synthesize.

## The Art of Program Design

When faced with a larger problem, how do you start? Here's a process:

### 1. Understand the Problem

Before writing any code, make sure you understand:
- What are the inputs?
- What are the outputs?
- What transformations happen in between?
- What edge cases exist?

### 2. Identify the Data

What data does the program need to track?
- Single values? Arrays? Structs?
- Does it need to persist between runs (files)?

Define your data structures first. The code often follows naturally.

### 3. Sketch the Functions

Break the problem into logical pieces:
- What are the major operations?
- What helper functions would make the code cleaner?
- How do pieces connect?

Don't write perfect code yet—just outline the structure.

### 4. Build Incrementally

Don't try to write the whole thing at once:
1. Start with the core data structures
2. Add basic operations (create, display)
3. Add more complex operations (search, modify)
4. Add file I/O last (or early, if it's central)
5. Test as you go!

### 5. Refactor and Polish

Once it works, make it better:
- Clearer names?
- Duplicated code to extract?
- Edge cases to handle?

## Common Program Patterns

### Pattern: Menu-Driven Program

A loop with a menu that dispatches to handlers:

```cpp
do {
    printMenu();
    cin >> choice;

    switch (choice) {
        case 1: addItem(); break;
        case 2: listItems(); break;
        case 3: searchItem(); break;
        case 4: cout << "Goodbye!"; break;
    }
} while (choice != 4);
```

### Pattern: Load-Work-Save

Programs that persist data:

```cpp
int main() {
    // Load from file
    Data items[MAX];
    int count = loadFromFile(items);

    // Work (menu loop or processing)
    processData(items, count);

    // Save back to file
    saveToFile(items, count);
}
```

### Pattern: Read-Transform-Write

Processing data files:

```cpp
int main() {
    while (readRecord(inFile, record)) {
        transformRecord(record);
        writeRecord(outFile, record);
    }
}
```

### Pattern: Validate-Process-Report

Interactive programs with validation:

```cpp
int main() {
    if (!validateInput()) {
        showError();
        return 1;
    }

    results = processData();
    displayReport(results);
}
```

## This Week's Examples

Rather than separate concept files, this week has two complete programs:

1. **inventory_manager.cpp** - A full inventory system combining structs, arrays, functions, and file I/O
2. **grade_book.cpp** - A student grade management system

Study how they're structured. Notice:
- How data is organized (structs + arrays)
- How functions divide the work
- How file I/O handles persistence
- How the user interface flows

## Exercises

### Practice Exercise 1
Modify `inventory_manager.cpp` to add a "low stock alert" feature that lists all items with quantity below a threshold.

### Practice Exercise 2
Add a "search by category" feature to the inventory manager.

### Practice Exercise 3
Add grade curves or weighted averages to `grade_book.cpp`.

## Mini-Project: Personal Finance Tracker

Build a program to track income and expenses.

**Requirements:**
1. Track transactions with:
   - Date (string for now)
   - Description
   - Amount (positive = income, negative = expense)
   - Category (Food, Transport, Entertainment, etc.)

2. Menu options:
   - Add transaction
   - List all transactions
   - Show summary by category
   - Show current balance
   - Save and quit

3. Persist to a file (`transactions.txt`)

**Sample run:**
```
=== Finance Tracker ===
Current balance: $250.00

1. Add transaction
2. List transactions
3. Category summary
4. Show balance
5. Save and quit

Choice: 1
Date: 2024-03-15
Description: Coffee
Amount: -4.50
Category: Food
Transaction added!

Choice: 3
=== Category Summary ===
Food: -$45.50
Transport: -$30.00
Entertainment: -$25.00
Income: +$400.00
------------------
Net: +$299.50

Choice: 5
Saved to transactions.txt
Goodbye!
```

A starter file is in `mini-project/finance_tracker.cpp`.

---

Integration is where programming starts to feel *powerful*. You're not just learning syntax anymore—you're building tools.

*Keep going. You're doing great.*
