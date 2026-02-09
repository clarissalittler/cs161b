#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){

  ifstream in("test1.csv");
  // get rid of the header
  string garbage;
  getline(in,garbage);
  string line;
  while(getline(in,line)){
    stringstream ls(line);
    string name;
    string species;
    int age;

    getline(ls,name,',');
    getline(ls,species,',');
    ls >> age;

    cout << name << " is a " << species << " and is " << age << " years old" << endl;
  }
  
  
  return 0;
}
