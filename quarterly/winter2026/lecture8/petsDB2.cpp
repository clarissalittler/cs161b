#include <iostream>
#include <fstream>
using namespace std;

struct pet {
  string name;
  string species;
  int age;
};

// change ofstream& to fstream&
void writePets(pet ps[], int petCount, ofstream& f){
  for(int i=0; i<petCount; i++){
    f << ps[i].name
      << " " << ps[i].species
      << " " << ps[i].age << endl;
  }
}

void readPets(pet ps[], int& petCount, ifstream& f){
  bool keepGoing = true;
  pet p;
  while(keepGoing){
    f >> p.name;
    f >> p.species;
    f >> p.age;
    if(!f.fail()){ // whoops, I accidentally wrote cin.fail() not f.fail()
      ps[petCount] = p;
      petCount++;
    }
    else{
      keepGoing = false;
    }
  }  
}

void addPets(pet ps[], int& petCount){
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

void printPets(pet ps[], int petCount){
  for(int i=0; i<petCount; i++){
    cout << ps[i].name << " is a " << ps[i].species << " and is " << ps[i].age << endl;
  }
}

int main(){

  pet pets[100];
  int petCount = 0;
  ifstream fin("petsdb.txt"); 

  // now we read in pets from the file
  readPets(pets,petCount,fin);
  fin.close();
  ofstream fout("petsdb.txt");
  
  cout << "Welcome to our pets database" << endl;
  addPets(pets,petCount);
  printPets(pets, petCount);
  
  writePets(pets, petCount,fout);
  fout.close();
  
  return 0;
}
