// Include input/output stream library
#include <iostream>
// Use standard namespace to avoid writing std:: before cout, cin, etc.
using namespace std;

// Define a struct to represent a pet with name, species, and age
struct Pet {
  string name;     // Stores the name of the pet
  string species;  // Stores the species of the pet
  int age;         // Stores the age of the pet
};

// Function to read pet details from user input
Pet readPet(){
  Pet p;  // Create a new Pet object to store input
  
  // Prompt user and read pet name
  cout << "Name: ";
  cin >> p.name;
  
  // Prompt user and read pet species
  cout << "Species: ";
  cin >> p.species;
  
  // Prompt user and read pet age
  cout << "Age: ";
  cin >> p.age; 
  
  // Return the completed Pet object
  return p;
}

// Main function - entry point of the program
int main(){
  // Create an array to store up to 50 pets
  Pet pets[50];
  
  // Track the number of pets added
  int petsAdded = 0;
  
  // String to control the input loop
  string toContinue;
  
  // Do-while loop to allow multiple pet entries
  do {
    // Inform user about input restrictions
    cout << "Enter data about your pets (up to 50 entries total)" << endl;
    
    // Call readPet() to get a new pet's details
    // Store the returned Pet in the pets array
    pets[petsAdded] = readPet();
    
    // Increment the count of pets added
    petsAdded++;
  
    // Ask user if they want to continue adding pets
    cout << "Do you wish to continue? yes or no:";
    cin >> toContinue;
  
  // Continue loop if user does not enter "no"
  } while(toContinue != "no");

  // Loop through all added pets
  for(int i = 0; i < petsAdded; i++){
    // Print out details of each pet
    cout << pets[i].name << " is a " << pets[i].species 
         << " and is " << pets[i].age << " years old!" << endl;
  }

  // Indicate successful program completion
  return 0;
}
