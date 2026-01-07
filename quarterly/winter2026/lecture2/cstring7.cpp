#include <iostream>
#include <cstring>
using namespace std;

// let's write a function that counts the length of the string

size_t strlen(const char str[]){
  int i = 0;
  while(str[i] != '\0'){
    i++;
  }
  
  return i;
}

int main(){

  char msg[100] = "hey there";

  msg[50] = 'h';
  msg[51] = 'i';

  cout << msg << endl;
  cout << strlen(msg) << endl;

  cout << (int)msg[strlen(msg)] << endl;
  
  return 0;
}
