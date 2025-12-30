# Testing Guide

Testing is how you verify your code actually works. This guide shows you practical strategies for testing your assignments.

## The Golden Rule of Testing

**Don't just test the happy path.** Your program should handle:
- ✅ Normal inputs (what you expect)
- ⚠️ Edge cases (boundary values, empty inputs)
- ❌ Invalid inputs (wrong types, out of range)

## General Testing Strategy

### 1. Test as You Build

Don't wait until your entire program is done to test. Test each function as you write it.

**Example workflow for Assignment 1:**
```cpp
// Write FindMax function
int FindMax(int arr[], int size) {
    // ... your code ...
}

// Test it IMMEDIATELY with a small test
int main() {
    int test[] = {5, 2, 9, 1, 7};
    cout << "Max of test array: " << FindMax(test, 5) << endl;
    // Expected: 9

    int test2[] = {-5, -2, -9};
    cout << "Max of negative numbers: " << FindMax(test2, 3) << endl;
    // Expected: -2

    return 0;
}
```

Once you're confident `FindMax` works, move on to the next function.

### 2. Create a Test Plan

Before submitting, write down test cases you'll try. Here's an example for **Assignment 1 (Score Manager)**:

#### Test Cases for Assignment 1

| Test | Input | Expected Output | Why This Test? |
|------|-------|----------------|----------------|
| Normal scores | 85, 90, 78, 92, 88 | Max: 92, Min: 78, Avg: 86.6 | Happy path |
| All same score | 75, 75, 75, 75 | Max: 75, Min: 75, Avg: 75 | Edge case |
| Single score | 100 | Max: 100, Min: 100, Avg: 100 | Boundary (size=1) |
| Threshold test | Scores: 55, 78, 90, 45, 82<br>Threshold: 70 | Count above 70: 3 | Verifies counting |
| Zero scores | Size: 0 | Should handle gracefully | Edge case |

### 3. Test Edge Cases

Edge cases are inputs at the boundaries of what your program expects.

**Common edge cases:**
- Empty data (size = 0)
- Single element (size = 1)
- Maximum size (e.g., array of 100 elements)
- Negative numbers
- Zero values
- All elements the same

### 4. Use Print Statements for Debugging

When something doesn't work, add debug prints:

```cpp
void PrintScores(int arr[], int size) {
    cout << "DEBUG: size = " << size << endl;  // Add this

    for(int i = 0; i < size; i++) {
        cout << "DEBUG: arr[" << i << "] = " << arr[i] << endl;  // Add this
        cout << arr[i] << " ";
    }
    cout << endl;
}
```

Remove debug prints before submitting, or wrap them in a flag:
```cpp
#define DEBUG 1

#if DEBUG
    cout << "DEBUG: size = " << size << endl;
#endif
```

## Assignment-Specific Testing

### Assignment 1: Score Manager

**Test each menu option:**
```
Test run:
1. Enter 5 scores: 85, 90, 78, 92, 88
2. Menu choice 1 (Print all) → Should show all 5 scores
3. Menu choice 2 (Max) → Should show 92
4. Menu choice 3 (Min) → Should show 78
5. Menu choice 4 (Average) → Should show ~86.6
6. Menu choice 5 (Threshold: 80) → Should show 3 scores above 80
7. Menu choice 0 (Quit) → Program exits
```

**Edge case tests:**
- Enter 1 score, verify all functions work
- Enter 100 scores (maximum size)
- Try invalid menu choices (test input validation)

### Assignment 2: Mini Text Dungeon

**Test movement systematically:**
```
Test map (5x5):
#####
#S..#
#.###
#..T#
#####

Test sequence:
1. Start position: Should be at S (row 1, col 1)
2. Move right (d) → Player moves to (1, 2)
3. Move down (s) → Player moves to (2, 2)? Wait, that's a wall!
   → Should reject movement and stay at (1, 2)
4. Test each wall boundary
5. Navigate to treasure at T
6. Verify win condition triggers
```

**Edge cases:**
- Try moving outside boundaries
- Try moving into every wall
- Enter invalid commands (not w/a/s/d)
- Test with player name of different lengths

**Create a test checklist:**
- [ ] Player name is stored and displayed
- [ ] Map displays correctly
- [ ] Starting position is marked
- [ ] Each direction (w/a/s/d) works correctly
- [ ] Cannot move through walls
- [ ] Cannot move outside boundaries
- [ ] Reaching treasure triggers win message
- [ ] Win message includes player name

### Assignment 3: Image Transformer

**Start with tiny test images:**

Create a minimal 2x2 test image (`test_tiny.ppm`):
```
P3
2 2
255
255 0 0    0 255 0
0 0 255    255 255 255
```
This is: red, green, blue, white

