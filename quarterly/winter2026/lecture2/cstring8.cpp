#include <iostream>
#include <cstring>
using namespace std;

// let's write a function that counts the length of the string

int strlen(char str[]){
  int i = 0;
  while(str[i] != '\0'){
    i++;
  }
  
  return i;
}

bool streq(char str1[], char str2[]){
  int i=0;
  bool isEq = true;
  if(strlen(str1) == strlen(str2)){
    while(str1[i] != '\0'){
      isEq = isEq && (str1[i] == str2[i]);
      i++;
    }
  }
  else{
    isEq = false;
  }

  return isEq;
}

int main(){

  char msg2[100] = "hey there, my dude";
  char msg1[100] = "hey there";

  cout << streq(msg1,msg2) << endl;
  
  return 0;
}
