#include <iostream>
using namespace std;

int main(){

  char msg[100] = "hey there";
  for(int i=0; i<100; i++){
    if(msg[i] == '\0'){
      msg[i] = '\n';
    }
  }
  // there are no longer any nulls!
  
  for(int i=0; msg[i] != '\0'; i++){
    cout << (int)msg[i] << endl;
  }
  cout << endl;
  
  return 0;
}
