#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main(){

  ifstream inFile("test1.csv");
  
  string s;
  getline(inFile,s);
  cout << s << endl; // should print the header, just for diagnostics
  while(getline(inFile,s)){
    // cout << s << endl; // should print each line
    stringstream streamy(s);
    string name;
    string species;
    string ageStr;

    getline(streamy,name,',');
    getline(streamy,species,',');
    getline(streamy,ageStr);

    int age = stoi(ageStr);

    cout << name << " is a " << species << " and is " << age << " years old" << endl;
  }

  inFile.close();
  return 0;
}
