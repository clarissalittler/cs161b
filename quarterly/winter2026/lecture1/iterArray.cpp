#include <iostream>
using namespace std;

// let's write some functions
// fillPets takes the array and the size
// and increments the size and fills the array
// printPets which prints all the pets

void printPets(string names[], int size){
  for(int i=0; i < size; i++){
    cout << names[i] << endl;
  }
}

void fillPets(string names[], int &size){
  string input = "";
  bool keepGoing = true;

  cout << "Enter the names of all the pets you've had/known:" << endl;
  do {
    cout << "Please enter a name: ";
    cin >> names[size];
    cout << "Continue? y/n" << endl;
    cin >> input;
    if(input != "y"){
      keepGoing = false;
    }
    size++;
  }while(keepGoing);
}

int main(){

  string namesOfPets[100];
  int numPets = 0;

  fillPets(namesOfPets,numPets);
  printPets(namesOfPets, numPets);
  
  return 0;
}
