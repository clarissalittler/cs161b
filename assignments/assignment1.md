# Assignment: Score Manager Program

## Overview

Here's a little warm-up! You have two weeks to finish it!

If you took cs161A with me, this might feel like review. If you didn't, then it's a great opportunity to get up to speed!

You will write a program that allows a user to manage a collection of integer scores stored in an array. This assignment will solidify your understanding of **functions**, **loops**, and **arrays** before moving on to more complex projects. You will practice breaking down a program into modular, reusable components and using a menu-driven interface for interaction.

## Learning Objectives

By completing this assignment, you will:

- Implement and call **functions** to perform specific tasks.
- Use **loops** to iterate over arrays and control program flow.
- Manipulate and process data stored in **arrays**.
- Design and implement a simple **menu-driven program**.

## Task Description

Your program will allow users to:

1. Enter a collection of scores into an array.
2. Perform various operations on the scores using a menu system.

The program will:

- Use **functions** to perform all operations on the array.
- Include a loop to repeatedly display a menu and process user input until the user chooses to quit.

## Program Requirements

### 1. Storing Scores

- Use a fixed-size integer array (e.g., `int scores[100]`).
- Prompt the user for how many scores they want to enter (up to 100).
- Use a **loop** to read and store that many scores into the array.

### 2. Functions for Array Operations

Implement and use the following functions:

- `void PrintScores(int arr[], int size)`
  - Prints all scores in a neat format.
- `int FindMax(int arr[], int size)`
  - Returns the highest score in the array.
- `int FindMin(int arr[], int size)`
  - Returns the lowest score in the array.
- `double CalculateAverage(int arr[], int size)`
  - Calculates and returns the average score as a `double`.
- `int CountAboveThreshold(int arr[], int size, int threshold)`
  - Counts and returns how many scores are above a user-specified threshold.

**Note:** The main function should **not** include logic for these tasks; it should only call these functions and display results.

### 3. Menu-Driven Interaction

After the scores are entered, display a menu that allows the user to choose one of the following options:
```
1. Print all scores
2. Find maximum score
3. Find minimum score
4. Calculate average
5. Count scores above a certain threshold
0. Quit
```

- Use a **loop** to repeatedly display the menu and read user input.
- Perform the selected operation by calling the relevant function.
- Display the result of each operation.
- Continue looping until the user chooses `0` to quit.

### 4. Optional Enhancements

- Add **input validation** to ensure the user inputs valid menu choices.
- Display a friendly error message if operations like `FindMax` or `FindMin` are attempted with no scores entered.

### 5. Clean Code and Style

- Break your program into clearly defined **functions**.
- Avoid code repetition by using loops.
- Keep the `main()` function focused on high-level program flow.

## What you need to turn in

Submit the following:

1. Your complete source code.
2. A reflection document answering the following questions:

## Reflection Questions (Only a couple of sentences are necessary):

1. **Initial Approach:**
   - *How did you begin working on this assignment—did you plan or sketch out a design first, or did you jump straight into coding? Briefly explain why you took that approach.*

2. **Challenges & Problem-Solving:**
   - *What was the most challenging aspect of the assignment, and how did you address it?*

3. **Testing & Debugging:**
   - *How did you test your code, and can you describe one example of a bug you discovered and how you fixed it?*

4. **Design & Structure Improvements:**
   - *If you had more time, what would you change in your code's structure or style to improve clarity or maintainability?*

5. **Conceptual Understanding:**
   - *Did this project change or deepen your understanding of how to use arrays or functions? Describe one insight you gained.*

## Grading Policy

This assignment will be graded out of 4:

- **4**: The assignment is bug-free, meets all requirements, and includes completed reflection questions.
- **3**: The assignment meets requirements but may include minor bugs or does not include completed reflection questions.
- **2**: The assignment is incomplete or contains significant errors.
- **1**: The submission shows minimal effort or is largely non-functional.
- **0**: No submission.

If the reflection questions are not turned in, the **highest grade you can receive is a 3**.

## Hints and Tips

- Start by implementing the basic input and output for the array.
- Gradually add functions one by one, testing each as you go.
- Use `for` loops for operations on arrays, and `while` loops for the menu.
- Use descriptive names for your functions and variables.

This assignment prepares you for the upcoming "Mini Text Dungeon" project, where you will apply similar concepts in a game-based context. Have fun coding!
