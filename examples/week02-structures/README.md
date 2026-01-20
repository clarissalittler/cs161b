# Week 2: Structures (Bundling Data Together)

Up until now, if you wanted to represent a "thing" with multiple pieces of data—say, a pet with a name, species, and age—you had to use separate arrays:

```cpp
string names[10];
string species[10];
int ages[10];
```

This is called "parallel arrays," and it's... fine? It works. But it's also error-prone and awkward. The name, species, and age of pet #3 are scattered across three different places. If you sort one array, the others don't come along for the ride.

This week, we bundle related data together with **structs**, and we also tackle **2D arrays** (arrays of arrays).

## 2D Arrays: Grids and Tables

Sometimes one dimension isn't enough. If you're representing a game board, a spreadsheet, or an image, you need rows *and* columns.

```cpp
int grid[3][4];  // 3 rows, 4 columns
```

You access elements with two indices:

```cpp
grid[0][0] = 1;  // Top-left
grid[2][3] = 2;  // Bottom-right (row 2, column 3)
```

Think of it as `grid[row][col]`. The first index picks the row, the second picks the column within that row.

### Memory Layout

In memory, a 2D array is stored row-by-row (this is called "row-major order"):

```
grid[0][0] grid[0][1] grid[0][2] grid[0][3] grid[1][0] grid[1][1] ...
```

This matters when you're looping through large arrays. Accessing elements in row order is faster than column order because of how CPU caching works. But don't worry about that for now—just know that the rows are laid out consecutively.

### Looping Through 2D Arrays

Nested loops are your friend:

```cpp
for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 4; col++) {
        cout << grid[row][col] << " ";
    }
    cout << endl;  // New line after each row
}
```

## Structs: Custom Data Types

A **struct** lets you group related pieces of data under one name:

```cpp
struct Pet {
    string name;
    string species;
    int age;
};
```

Now you can create variables of type `Pet`:

```cpp
Pet myPet;
myPet.name = "Whiskers";
myPet.species = "Cat";
myPet.age = 5;
```

The dot (`.`) is called the "member access operator." It lets you get at the fields inside the struct.

### Why Structs are Better Than Parallel Arrays

With parallel arrays:
```cpp
// Which pet is "Whiskers"? Hope you remember it's index 0!
names[0] = "Whiskers";
species[0] = "Cat";
ages[0] = 5;
```

With structs:
```cpp
// All of Whiskers's data is together
Pet whiskers = {"Whiskers", "Cat", 5};
```

When you have an array of structs, sorting becomes easy—move the whole struct at once, and all the fields come along.

### Passing Structs to Functions

You can pass structs to functions just like any other type:

```cpp
void printPet(Pet p) {
    cout << p.name << " is a " << p.age << "-year-old " << p.species << endl;
}
```

But remember: by default, structs are **passed by copy**. If your struct is large, or if you want to modify it, use a reference:

```cpp
void birthday(Pet& p) {
    p.age++;  // Modifies the original
}
```

### Structs and Pointers

You can also have pointers to structs:

```cpp
Pet* ptr = &myPet;
```

To access a member through a pointer, you could write `(*ptr).name`, but that's ugly. C++ gives us the **arrow operator** (`->`) as a shortcut:

```cpp
cout << ptr->name << endl;  // Same as (*ptr).name
```

The arrow combines dereferencing and member access into one tidy symbol.

## The Examples

1. **01-2d-arrays.cpp** - Creating and traversing grids
2. **02-structs.cpp** - Defining and using custom types
3. **03-arrays-of-structs.cpp** - The best of both worlds
4. **04-2d-array-row-sum.cpp** - Summing each row in a 2D array
5. **05-struct-initialization.cpp** - Two ways to initialize a struct
6. **06-array-of-structs-search.cpp** - Searching an array of structs
7. **07-char-grid-movement.cpp** - Moving on a 2D char grid with checks

## Exercises

### Basic
1. Create a 5x5 multiplication table using a 2D array
2. Define a `Book` struct with title, author, and pages; create and print one

### Intermediate
3. Write a function that finds the largest element in a 2D array
4. Create an array of 5 `Student` structs (name, id, gpa) and compute the average GPA

### Challenge
5. Implement a Tic-Tac-Toe board as a 2D char array, with functions to print the board and check for a winner

## Mini-Project: Contact Book

Build a simple contact manager.

**Your program should:**
1. Define a `Contact` struct with:
   - `name` (string)
   - `phone` (string)
   - `email` (string)

2. Store up to 100 contacts in an array

3. Provide a menu with options to:
   - Add a new contact
   - List all contacts
   - Search for a contact by name
   - Delete a contact
   - Quit

**Sample run:**
```
=== Contact Book ===
1. Add contact
2. List all contacts
3. Search by name
4. Delete contact
5. Quit

Choice: 1
Name: Alice Smith
Phone: 555-1234
Email: alice@example.com
Contact added!

Choice: 2
1. Alice Smith - 555-1234 - alice@example.com

Choice: 3
Search for: Alice
Found: Alice Smith - 555-1234 - alice@example.com

Choice: 5
Goodbye!
```

A starter file is in `mini-project/contact_book.cpp`.

---

Structs are a stepping stone to something bigger. In CS162 and beyond, you'll learn about *classes*, which are like structs but with built-in functions and access control. But that's a story for another course.

For now, enjoy the tidiness of keeping related data together.

*Onwards to functions!*
