#include <iostream>
using namespace std;

int main(){

  int nums[10];

  for(int i=0; i<10; i++){
    nums[i] = i*i;
  }

  cout << nums << endl;
  cout << *nums << endl;

  for(int i=0; i<10; i++){
    cout << *(nums+i) << endl;
    // nums[i] ==> *(nums + i)
  }
  
  return 0;
}
