#include <iostream>
#include <fstream>
using namespace std;

struct majorStats {
  int code;
  string major;
  string category;
  int total;
  int men;
  int women;
  int salary;
};

majorStats parseMajor(ifstream& f){
  majorStats m;
  f >> m.code;
  f >> m.major;
  f >> m.category;
  f >> m.total;
  f >> m.men;
  f >> m.women;
  f >> m.salary;

  return m;
}

void printMajor(majorStats m){
  cout << m.major << ": ";
  cout << m.total << " ";
  cout << m.salary << endl;
}

int main(){

  ifstream stemmy("stem.txt");

  int lines = 0;
  char ln[100];
  stemmy.getline(ln,100);
  while(stemmy.getline(ln,100)){
    lines++;
  }

  cout << lines << endl;

  // we can close the input stream and reopen it!
  // OR we can seek back to the beginning
  
  stemmy.clear(); // IN ORDER TO SEEK BACK TO THE START
  // we have to clear the stream from the eof bit being on
  stemmy.seekg(0);

  stemmy.getline(ln,100);
  cout << ln << endl;
  majorStats* majors = new majorStats[lines];
  for(int i=0; i<lines; i++){
    majors[i] = parseMajor(stemmy);
  }

  for(int i=0; i<lines; i++){
    printMajor(majors[i]);
  }

  delete[] majorStats;
  
  return 0;
}
