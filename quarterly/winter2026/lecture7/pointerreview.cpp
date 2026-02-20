#include <iostream>
using namespace std;

int main(){

  int num = 5;

  int* pointy = &num;

  cout << pointy << endl;

  char numArray[5] = {0,1,2,3,4};

  for(int i=0; i<5; i++){
    cout << (int*)(numArray+i) << ": " << (int)*(numArray+i) << endl;
  }
  
  return 0;
}
