# Disclaimer
    The following is a synthetic tutorial derived by machine from the examples I show in videos. The code and explanations should be correct but may have a slightly different flavor than how I explain things. 
    
# Tutorial

**I. Introduction to C-Style Strings**

*   **What are C-style strings?**
    *   In C++, a C-style string is simply an array of characters (`char`) that is terminated by a special character called the **null terminator** (`\0`).
    *   The null terminator signals the end of the string. It's like a period at the end of a sentence.
    *   Think of it like this:  `char myString[6] = "Hello";`  Here, `myString` can hold 5 characters, and the 6th position is reserved for `\0`.

*   **Example 1: Character Array Initialization and Null Terminator**

    ```c++
    #include <iostream>
    using namespace std;

    int main() {
        char msg[50] = "Hey there I'm silly"; 

        // ... (rest of the code)
        return 0;
    }
    ```

    *   **Explanation:**
        *   `char msg[50]` declares a character array named `msg` that can store up to 50 characters.
        *   `= "Hey there I'm silly"` initializes the array with the string literal. The compiler automatically adds the null terminator (`\0`) at the end.
        *   **Important:** Even though `msg` is declared with size 50, it can effectively store a string of up to 49 characters because one space is always needed for the null terminator.

*   **Example 2: Iterating Through a C-Style String**

    ```c++
    int i = 0;
    while (msg[i] != '\0') {
        cout << static_cast<int>(msg[i]) << "_";
        i++;
    }
    cout << endl;
    ```

    *   **Explanation:**
        *   This code iterates through the `msg` array character by character until it encounters the null terminator.
        *   `while (msg[i] != '\0')`: This loop continues as long as the current character `msg[i]` is not the null terminator.
        *   `cout << static_cast<int>(msg[i]) << "_";`: This line prints the ASCII value of each character followed by an underscore. `static_cast<int>()` is used to convert the `char` to its integer representation (ASCII value).
        *   `i++`: The counter `i` is incremented to move to the next character in the array.

*   **Example 3: Demonstrating Null Terminator's Position**

    ```c++
    cout << "The " << i << "th indexed element of the array is: " 
         << static_cast<int>(msg[i]) << endl;
    ```

    *   **Explanation:**
        *   After the `while` loop in Example 2 finishes, `i` will hold the index of the null terminator.
        *   This code prints the index `i` and the ASCII value of the character at that index (which will be 0, the ASCII value of `\0`).

**II. Working with Strings: Copying and Input**

*   **Example 4: Implementing a String Copy Function (`ourStrcpy`)**

    ```c++
    #include <iostream>
    #include <cstring> // Although not directly used, it's relevant for context
    using namespace std;

    void ourStrcpy(char dest[], char src[]) {
        int i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = src[i]; // Copy the null terminator too
    }
    ```

    *   **Explanation:**
        *   This function mimics the behavior of the standard C library function `strcpy`.
        *   `void ourStrcpy(char dest[], char src[])`: The function takes two character arrays as input: `dest` (the destination where the string will be copied) and `src` (the source string).
        *   The `while` loop copies each character from `src` to `dest` until the null terminator is encountered.
        *   `dest[i] = src[i];`: The null terminator is also copied to ensure that `dest` becomes a valid C-style string.

*   **Example 5: String Input and Output using `cin` and `cout`**

    ```c++
    int main() {
        char msg1[50];
        char oldMsg[50] = "beepity boopity boppity ba-blam";

        cout << "Say something: ";
        cin >> msg1;       // Read user input into msg1
        cout << msg1 << endl;  // Echo input back to user

        ourStrcpy(oldMsg, msg1); // Copy msg1 to oldMsg

        // ... (rest of the code)
        return 0;
    }
    ```

    *   **Explanation:**
        *   `cout << "Say something: ";`: Prompts the user to enter a string.
        *   `cin >> msg1;`: Reads a space-delimited string from the console and stores it in `msg1`. **Important:** `cin >>` with a character array reads until it encounters whitespace (space, tab, newline). It automatically adds a null terminator.
        *   `cout << msg1 << endl;`: Prints the string entered by the user.

