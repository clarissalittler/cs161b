#include <iostream>
#include <fstream>
using namespace std;

int main(){
  ifstream f("num.csv");
  int n1;
  int n2;
  int n3;
  char c;

  while(f >> n1 >> c >> n2 >> c >> n3){
    cout << n1 << " " << n2 << " " << n3 << endl;
  }
    
  f.close();
  return 0;
}
