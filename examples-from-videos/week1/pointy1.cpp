#include <iostream>
using namespace std;

int main(){
  int thing = 10;
  int* thingAddr = &thing;

  int arr[10];

  for(int i = 0; i < 10; i++){
    arr[i] = i*i+100;
  }
  
  for(int i = 0; i < 10; i++){
    // show that arr[i] is just pointer arithmetic
    cout << "arr[i] is: " << arr[i] << endl;
    cout << "*(arr+i) is: " << *(arr+i) << endl;
  }
  
  return 0;
}