**III. Modifying C-Style Strings**

*   **Example 6: Overwriting Part of a String**

    ```c++
    #include <iostream>
    using namespace std;

    int main() {
        char msg[50] = "Hey there I'm silly";
        for (int i = 19; i < 50; i++) {
            msg[i] = 'x';
        }
        cout << msg << endl; 
        // ...
        return 0;
    }
    ```

    *   **Explanation:**
        *   This code overwrites a portion of the `msg` array with the character 'x', starting from index 19.
        *   `cout << msg << endl;`: When you print `msg` using `cout`, the output will stop at the first null terminator it encounters. If the original null terminator was overwritten, and no new one was added before the end of the array, `cout` might print beyond the intended end of the string, potentially displaying garbage characters. This highlights the importance of null terminators in C-style strings.

**IV. Building a Simple "Hangman" Game**

*   **Example 7: Core Game Logic**

    ```c++
    #include <iostream>
    #include <cstring> // For strlen (not directly used in the final version, but relevant)
    using namespace std;

    int ourStrlen(char s[]) {
        int i = 0;
        while (s[i] != '\0') {
            i++;
        }
        return i;
    }

    bool checkGuess(char g, char s[], char p[]) {
        int i = 0;
        bool found = false;
        while (s[i] != '\0') {
            if (s[i] == g) {
                found = true;
                p[i] = s[i];
            }
            i++;
        }
        return found;
    }

    bool areEqualStrs(char s1[], char s2[]) {
        // ... (implementation in the original code)
    }

    int main() {
        char secret[50] = "chicken";
        char partial[50];

        for (int i = 0; i < ourStrlen(secret); i++) {
            partial[i] = '_';
        }
        partial[ourStrlen(secret)] = '\0';

        // ... (rest of the game loop)
        return 0;
    }
    ```

    *   **Explanation:**
        *   **`ourStrlen`:** This function calculates the length of a C-style string (excluding the null terminator).
        *   **`checkGuess`:**  This function takes a guessed character (`g`), the secret word (`s`), and the partially revealed word (`p`). It checks if the guessed character exists in the secret word. If it does, it updates the `p` array to reveal the letter's position(s) and returns `true`; otherwise, it returns `false`.
        *   **`areEqualStrs`:** This function compares two C-style strings to see if they are identical.
        *   **`main` (Game Setup):**
            *   `secret`: Stores the secret word.
            *   `partial`: Stores the partially revealed word, initially filled with underscores.
            *   The loop initializes `partial` with underscores, the same length as `secret`.

*   **Example 8: Game Loop and Win/Lose Conditions**

    ```c++
    int guessesLeft = 5;
    char guess;

    do {
        cout << "The phrase: " << partial << endl;
        cout << "Guesses left: " << guessesLeft << endl;
        cout << "Enter your guess: ";
        cin >> guess;

        if (!checkGuess(guess, secret, partial)) {
            cout << "Whoops!" << endl;
            guessesLeft--;
        } else if (areEqualStrs(secret, partial)) {
            cout << "Yay you win!" << endl;
            return 0;
        }

    } while (guessesLeft > 0);

    cout << "Dang, you lost!" << endl;
    cout << "The real secret was: " << secret << endl;
    ```

    *   **Explanation:**
        *   **`guessesLeft`:** Keeps track of the number of remaining guesses.
        *   **`guess`:** Stores the player's letter guess.
        *   **`do...while` loop:** This loop continues until the player either wins or runs out of guesses.
        *   **Inside the loop:**
            *   The current state of `partial` and the number of `guessesLeft` are displayed.
            *   The player is prompted to enter a guess.
            *   `checkGuess` is called to process the guess.
            *   If the guess is incorrect (`!checkGuess(...)`), a message is printed, and `guessesLeft` is decremented.
            *   If the guess is correct and the `partial` word now matches the `secret` word (`areEqualStrs(...)`), the player wins, a message is printed, and the program exits.
        *   **After the loop:** If the loop finishes (meaning `guessesLeft` reached 0), the player has lost, and the secret word is revealed.

