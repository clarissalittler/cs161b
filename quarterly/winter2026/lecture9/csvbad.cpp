#include <iostream>
#include <fstream>
using namespace std;

int main(){
  ifstream f("inconvenient.csv");
  string s1;
  int n2;
  int n3;
  char c;

  f >> s1;
  cout << s1 << endl;
  /*
  while(f >> s1 >> c >> n2 >> c >> n3){
    cout << s1 << " " << n2 << " " << n3 << endl;
  }
  */ 
  f.close();
  return 0;
}
