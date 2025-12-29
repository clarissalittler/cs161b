#include <iostream>
#include <cstring>
using namespace std;

// strcpy

void ourStrcpy(char dest[],char src[]){
  int i = 0;
  while(src[i] != '\0'){
    dest[i] = src[i];
    i++;
  }
  dest[i] = src[i]; // copy the null
}

int main(){

  char msg1[50];
  char oldMsg[50] = "beepity boopity boppity ba-blam";
  
  cout << "Say something: ";
  cin >> msg1;
  cout << msg1 << endl;

  ourStrcpy(oldMsg,msg1);

  cout << "Say something else: ";
  cin >> msg1;
  cout << msg1 << endl;
  cout << oldMsg << endl;

  // is the old data still in there?
  for(int i = 0; i < 50; i++){
    cout << oldMsg[i] << '_';
  }
  cout << endl;
  
  return 0;
}
