#include <iostream>
using namespace std;

int main(){

  string names[50];
  string specieses[50];
  int ages[50];
  int petsAdded = 0;
  string toContinue;
  
  // let's do this as a do-while
  // controlled by whether continue is !"no"

  do{
    cout << "Enter data about your pets (up to 50 entries total)" << endl;
    cout << "Name: ";
    cin >> names[petsAdded];
    cout << "Species: ";
    cin >> specieses[petsAdded];
    cout << "Age: ";
    cin >> ages[petsAdded];
    petsAdded++;

    cout << "Do you with to continue? yes or no: ";
    cin >> toContinue;
  } while(toContinue != "no");
  
  // print it all out in the end
  for(int i = 0; i < petsAdded; i++){
    cout << names[i] << " is a " << specieses[i] << " and is " << ages[i] << " years old!" << endl;
  }
  
  return 0;
}
