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
  // concatenate str2 onto the end of str1
  // this means FIRST we need to find the end
  // of str1
  // BUT the end of str1 is the index of the first null
  // character in str1
  // BUT that's just the index corresponding to the length returned by strlen
  int endOfStr1 = strlen(str1);
  // str1[endOfStr1] = '\0'
  for(int i=0; i <= strlen(str2); i++){ // easiest way to add a \0 is to change the < to a <=
    str1[i+endOfStr1] = str2[i];
  }
}

int main(){

  char msg2[100] = ", my dude"; 
  char msg1[100] = "hey there";

  // destructive
  strcat(msg1,msg2);

  cout << msg1 << endl;
  cout << msg2 << endl;

  string str1 = "hey there";
  string str2 = ", my dude";

  str1 + str2;
  // non-destructive
  cout << str1 << endl;
  
  return 0;
}
