#include <iostream>
using namespace std;

struct Goofus {
  int field1;
  string field2;
  bool field3;
};

void printGoofus(Goofus g){
  cout << "field1: " << g.field1 << endl;
  cout << "field2: " << g.field2 << endl;
  cout << "field3: " << g.field3 << endl;
}

int main(){

  Goofus g;

  g.field1 = 10;
  g.field2 = "boop";
  g.field3 = false;

  g.field1++;
  
  printGoofus(g);
  
  return 0;
}
