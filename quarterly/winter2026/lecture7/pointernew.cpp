#include <iostream>
using namespace std;

// so far we've only used memory *statically*
// by which I mean we've always known all
// the memory that was going to be used ever by the program
// at compile time

int main(){

  int* numPoint = new int;

  cout << numPoint << endl;

  delete numPoint;
  
  return 0;
}
