#include <iostream>
using namespace std;

int main(){

  // let's first talk about how ASCII works
  // in C a char type is really a special 8-bit integer
  // why?
  // because ASCII represents the characters
  // with not even the whole byte
  // A byte can name 256 things, but ASCII
  // actually only uses 7 bits (0 - 127)

  char boop = 'A';
  char beep = boop +1;

  cout << beep << endl;
  
  return 0;
}
