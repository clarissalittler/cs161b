#include <iostream>
#include <cstring>
using namespace std;


// and
// | p | q | p & q |
// | T | T | T     |
// | T | F | F     |
// | F | T | F     |
// | F | F | F     |
// or
// | p | q | p | q |
// | T | T | T     |
// | T | F | T     |
// | F | T | T     |
// | F | F | F     |
// xor
// | p | q | p ^ q |
// | 1 | 1 | 0     |
// | 1 | 0 | 1     |
// | 0 | 1 | 1     |
// | 0 | 0 | 0     |


// the idea of the 1-time pad is that you
// take a message and a key
// the key MUST BE THE SAME LENGTH AS THE MESSAGE
// and you xor the bytes of the key and the message
// together one by one

int main(){
  
  char msg[100];
  cout << "Enter the message to read: " << endl;
  cin.getline(msg,100);

  char encrypted[100];
  
  cout << "Enter the key (must be " << strlen(msg) << ") characters in length: " << endl;
  char key[100];
  cin.getline(key,100);

  cout << "Encrypted message: " << endl;
  int i=0;
  while(msg[i] != '\0'){
    encrypted[i] = key[i] ^ msg[i];
    i++;
  }
  encrypted[i] = '\0';

  i=0;
  while(encrypted[i] != '\0'){
    cout << (int)encrypted[i] << " ";
    i++;
  }
  cout << endl;

  i = 0;
  while(encrypted[i] != '\0'){
    encrypted[i] = encrypted[i] ^ key[i];
    i++;
  }
  
  cout << "Unencrypted: " << encrypted << endl;
  
  
  return 0;
}
