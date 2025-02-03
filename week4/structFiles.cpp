#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Pet {
  char name[50];
  char species[50];
  int age;
};

void printPets(Pet db[], int n){
  cout << "The pets I know about are:" << endl;
  for(int i=0; i < n; i++){
    cout << db[i].name << " is a " << db[i].species << " and is " << db[i].age << " years old" << endl;
  }
}

void addPet(Pet db[], int& n){
  Pet newPet;
  cout << "Enter the pet's name: ";
  cin >> newPet.name;
  cout << "Enter the pet's species: ";
  cin >> newPet.species;
  cout << "Enter the pet's age: ";
  cin >> newPet.age;

  db[n] = newPet; // put it at the end
  n++; // increase the number of pets
}

void delPet(Pet db[], int& n){ // delete from the end
  // which is easy
  n--;
}

void parsePet(ifstream& f, Pet db[], int&n){

  int i = 0;
  do {
    Pet temp;
    
    // use the fact that getline can be used with
    // delimiters other than \n
    f.getline(temp.name,50,',');
    f.getline(temp.species,50,',');
    f >> temp.age;
    f.ignore(256,'\n');
    if(!f.fail()){
      db[i] = temp;
      i++;
    }
  }while(!f.fail());
  n = i;
}

int main(){

  // let our file be pets.txt
  ifstream inputPets("pets.txt");

  Pet petDB[100];
  int numPets = 0;
  int menu;
  
  // if the file exists then we want to
  // load data from the file first
  // if the file does not exist, we want to
  // go straight to adding entries via a menu
  
  if(inputPets){
    // add our reading and parsing code
    parsePet(inputPets,petDB,numPets);
    inputPets.close();
  }

  do {
    cout << endl;
    cout << "Welcome to our pets database!" << endl;
    cout << "Choose a menu option: " << endl;
    cout << "1: Add a pet" << endl;
    cout << "2: Delete a pet" << endl;
    cout << "3: See all known pets" << endl;
    cout << "0: Quit and write out the data" << endl;
    cout << endl;
    cin >> menu;
    switch(menu){
    case 1:
      addPet(petDB,numPets);
      break;
    case 2:
      delPet(petDB,numPets);
      break;
    case 3:
      printPets(petDB,numPets);
      break;
    }
    
  }while(menu != 0);

  ofstream outPets("pets.txt");
  for(int i=0; i < numPets; i++){
    // print as name,species,age
    outPets << petDB[i].name << ',' << petDB[i].species << ',' << petDB[i].age << endl;
  }

  outPets.close();
  return 0;
}
