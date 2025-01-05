#include <iostream>
using namespace std;

int main(){
  int num[5];

  for(int i = 0; i < 5; i++){
    num[i] = i*i;
  }

  for(int i = 0; i < 5; i++){
    cout << "The " << i << "th number is: " << num[i] << endl;
  }

  cout << "And num[6] is " << num[6] << endl;

  cout << "num itself is " << num << endl;
  
  return 0;
}
