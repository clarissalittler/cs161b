#include <iostream>
using namespace std;

int main(){

  char msg[100] = "This is some text";

  // null-terminated strings loooove while loops
  for(int i=0; msg[i] != '\0';i++){
    cout << msg[i];
  }
  cout << endl;
  
  return 0;
}
