// Include the input/output stream library
#include <iostream>

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main(){
    // Declare arrays to store pet information
    // Each array can hold up to 50 entries
    string names[50];      // Array to store pet names
    string specieses[50];  // Array to store pet species
    int ages[50];          // Array to store pet ages

    // Counter to keep track of how many pets have been added
    int petsAdded = 0;

    // Variable to control whether user wants to continue adding pets
    string toContinue;
  
    // Start a do-while loop that allows multiple pet entries
    // The loop will run at least once, then continue based on user input
    do {
        // Prompt user to enter pet information
        cout << "Enter data about your pets (up to 50 entries total)" << endl;

        // Ask for and store pet name
        // Stores name in names array at the current petsAdded index
        cout << "Name: ";
        cin >> names[petsAdded];

        // Ask for and store pet species
        // Stores species in specieses array at the current petsAdded index
        cout << "Species: ";
        cin >> specieses[petsAdded];

        // Ask for and store pet age
        // Stores age in ages array at the current petsAdded index
        cout << "Age: ";
        cin >> ages[petsAdded];

        // Increment the pets added counter
        // This ensures next entry goes into next array index
        petsAdded++;

        // Ask user if they want to continue adding pets
        cout << "Do you with to continue? yes or no: ";
        cin >> toContinue;

    // Continue loop if user does NOT enter "no"
    } while(toContinue != "no");
  
    // After collecting all pet data, print out a summary
    // Loop through all added pets
    for(int i = 0; i < petsAdded; i++){
        // Print detailed information about each pet
        // Uses array indices to access specific pet's information
        cout << names[i] << " is a " << specieses[i] 
             << " and is " << ages[i] << " years old!" << endl;
    }
  
    // Indicate successful program completion
    return 0;
}
