/*
 * 06-const-references.cpp
 * Pass large values without copying, and protect them from changes.
 */

#include <iostream>
#include <string>
using namespace std;

void printMessage(const string& message) {
    cout << message << endl;
}

int countVowels(const string& message) {
    int count = 0;
    for (int i = 0; i < static_cast<int>(message.length()); i++) {
        char c = message[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    string text = "Functions are fun";
    printMessage(text);
    cout << "Vowels: " << countVowels(text) << endl;

    return 0;
}
