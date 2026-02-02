#include <iostream>
#include <fstream>
using namespace std;

struct pet {
  string name;
  string species;
  int age;
};

void writePets(pet ps[], int petCount, ofstream& f){
  for(int i=0; i<petCount; i++){
    f << ps[i].name
      << " " << ps[i].species
      << " " << ps[i].age << endl;
  }
}

void readPets(pet ps[], int& petCount){
  // read this in from the console
  // then populate the array
  pet p;
  char done = 'n';
  while(done == 'n'){
    cout << "Enter the name of the pet: ";
    cin >> p.name;
    cout << "What kind of animal are they?: ";
    cin >> p.species;
    cout << "How old are they?: ";
    cin >> p.age;

    ps[petCount] = p;
    petCount++;
    
    cout << "Are you done entering data? y/n: ";
    cin >> done;
  }  
}

int main(){

  pet pets[100];
  int petCount = 0;
  ofstream f("petsdb.txt");

  cout << "Welcome to our pets database" << endl;
  readPets(pets,petCount);

  writePets(pets,petCount,f);
  f.close();
  
  return 0;
}
