// THIS WON'T COMPILE

#include <iostream>
using namespace std;

int main(){

  char msg[] = "Hi there!";

  // with a string type I can reassign
  // with a c-string I can't
  msg = "Yup!     ";
  
  cout << msg << endl;
  
  return 0;
}