**Test your program:**
```bash
# Test reading
./image_transform test_tiny.ppm output.ppm

# Verify the output file exists and is valid P3 format
cat output.ppm

# Visual check: Compare with original
# - If you flipped horizontally: green should be on left, red on right
# - If you converted to grayscale: all pixels should have R=G=B
```

**Test incrementally:**
1. First, just read and write (no transformation) - verify output matches input
2. Then add ONE transformation and test
3. Then add the next transformation
4. Finally test with the full pikachu.ppm image

**Edge cases:**
- 1x1 pixel image
- Very wide image (100x1)
- Very tall image (1x100)
- Large image (pikachu.ppm)

### Assignment 4: Stack Implementation

**Test both implementations (array and linked list) with same tests:**

```cpp
// Test sequence for array-based stack
Stack s;
initStack(s);

// Test 1: isEmpty on new stack
assert(isEmpty(s) == true);  // Should be empty

// Test 2: Push elements
push(s, 10);
push(s, 20);
push(s, 30);

// Test 3: Peek (should be 30)
assert(peek(s) == 30);

// Test 4: isEmpty after pushes
assert(isEmpty(s) == false);

// Test 5: Pop elements
assert(pop(s) == 30);  // Last in, first out
assert(pop(s) == 20);
assert(pop(s) == 10);

// Test 6: isEmpty after all pops
assert(isEmpty(s) == true);

// Test 7: Pop on empty stack (should handle gracefully)
pop(s);  // Should print error, not crash

// Test 8: Push until full (array version only)
for(int i = 0; i < 10; i++) {
    push(s, i);
}
push(s, 99);  // Should print "stack full" error
```

**Test both implementations identically** to ensure they behave the same way.

## Creating Good Test Cases

### Think About What Could Go Wrong

For each function, ask:
- What if the input is empty?
- What if there's only one item?
- What if all items are the same?
- What if the input is at the maximum size?
- What if the input contains unexpected values?

### Use Assertions (When You're Confident)

Once you know expected values, you can use assertions:

```cpp
#include <cassert>

int max = FindMax(arr, size);
assert(max == 92);  // Program stops if this is false
```

This is useful for automated testing but can be harsh during development. Use with caution.

### Keep a Test Log

While testing, keep notes:

```
Assignment 1 Testing Log:
- [✓] PrintScores works with 5 elements
- [✓] FindMax works with positive numbers
- [✗] FindMax fails with negative numbers - FIXED: initialized max to arr[0] instead of 0
- [✓] CalculateAverage returns correct value
- [✓] Menu loops correctly
- [✓] Invalid menu input is handled
```

## Common Testing Mistakes

### ❌ Only testing with one input

Don't just test with the example from the assignment. Try variations.

### ❌ Not testing edge cases

The bugs are usually hiding at the boundaries.

### ❌ Assuming it works because it compiles

Compiling means valid C++. It doesn't mean correct logic.

### ❌ Testing everything at once

If you test the whole program and something's wrong, you don't know where the bug is.

## Example: Complete Test Session for Assignment 1

```
$ ./score_manager

How many scores? 5
Enter score 1: 85
Enter score 2: 90
Enter score 3: 78
Enter score 4: 92
Enter score 5: 88

=== Menu ===
1. Print all scores
2. Find maximum score
3. Find minimum score
4. Calculate average
5. Count scores above threshold
0. Quit
Choice: 1

Scores: 85 90 78 92 88

=== Menu ===
...
Choice: 2

Maximum score: 92

Choice: 3

Minimum score: 78

Choice: 4

Average score: 86.6

Choice: 5

Enter threshold: 80
Scores above 80: 3

Choice: 0

Goodbye!

----- Test 2: Edge case (single score) -----
$ ./score_manager

How many scores? 1
Enter score 1: 100

Choice: 2
Maximum score: 100

Choice: 3
Minimum score: 100  ✓ Works!

----- Test 3: Edge case (zero scores) -----
How many scores? 0

Choice: 2
Error: No scores entered  ✓ Handles gracefully!
```

## When You Find a Bug

1. **Reproduce it reliably** - Can you make it happen every time?
2. **Isolate it** - Which function is causing the problem?
3. **Understand it** - What is the program actually doing vs. what you expected?
4. **Fix it** - Change one thing at a time
5. **Test again** - Verify the fix and check you didn't break something else

## Before Submitting

### Final Checklist

- [ ] Program compiles with no warnings (`g++ -Wall`)
- [ ] Tested with normal inputs
- [ ] Tested with edge cases
- [ ] Tested with invalid inputs
- [ ] No debug print statements left in code
- [ ] Reflection questions answered

### Run It One More Time

Start fresh and run through all functionality as if you're seeing it for the first time. Pretend you're the grader.

---

**Remember:** Good testing is a skill that improves with practice. The goal isn't to prove your code works—it's to find where it breaks, so you can fix it.

*Test early, test often, test thoroughly.*
