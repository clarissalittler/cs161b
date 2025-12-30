/*
 * Mini-Project: String Toolkit
 *
 * Implement your own C-string functions without using the standard library.
 *
 * This is great practice for:
 * - Pointer arithmetic
 * - Understanding how C-strings work
 * - Writing functions that work with pointers
 */

#include <iostream>
using namespace std;

// TODO: Implement this function
// Returns the length of the string (not counting the null terminator)
int myStrlen(const char* s) {
    // Hint: walk through the string with a pointer or index
    // until you find '\0', counting as you go
    return 0;
}

// TODO: Implement this function
// Copies the string from src to dest (including the null terminator)
// Assumes dest has enough space!
void myStrcpy(char* dest, const char* src) {
    // Hint: copy characters one by one until you've copied the '\0'

}

// TODO: Implement this function
// Returns:
//   0 if the strings are equal
//   negative if a comes before b alphabetically
//   positive if a comes after b alphabetically
int myStrcmp(const char* a, const char* b) {
    // Hint: compare characters one by one
    // If you find a difference, return the difference
    // If both strings end at the same time, they're equal
    return 0;
}

// TODO: Implement this function
// Reverses the string in place (modifies the original)
void myReverse(char* s) {
    // Hint: swap the first and last, then move inward
    // You'll need to know the length first

}

// Helper function to print a test result
void test(const char* name, bool passed) {
    cout << (passed ? "[PASS] " : "[FAIL] ") << name << endl;
}

int main() {
    cout << "=== Testing myStrlen ===" << endl;
    test("empty string", myStrlen("") == 0);
    test("hello", myStrlen("hello") == 5);
    test("a", myStrlen("a") == 1);
    cout << endl;

    cout << "=== Testing myStrcpy ===" << endl;
    char buffer[50];
    myStrcpy(buffer, "hello");
    test("copy hello", myStrlen(buffer) == 5 && buffer[0] == 'h');
    myStrcpy(buffer, "");
    test("copy empty", myStrlen(buffer) == 0);
    cout << endl;

    cout << "=== Testing myStrcmp ===" << endl;
    test("equal strings", myStrcmp("hello", "hello") == 0);
    test("a < b", myStrcmp("apple", "banana") < 0);
    test("b > a", myStrcmp("banana", "apple") > 0);
    test("short < long", myStrcmp("app", "apple") < 0);
    test("empty strings equal", myStrcmp("", "") == 0);
    cout << endl;

    cout << "=== Testing myReverse ===" << endl;
    char rev1[] = "hello";
    myReverse(rev1);
    test("hello -> olleh", myStrcmp(rev1, "olleh") == 0);

    char rev2[] = "a";
    myReverse(rev2);
    test("a -> a", myStrcmp(rev2, "a") == 0);

    char rev3[] = "";
    myReverse(rev3);
    test("empty -> empty", myStrcmp(rev3, "") == 0);

    char rev4[] = "ab";
    myReverse(rev4);
    test("ab -> ba", myStrcmp(rev4, "ba") == 0);
    cout << endl;

    // Interactive demo
    cout << "=== Interactive Demo ===" << endl;
    char input[100];
    cout << "Enter a string: ";
    cin >> input;

    cout << "Length: " << myStrlen(input) << endl;

    myReverse(input);
    cout << "Reversed: " << input << endl;

    char another[100];
    myReverse(input);  // Reverse back to original
    cout << "Enter another string to compare: ";
    cin >> another;

    int cmp = myStrcmp(input, another);
    if (cmp == 0) {
        cout << "The strings are equal!" << endl;
    } else if (cmp < 0) {
        cout << "\"" << input << "\" comes before \"" << another << "\"" << endl;
    } else {
        cout << "\"" << input << "\" comes after \"" << another << "\"" << endl;
    }

    return 0;
}

/*
 * Implementation hints:
 *
 * myStrlen:
 *   int len = 0;
 *   while (s[len] != '\0') len++;
 *   return len;
 *
 * myStrcpy:
 *   int i = 0;
 *   while (src[i] != '\0') {
 *       dest[i] = src[i];
 *       i++;
 *   }
 *   dest[i] = '\0';  // Don't forget the null terminator!
 *
 * myStrcmp:
 *   while (*a && *a == *b) { a++; b++; }
 *   return *a - *b;
 *
 * myReverse:
 *   Find the length, then swap s[0] with s[len-1], s[1] with s[len-2], etc.
 */
