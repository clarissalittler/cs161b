#include <iostream>
using namespace std;

const int maxSize = 20;

void printArray(int arr[], int s){
  for(int i=0; i<s; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

// if there's empty space, we put a 0 there

// [1,2,3,4] -> [2,3,4] (size goes down)
void shiftLeft(int arr[], int &s){
  for(int i=0; i<s-1; i++){
    arr[i] = arr[i+1];
  }
  s--;
}

// [1,2,3,4] -> [0,1,2,3,4] (size goes up)
void shiftRight(int arr[], int &s){
  // if we're shifting right we have to start
  // copying from the right-end
  for(int i=s-1; i>=0; i--){
    arr[i+1] = arr[i];
  }
  s++;
  arr[0] = 0;
}

void shiftRightWrong(int arr[], int &s){
  // let's copy arr[0] -> arr[1], arr[1] -> arr[2]
  for(int i=0; i<s; i++){
    arr[i+1] = arr[i];
  }
  arr[0] = 0;
  s++;
}

int main(){
  
  int arr[20];
  int size = 0;
  for(int i=0; i<10; i++){
    arr[i] = (i+1)*(i+1);
    size++;
  }

  printArray(arr,size);
  shiftRight(arr,size);
  printArray(arr,size);
  shiftLeft(arr,size);
  printArray(arr,size);
  
  return 0;
}
