#include <iostream>
#include <cstring>
using namespace std;

// Apply a Caesar shift to lowercase letters in arr, in-place.
// Non-lowercase characters are left unchanged.
void caesar(char arr[],int shift){
  int i=0;
  while(arr[i] != '\0'){
    // lower case range is
    // 97 -> 122
    if(arr[i] >= 97 && arr[i] <= 122){
      // Use unsigned char so wrap-around math is easier to reason about.
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

// Convert a single character to lowercase (ASCII-only).
char ourlower(char c){
  if(c >= 65 && c <= 90){
    return (c + 32);
  }
  else{
    return c;
  }
}

// Convert an entire C-string to lowercase in-place.
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

  // Normalize to lowercase so the cipher only needs one range.
  alllower(msg);

  // Encrypt by shifting forward.
  caesar(msg,shifty);

  cout << "Encrypted message: " << msg << endl;
  // Decrypt by shifting back by the same amount.
  caesar(msg,-shifty);

  cout << "Unencrypted message again: " << msg << endl;

  return 0;
}
