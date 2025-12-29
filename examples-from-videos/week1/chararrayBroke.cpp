#include <iostream>
using namespace std;

int main(){

  // null is \0
  // \n

  // POP QUIZ: how many characters can *really*
  // be in the message stored in msg[50]?
  char msg[50] = "Hey there I'm silly";
  for(int i = 19; i < 50; i++){
    msg[i] = 'x';
  }
  cout << msg << endl;

  /*
  // first shot
  for(int i = 0; i < 50; i++){
    cout << msg[i] << "_";
  }
  */
  // null-terminated iteration
  
  return 0;
}
