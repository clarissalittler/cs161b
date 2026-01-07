#include <iostream>
using namespace std;

int main(){

  char msg[100] = "This is some text";

  for(int i=0; i<20; i++){
    cout << (int)msg[i] << endl;
  }
  cout << endl;
  
  return 0;
}
