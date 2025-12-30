/*
 * Mini-Project: String Toolkit (Solution)
 */

#include <iostream>
using namespace std;

int myStrlen(const char* s) {
    int len = 0;
    if (s == nullptr) {
        return 0;
    }
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void myStrcpy(char* dest, const char* src) {
    if (dest == nullptr || src == nullptr) {
        return;
    }
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int myStrcmp(const char* a, const char* b) {
    if (a == nullptr && b == nullptr) {
        return 0;
    }
    if (a == nullptr) {
        return -1;
    }
    if (b == nullptr) {
        return 1;
    }
    while (*a && *a == *b) {
        a++;
        b++;
    }
    return static_cast<unsigned char>(*a) - static_cast<unsigned char>(*b);
}

void myReverse(char* s) {
    if (s == nullptr) {
        return;
    }
    int len = myStrlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

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

    cout << "=== Interactive Demo ===" << endl;
    char input[100];
    cout << "Enter a string (no spaces): ";
    cin >> input;

    cout << "Length: " << myStrlen(input) << endl;

    myReverse(input);
    cout << "Reversed: " << input << endl;

    char another[100];
    myReverse(input);
    cout << "Enter another string to compare (no spaces): ";
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
