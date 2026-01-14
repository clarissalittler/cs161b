#include <iostream>
using namespace std;

int main(){

  char c1 = 'a';
  char c2 = 'b';
  char c3 = c1 ^ c2;
  
  cout << c3 << endl;
  cout << (char)(c3 ^ c2) << endl;
  
  return 0;
}
