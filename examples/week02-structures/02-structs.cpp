/*
 * 02-structs.cpp
 * Creating custom data types by bundling related fields together.
 *
 * A struct is a blueprint for a new type. Once defined, you can
 * create variables of that type and access their fields with dot notation.
 */

#include <iostream>
#include <string>
using namespace std;

// Define a struct OUTSIDE of main (so it's visible everywhere)
// This doesn't create any variables - it's just a blueprint
struct Pet {
    string name;
    string species;
    int age;
    double weight;  // in pounds
};

// Another struct example
struct Rectangle {
    double width;
    double height;
};

// Functions can take structs as parameters
void printPet(Pet p) {
    cout << p.name << " is a " << p.age << "-year-old " << p.species;
    cout << " weighing " << p.weight << " lbs" << endl;
}

// Pass by reference to modify the original
void haveBirthday(Pet& p) {
    p.age++;
    cout << "Happy birthday, " << p.name << "! Now " << p.age << " years old." << endl;
}

// Functions can return structs too
double area(Rectangle r) {
    return r.width * r.height;
}

int main() {
    // === Creating struct instances ===
    cout << "=== Creating pets ===" << endl;

    // Method 1: Declare, then assign fields
    Pet cat;
    cat.name = "Whiskers";
    cat.species = "Cat";
    cat.age = 5;
    cat.weight = 10.5;

    // Method 2: Initialize all at once (in order of declaration)
    Pet dog = {"Buddy", "Dog", 3, 45.0};

    printPet(cat);
    printPet(dog);
    cout << endl;

    // === Modifying struct fields ===
    cout << "=== Modifications ===" << endl;
    cat.weight = 11.0;  // Whiskers gained some weight
    cout << "Whiskers now weighs " << cat.weight << " lbs" << endl;

    haveBirthday(dog);  // Pass by reference - modifies original
    printPet(dog);
    cout << endl;

    // === Structs are copied by default ===
    cout << "=== Copy behavior ===" << endl;
    Pet catCopy = cat;  // Makes a complete copy
    catCopy.name = "Whiskers Jr.";
    catCopy.age = 1;

    cout << "Original: ";
    printPet(cat);
    cout << "Copy: ";
    printPet(catCopy);
    cout << "(Changing the copy didn't affect the original)" << endl;
    cout << endl;

    // === Comparing struct fields ===
    cout << "=== Comparisons ===" << endl;
    // Note: you can't use == on whole structs (by default)
    // You have to compare field by field
    if (cat.species == dog.species) {
        cout << "Same species!" << endl;
    } else {
        cout << cat.name << " and " << dog.name << " are different species." << endl;
    }

    if (cat.age > dog.age) {
        cout << cat.name << " is older." << endl;
    } else {
        cout << dog.name << " is older (or same age)." << endl;
    }
    cout << endl;

    // === Using the Rectangle struct ===
    cout << "=== Rectangle example ===" << endl;
    Rectangle box = {5.0, 3.0};
    cout << "Rectangle: " << box.width << " x " << box.height << endl;
    cout << "Area: " << area(box) << endl;

    return 0;
}

/*
 * Struct vs. Class (preview):
 *
 * In C++, structs and classes are almost identical.
 * The main difference: struct members are public by default,
 * class members are private by default.
 *
 * For this course, we'll use structs. Classes come in CS162.
 *
 * When to use a struct:
 * - When you have related data that belongs together
 * - When you find yourself making parallel arrays
 * - When a function needs to return multiple values
 */