*   **Example 9: Enhancing the Game with Random Words**

    ```c++
    #include <iostream>
    #include <cstring>
    #include <ctime>
    #include <cstdlib>
    using namespace std;

    // ... (checkGuess function)

    int main() {
        srand(time(0)); // Seed the random number generator

        char words[5][50] = {"chicken", "pants", "dapper", "houndstooth", "kettle"};

        int word1 = rand() % 5;
        int word2 = rand() % 5;

        char secret[50];
        strcpy(secret, words[word1]);
        strcat(secret, " ");
        strcat(secret, words[word2]);

        // ... (rest of the game logic)
        return 0;
    }
    ```

    *   **Explanation:**
        *   **`#include <ctime>` and `#include <cstdlib>`:** These header files are included for time-related functions (used for seeding the random number generator) and general utility functions (including `rand` and `srand`).
        *   **`srand(time(0))`:** This line seeds the random number generator using the current time. This ensures that you get a different sequence of random numbers each time you run the program.
        *   **`char words[5][50]`:** This declares a 2D array of characters, essentially an array of 5 strings, each of which can hold up to 49 characters (plus the null terminator).
        *   **`rand() % 5`:** `rand()` generates a pseudo-random integer. The modulo operator (`%`) gives you the remainder of the division by 5, resulting in a random number between 0 and 4 (inclusive), which is used to select a random word from the `words` array.
        *   **`strcpy` and `strcat`:** These standard C string functions are used to build the `secret` phrase:
            *   `strcpy(secret, words[word1])`: Copies the first randomly chosen word into `secret`.
            *   `strcat(secret, " ")`: Appends a space to `secret`.
            *   `strcat(secret, words[word2])`: Appends the second randomly chosen word to `secret`.

**V. Pointers and References**

*   **Example 10: Introduction to Pointers**

    ```c++
    #include <iostream>
    using namespace std;

    int main() {
        int thing = 10;
        int* thingAddr = &thing; 

        // ...
        return 0;
    }
    ```

    *   **Explanation:**
        *   `int thing = 10;`: Declares an integer variable `thing` and initializes it to 10.
        *   `int* thingAddr = &thing;`: This is the core of pointer declaration:
            *   `int*`: Declares a variable `thingAddr` that is a pointer to an integer. The `*` indicates that it's a pointer.
            *   `&thing`: The address-of operator (`&`) gets the memory address of the variable `thing`.
            *   So, `thingAddr` now stores the memory address where the value of `thing` is located.

*   **Example 11: Pointer Arithmetic and Arrays**

    ```c++
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i * i + 100;
    }

    for (int i = 0; i < 10; i++) {
        cout << "arr[i] is: " << arr[i] << endl;
        cout << "*(arr+i) is: " << *(arr + i) << endl;
    }
    ```

    *   **Explanation:**
        *   `int arr[10];`: Declares an integer array named `arr` with 10 elements.
        *   **Array Names as Pointers:** In C++, the name of an array (like `arr`) decays into a pointer to the first element of the array.
        *   **Pointer Arithmetic:**
            *   `arr + i`: This expression performs pointer arithmetic. Since `arr` is a pointer to the beginning of the array, `arr + i` calculates the memory address that is `i` integer-sized memory locations away from the start of the array.
            *   `*(arr + i)`: The dereference operator (`*`) accesses the value stored at the memory address calculated by `(arr + i)`. This is equivalent to `arr[i]`.

*   **Example 12: Introduction to References**

    ```c++
    #include <iostream>
    using namespace std;

    void doubler(int& num) {
        num = 2 * num;
    }

    int main() {
        int thing = 10;
        doubler(thing);
        cout << "Now thing is: " << thing << endl; // Output: 20
        return 0;
    }
    ```

    *   **Explanation:**
        *   `void doubler(int& num)`: This function declares a parameter `num` that is a **reference** to an integer.
            *   `int&`: The `&` after the type indicates that `num` is a reference.
        *   **References as Aliases:** A reference is essentially an alias for another variable. When you modify `num` inside the `doubler` function, you are directly modifying the original variable that was passed to the function (in this case, `thing`).
        *   `doubler(thing)`: When you call `doubler` and pass `thing`, the `num` reference inside the function becomes an alias for `thing`.

