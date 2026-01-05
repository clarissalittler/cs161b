#include <iostream>
using namespace std;

int main(){

  int n = 0;

  cout << n << endl;
  int* numaddr = &n; 
  cout << numaddr << endl;

  *numaddr = 10;

  cout << n << endl;

  
  return 0;
}
