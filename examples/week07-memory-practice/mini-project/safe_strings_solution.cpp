/*
 * Mini-Project: Memory-Safe Dynamic Strings (Solution)
 */

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char* createString(int capacity) {
    if (capacity <= 0) return nullptr;

    char* str = new char[capacity];
    str[0] = '\0';
    return str;
}

void freeString(char*& str) {
    if (str != nullptr) {
        delete[] str;
        str = nullptr;
    }
}

char* copyString(const char* src) {
    if (src == nullptr) return nullptr;

    int len = static_cast<int>(strlen(src)) + 1;
    char* copy = new char[len];
    strcpy(copy, src);
    return copy;
}

char* concatenate(const char* a, const char* b) {
    int lenA = (a != nullptr) ? static_cast<int>(strlen(a)) : 0;
    int lenB = (b != nullptr) ? static_cast<int>(strlen(b)) : 0;
    int total = lenA + lenB + 1;

    char* result = new char[total];
    result[0] = '\0';

    if (a != nullptr) {
        strcpy(result, a);
    }
    if (b != nullptr) {
        strcat(result, b);
    }

    return result;
}

void resizeString(char*& str, int newCapacity) {
    if (newCapacity <= 0) {
        freeString(str);
        return;
    }

    char* newStr = new char[newCapacity];
    newStr[0] = '\0';

    if (str != nullptr) {
        strncpy(newStr, str, newCapacity - 1);
        newStr[newCapacity - 1] = '\0';
        delete[] str;
    }

    str = newStr;
}

void testCreateAndFree() {
    cout << "=== Test createString/freeString ===" << endl;

    char* s1 = createString(10);
    if (s1 != nullptr) {
        cout << "Created string of capacity 10" << endl;
        cout << "Length: " << strlen(s1) << " (should be 0)" << endl;

        strcpy(s1, "Hello");
        cout << "After strcpy: \"" << s1 << "\"" << endl;

        freeString(s1);
        cout << "After free: s1 = " << (s1 == nullptr ? "nullptr" : "NOT null") << endl;
    }

    char* s2 = createString(0);
    cout << "createString(0) returns: " << (s2 == nullptr ? "nullptr" : "NOT null") << endl;

    freeString(s2);
    cout << endl;
}

void testCopyString() {
    cout << "=== Test copyString ===" << endl;

    const char* original = "Hello, World!";
    char* copy = copyString(original);

    if (copy != nullptr) {
        cout << "Original: \"" << original << "\"" << endl;
        cout << "Copy: \"" << copy << "\"" << endl;
        cout << "Same address? " << (original == copy ? "YES (bad!)" : "NO (good!)") << endl;
        freeString(copy);
    }

    char* nullCopy = copyString(nullptr);
    cout << "copyString(nullptr) returns: " << (nullCopy == nullptr ? "nullptr" : "NOT null") << endl;
    cout << endl;
}

void testConcatenate() {
    cout << "=== Test concatenate ===" << endl;

    char* result = concatenate("Hello, ", "World!");
    if (result != nullptr) {
        cout << "concatenate(\"Hello, \", \"World!\") = \"" << result << "\"" << endl;
        freeString(result);
    }

    result = concatenate(nullptr, "test");
    if (result != nullptr) {
        cout << "concatenate(nullptr, \"test\") = \"" << result << "\"" << endl;
        freeString(result);
    }

    result = concatenate("test", nullptr);
    if (result != nullptr) {
        cout << "concatenate(\"test\", nullptr) = \"" << result << "\"" << endl;
        freeString(result);
    }

    result = concatenate(nullptr, nullptr);
    cout << "concatenate(nullptr, nullptr) = " << (result == nullptr ? "nullptr" : "\"" + string(result) + "\"") << endl;
    freeString(result);
    cout << endl;
}

void testResize() {
    cout << "=== Test resizeString ===" << endl;

    char* s = createString(10);
    if (s != nullptr) {
        strcpy(s, "Hello");
        cout << "Initial: \"" << s << "\" (capacity 10)" << endl;

        resizeString(s, 20);
        if (s != nullptr) {
            cout << "After resize to 20: \"" << s << "\"" << endl;

            strcat(s, ", World!");
            cout << "After append: \"" << s << "\"" << endl;
        }

        resizeString(s, 5);
        if (s != nullptr) {
            cout << "After resize to 5: \"" << s << "\" (truncated)" << endl;
        }

        freeString(s);
    }

    char* nullStr = nullptr;
    resizeString(nullStr, 10);
    if (nullStr != nullptr) {
        cout << "resizeString(nullptr, 10) created new string" << endl;
        freeString(nullStr);
    }
    cout << endl;
}

int main() {
    cout << "=== Safe String Functions Test ===" << endl << endl;

    testCreateAndFree();
    testCopyString();
    testConcatenate();
    testResize();

    cout << "=== All tests complete ===" << endl;
    cout << "Run with valgrind to check for memory leaks:" << endl;
    cout << "  valgrind ./safe_strings" << endl;

    return 0;
}
