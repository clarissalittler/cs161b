#include <iostream>
#include <fstream>
using namespace std;

int main(){

  ifstream f("goof.txt");
  ofstream o("outer.txt");
  
  int thing;
  while(f >> thing){
    o << thing << endl;
  }

  f.close();
  o.close();
  return 0;
}
