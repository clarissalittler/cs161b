#include <iostream>
using namespace std;

struct Pet {
  string name;
  string species;
  int age;
};

Pet readPet(){
  Pet p;
  cout << "Name: ";
  cin >> p.name;
  cout << "Species: ";
  cin >> p.species;
  cout << "Age: ";
  cin >> p.age; 
  return p;
}


int main(){

  Pet pets[50];
  int petsAdded= 0;
  string toContinue;
  do {
    cout << "Enter data about your pets (up to 50 entries total)" << endl;
    pets[petsAdded] = readPet();
    petsAdded++;
  
    cout << "Do you wish to continue? yes or no:";
    cin >> toContinue;
  } while(toContinue != "no");

  for(int i = 0; i < petsAdded; i++){
    cout << pets[i].name << " is a " << pets[i].species << " and is " << pets[i].age << " years old!" << endl;
  }

  return 0;
}
