// Include necessary header files for input/output, file operations, and string manipulation
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Define a struct to represent a pet with name, species, and age
struct Pet {
  char name[50];     // Array to store pet's name (fixed size for simplicity)
  char species[50];  // Array to store pet's species
  int age;           // Integer to store pet's age
};

// Function to print all pets in the database
void printPets(Pet db[], int n){
  cout << "The pets I know about are:" << endl;
  // Iterate through the array of pets and print details
  for(int i=0; i < n; i++){
    cout << db[i].name << " is a " << db[i].species << " and is " << db[i].age << " years old" << endl;
  }
}

// Function to add a new pet to the database
void addPet(Pet db[], int& n){
  Pet newPet;  // Create a temporary pet object
  
  // Prompt user for pet details and store them
  cout << "Enter the pet's name: ";
  cin >> newPet.name;
  cout << "Enter the pet's species: ";
  cin >> newPet.species;
  cout << "Enter the pet's age: ";
  cin >> newPet.age;

  // Add the new pet to the end of the database
  db[n] = newPet; 
  n++;  // Increment the number of pets
}

// Function to delete a pet from the database (simple implementation - removes last pet)
void delPet(Pet db[], int& n){ 
  n--;  // Simply decrease the number of pets (effectively "deleting" the last pet)
}

// Function to parse pets from a file and populate the database
void parsePet(ifstream& f, Pet db[], int&n){
  int i = 0;
  do {
    Pet temp;  // Temporary pet to store parsed data
    
    // Read name up to comma delimiter
    f.getline(temp.name, 50, ',');
    // Read species up to comma delimiter
    f.getline(temp.species, 50, ',');
    // Read age (assumes age is an integer)
    f >> temp.age;
    // Ignore rest of the line to prepare for next pet
    f.ignore(256,'\n');
    
    // If reading was successful, add pet to database
    if(!f.fail()){
      db[i] = temp;
      i++;
    }
  }while(!f.fail());  // Continue until file reading fails
  n = i;  // Update number of pets
}

int main(){
  // Open input file for reading existing pets
  ifstream inputPets("pets.txt");

  Pet petDB[100];  // Array to store pets (maximum 100 pets)
  int numPets = 0;  // Counter for number of pets
  int menu;  // Variable to store user menu choice
  
  // Check if file exists and can be opened
  if(inputPets){
    // If file exists, parse pets from the file
    parsePet(inputPets,petDB,numPets);
    inputPets.close();  // Close the input file
  }

  // Main menu loop
  do {
    // Display menu options
    cout << endl;
    cout << "Welcome to our pets database!" << endl;
    cout << "Choose a menu option: " << endl;
    cout << "1: Add a pet" << endl;
    cout << "2: Delete a pet" << endl;
    cout << "3: See all known pets" << endl;
    cout << "0: Quit and write out the data" << endl;
    cout << endl;
    
    // Get user's menu choice
    cin >> menu;
    
    // Handle user's choice
    switch(menu){
    case 1:
      addPet(petDB,numPets);  // Add a new pet
      break;
    case 2:
      delPet(petDB,numPets);  // Delete a pet
      break;
    case 3:
      printPets(petDB,numPets);  // Print all pets
      break;
    }
    
  }while(menu != 0);  // Continue until user chooses to quit

  // Open output file to save pets
  ofstream outPets("pets.txt");
  
  // Write all pets to the file
  for(int i=0; i < numPets; i++){
    // Format: name,species,age
    outPets << petDB[i].name << ',' << petDB[i].species << ',' << petDB[i].age << endl;
  }

  outPets.close();  // Close the output file
  return 0;
}
