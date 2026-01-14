#include <iostream>
using namespace std;

int main(){

  // XOR combines bits: different bits => 1, same bits => 0.
  char c1 = 'a';
  char c2 = 'b';
  char c3 = c1 ^ c2;

  // Printing c3 directly will likely show a non-letter character.
  cout << c3 << endl;

  // XOR is reversible: (c1 ^ c2) ^ c2 == c1.
  cout << (char)(c3 ^ c2) << endl;

  return 0;
}
