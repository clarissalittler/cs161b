#include <iostream>
using namespace std;

struct Goofus {
  string s;
  int a[10];
};

template <typename T>
T sum(T arr[], int l){
  T acc = 0;
  for(int i =0; i < l; i++){
    acc += arr[i];
  }

  return acc;
}

int main(){

  int arr1[5] = {0,1,2,3,4};
  float arr2[5] = {10.0,11.0,12.0,13.0,14.0};

  Goofus arr3[5];
  
  cout << "The sum of arr1 is: " << sum(arr1,5) << endl;
  cout << "The sum of arr2 is: " << sum(arr2,5) << endl;

  // cout << "The sum of arr3 is: " << sum(arr3,5) << endl;
  
  return 0;
}
