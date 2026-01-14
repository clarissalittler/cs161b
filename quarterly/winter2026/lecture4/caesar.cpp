#include <iostream>
#include <cstring>
using namespace std;

void caesar(char arr[],int shift){
  int i=0;
  while(arr[i] != '\0'){
    // lower case range is
    // 97 -> 122
    if(arr[i] >= 97 && arr[i] <= 122){
      unsigned char temp = arr[i] + shift;
      cout << "Char: " << arr[i] << endl;
      cout << "Temp: " << (int)temp << endl;
      if(temp > 122){
	// 112 + 23 = 135, 135 - 26 = 109
	temp = temp - 26;
	cout << "Fixed temp: " << temp << endl;
	// 123 - 26 = 97 which is a
      }
      else if(temp < 97){
	temp = temp + 26;
      }
      arr[i] = temp;
    }
    i++;
  }
}

char ourlower(char c){
  if(c >= 65 && c <= 90){
    return (c + 32);
  }
  else{
    return c;
  }
}

void alllower(char arr[]){
  for(int i=0; arr[i] != '\0'; i++){
    arr[i] = ourlower(arr[i]);
  }
}

int main(){

  char msg[100];

  cout << "Enter a message: ";
  cin.getline(msg,100);

  int shifty = 0;
  cout << "Enter the shift: ";
  cin >> shifty;

  cout << "Converting message to lowercase" << endl;

  alllower(msg);
  
  caesar(msg,shifty);

  cout << "Encrypted message: " << msg << endl;
  caesar(msg,-shifty);
  
  cout << "Unencrypted message again: " << msg << endl;
  
  return 0;
}
