# Assignment 3: Image Transformer

## Concepts

This assignment focuses on the following key concepts:

- Dynamic memory management
- Structs and basic function-based manipulation of data

## Assignment Overview

You will design and implement a simple **Image Transformer** in C++ that represents an image as a dynamically allocated 2D array of **Pixel** objects. This will give you hands-on experience with structs, memory management, and fundamental programming concepts in C++.

## Requirements

### 1. Create a Pixel Struct

- Define a `Pixel` struct to represent the individual components of an image pixel.
  - If you are using color, include fields such as `red`, `green`, and `blue` (as integers).
  - If you are only representing grayscale, include a single value (e.g., `int intensity`).

### 2. Create an Image Struct

- Define an `Image` struct that contains:
  - A pointer to a dynamically allocated 2D array of `Pixel` objects.
  - Integers to store the image `width` and `height`.

### 3. Implement Basic Functions

- Write **standalone functions** that operate on `Image` and `Pixel` structs. These functions should take `Image` and `Pixel` structs as arguments or return modified `Image` structs.
- Implement at least two of the following image manipulation functions:
  - **Flip Horizontally**: Reverse the pixel order for each row in the image.
  - **Convert to Grayscale**: If your image uses color, implement a function to convert it to grayscale.
  - **Simple Filter**: Apply a basic filter to the image (e.g., darken all pixels or increase brightness).

### 4. Input/Output

- Use the **P3 format** of the Netpbm image family for input and output.

#### What is the P3 Format?

The P3 format is a simple, human-readable text-based image format. It consists of:

- A header containing the image dimensions and maximum color value.
- Pixel values represented as integers for red, green, and blue channels.

**Structure of a P3 File:**
```
P3
WIDTH HEIGHT
MAX_COLOR_VALUE
r1 g1 b1 r2 g2 b2 ...
r3 g3 b3 r4 g4 b4 ...
```

- **P3**: Identifies the format.
- **width, height**: Image dimensions.
- **max_color_value**: Maximum color value (usually 255).
- **Pixel values**: Each pixel has 3 integers (red, green, and blue), separated by spaces.

**Example of a 2x2 P3 File:**
```
P3
2 2
255
255 0 0    0 255 0
0 0 255    128 128 128
```

- This represents a 2x2 image with four pixels: red, green, blue, and gray.

Your program should:

- **Read** an input image file in P3 format.
- **Write** the manipulated image back to a file in the same P3 format.

## Hints (examples in the repo)

- Dynamic 2D arrays + file parsing structure: [examples-from-videos/week6/p1commented.cpp](../examples-from-videos/week6/p1commented.cpp)
- Example P3 input file: [pikachu.ppm](pikachu.ppm)
- Generalizing from P1 to P3: use the same file-parsing flow, but store each pixel as a `Pixel` struct with three fields (red, green, blue) instead of a single value.

## Reflection Questions

After completing the coding portion of the assignment, answer the following reflection questions. Only a couple of sentences are necessary for each.

1. **Initial Approach:**
   - *How did you begin working on this assignment—did you plan or sketch out a design first, or did you jump straight into coding? Briefly explain why you took that approach.*

2. **Challenges & Problem-Solving:**
   - *What was the most challenging aspect of the assignment, and how did you address it?*

3. **Testing & Debugging:**
   - *How did you test your code, and can you describe one example of a bug you discovered and how you fixed it?*

4. **Design & Structure Improvements:**
   - *If you had more time, what would you change in your code's structure or style to improve clarity or maintainability?*

5. **Conceptual Understanding:**
   - *Did this project change or deepen your understanding of how structs or memory management work? Describe one insight you gained.*

## Grading Policy

This assignment will be graded out of 4:

- **4**: The assignment is bug-free, meets all requirements, and includes completed reflection questions.
- **3**: The assignment meets requirements but may include minor bugs or does not include completed reflection questions.
- **2**: The assignment is incomplete or contains significant errors.
- **1**: The submission shows minimal effort or is largely non-functional.
- **0**: No submission.

**Note**: If the reflection questions are not turned in, the **highest grade you can receive is a 3**.

## What you need to submit

1. Your source file
2. Completed reflection questions.
3. An example of running your program to transform an image

## Tips

- Test each method you implement individually.
- Write clear comments and document your code for better maintainability.
- Ensure dynamic memory is properly managed to avoid memory leaks or segmentation faults.

Good luck and have fun coding!
