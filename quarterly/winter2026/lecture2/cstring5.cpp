#include <iostream>
using namespace std;

int main(){

  char msg[100] = "This is some text";

  // null-terminated strings loooove while loops
  int i=0;
  while(msg[i] != '\0'){
    cout << msg[i];
    i++;
  }
  cout << endl;
  
  return 0;
}
