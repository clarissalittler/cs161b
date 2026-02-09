#include <iostream>
using namespace std;

template <typename T>
void printArray(T a[], int s){
  cout << "[ ";
  for(int i=0; i<s; i++){
    cout << a[i] << " ";
  }
  cout << "]" << endl;
}

void printIntArray(int a[], int s){
  cout << "[ ";
  for(int i=0; i<s; i++){
    cout << a[i] << " ";
  }
  cout << "]" << endl;
}

void printStringArray(string a[], int s){
  cout << "[ ";
  for(int i=0; i<s; i++){
    cout << a[i] << " ";
  }
  cout << "]" << endl;
}



int main(){
  int arr1[10] = {0,1,2,3,4,5,6,7,8,9};
  string arr2[5] = {"beep","boop","chicken","cow","dog"};

  printArray(arr1,10);
  printArray(arr2,5);
  
  return 0;
}
