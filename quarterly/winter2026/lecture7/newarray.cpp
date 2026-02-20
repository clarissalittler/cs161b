#include <iostream>
using namespace std;

void doubleArray(int arr[], int s){
  for(int i=0;i<s;i++){
    arr[i] = 2*arr[i];
  }
}  

int main(){

  int* numArray = new int[10]; 

  for(int i=0; i<10; i++){
    numArray[i] = i*i;
  }

  doubleArray(numArray,10);
  
  for(int i=0; i<10; i++){
    cout << numArray[i] << endl;
  }

  delete[] numArray;
  
  return 0;
}
