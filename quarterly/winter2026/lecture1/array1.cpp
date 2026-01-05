#include <iostream>
using namespace std;

int main(){

  int nums[15];

  for(int i = 0; i < 15; i++){
    nums[i] = i*i;
  }

  cout << nums[100] << endl;
  
  return 0;
}
