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

void strcat(char str1[], char str2 []){
  int endOfStr1 = strlen(str1);

  for(int i=0; i <= strlen(str2); i++){
    str1[i+endOfStr1] = str2[i];
  }
}

void strcpy(char str1[], char str2[]){
  // should copy the contents for the second string
  // into the first, destructively
  /*
  for(int i=0; i <=strlen(str2); i++){
    str1[i] = str2[i];
  }
  */

  int i=0;
  while(str2[i] != '\0'){
    str1[i] = str2[i];
    i++;
  }
  // now str2[i] is going to be \0
  str1[i] = '\0';
  
}

int main(){

  char msg1[100] = "this is a much longer text"; 
  char msg2[100] = "hey there";

  // destructive
  strcpy(msg1,msg2);

  cout << msg1 << endl;
  for(int i=0; i<30; i++){
    cout << msg1[i];
  }
  cout << endl;
  
  return 0;
}
