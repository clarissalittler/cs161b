/*
 * 02-input-output.cpp
 * Getting information from the user.
 *
 * cin (character input) reads from the keyboard
 * cout (character output) writes to the screen
 *
 * Think of them as pipes: data flows from cin into your variables,
 * and from your variables into cout.
 */

#include <iostream>
using namespace std;

int main() {
    // Declare variables to hold user input
    string name;
    int age;

    // Prompt and read the name
    // Note: the prompt doesn't have endl - we want the cursor to stay on the same line
    cout << "What's your name? ";
    cin >> name;

    // Prompt and read the age
    cout << "How old are you? ";
    cin >> age;

    // Respond with what we learned
    cout << endl;  // Blank line for readability
    cout << "Hello, " << name << "!" << endl;
    cout << "You are " << age << " years old." << endl;

    // A little calculation to show we can do things with the input
    int dogYears = age * 7;
    cout << "That's " << dogYears << " in dog years!" << endl;

    return 0;
}

/*
 * Try this:
 * - What happens if you enter a number for the name?
 * - What happens if you enter a word for the age?
 * - What happens if you enter a name with a space in it?
 *
 * (Spoiler: cin >> stops at whitespace. We'll learn about getline later.)
 */