*   **Example 13: Modifying Array Elements Using Pointers**

    ```c++
    #include <iostream>
    using namespace std;

    void doubler(int* num, int l) {
        for (int i = 0; i < l; i++) {
            *(num + i) = 2 * (*(num + i));
        }
    }

    int main() {
        int thing[10];
        // ... (initialize array)
        doubler(thing, 10); // Pass the array (which decays to a pointer) and its length
        // ... (print the array)
        return 0;
    }
    ```

    *   **Explanation:**
        *   `void doubler(int* num, int l)`: This function takes a pointer to an integer (`int* num`) and the length of the array (`int l`) as parameters.
        *   Inside the loop, `*(num + i)` is used to access each element of the array using pointer arithmetic, just like in Example 11. The value at each element is then doubled.

**VI. Important Library Functions**

Here's a summary of the key library functions used in these examples:

1. **`<iostream>`** (Input/Output Stream)
    *   **`cout`:** Used for outputting data to the console.
        *   `cout << "Hello";` // Outputs the string "Hello"
        *   `cout << x;` // Outputs the value of variable x
        *   `cout << "Value: " << x << endl;` // Output formatting
    *   **`cin`:** Used for reading input from the console.
        *   `cin >> x;` // Reads a value from the console and stores it in x
        *   `cin >> myString;` // Reads a space-delimited string into `myString` (for C-style strings)
    *   **`endl`:** Inserts a newline character and flushes the output buffer.
        *   `cout << "Hello" << endl;` // Outputs "Hello" followed by a newline

2. **`<cstring>`** (C String Library - not directly used in all examples but relevant for C-style strings)
    *   **`strcpy(char* dest, const char* src)`:** Copies a C-style string from `src` to `dest`.
    *   **`strcat(char* dest, const char* src)`:** Concatenates (appends) a C-style string from `src` to the end of `dest`.
    *   **`strlen(const char* str)`:** Returns the length of a C-style string (excluding the null terminator).
    *   **`strcmp(const char* str1, const char* str2)`:** Compares two C-style strings lexicographically. Returns 0 if they are equal, a negative value if `str1` comes before `str2`, and a positive value if `str1` comes after `str2`.

3. **`<ctime>`** (Time Library)
    *   **`time(time_t* timer)`:** Returns the current calendar time as a `time_t` value. Often used to seed random number generators.

4. **`<cstdlib>`** (General Utilities Library)
    *   **`rand()`:** Generates a pseudo-random integer.
    *   **`srand(unsigned int seed)`:** Seeds the random number generator. Using `time(0)` as the seed is common practice.
    *   **`static_cast<type>(expression)`:**  This is a C++ cast operator used for explicit type conversions. For example, `static_cast<int>(myChar)` converts the `char` variable `myChar` to its integer (ASCII) representation.

**VII. Key Concepts Summarized**

1. **C-Style Strings:** Character arrays terminated by a null character (`\0`).
2. **Null Terminator:** Marks the end of a C-style string.
3. **Arrays:** Contiguous blocks of memory used to store sequences of elements of the same data type.
4. **Pointers:** Variables that store memory addresses.
5. **Address-of Operator (`&`):** Returns the memory address of a variable.
6. **Dereference Operator (`*`):** Accesses the value stored at a memory address held by a pointer.
7. **Pointer Arithmetic:** Performing arithmetic operations on pointers to move through memory locations (often used with arrays).
8. **References:** Aliases for existing variables. Modifying a reference directly modifies the original variable.
9. **`cin` and `cout`:** Objects for input and output stream operations.
10. **Standard C String Functions (`strcpy`, `strcat`, `strlen`, `strcmp`):** Functions for manipulating C-style strings.
11. **Random Number Generation (`rand`, `srand`, `time`):** Functions for generating and seeding pseudo-random numbers.

