#include <iostream>
using namespace std;

int main(){

  // null is \0
  // \n

  // POP QUIZ: how many characters can *really*
  // be in the message stored in msg[50]?
  char msg[50] = "Hey there I'm silly";
  
  string silly = "Hi I'm a 0";
  /*
  // first shot
  for(int i = 0; i < 50; i++){
    cout << msg[i] << "_";
  }
  */
  // null-terminated iteration
  int i=0;
  while(msg[i] != '\0'){
    cout << static_cast<int>(msg[i]) << "_";
    i++;
  }
  cout << endl;

  cout << "The " << i << "th indexed element of the array is: " << static_cast<int>(msg[i]) << endl;
  
  return 0;
}
