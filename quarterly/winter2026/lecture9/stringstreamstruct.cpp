#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

struct pet {
  string name;
  string species;
  int age;
};

void readPets(pet ps[], int& n, ifstream& f){
  string s;
  getline(f,s);
  while(getline(f,s) && n < 100){
    // cout << s << endl; // should print each line
    stringstream streamy(s);
    pet p;

    getline(streamy,p.name,',');
    getline(streamy,p.species,',');
    if(!(streamy >> p.age)){
      p.age = 0;
    }

    ps[n] = p;
    n++;
  }
}

void printPets(pet ps[], int n){
  for(int i=0; i<n; i++){
    cout << ps[i].name << " is a " << ps[i].species << " and is " << ps[i].age << " years old" << endl;
  }
}

int main(){

  pet pets[100];
  int numPets = 0;
  
  
  ifstream inFile("test1.csv");

  readPets(pets,numPets,inFile);
  printPets(pets,numPets);

  inFile.close();
  return 0;
}
