#include <iostream>
using namespace std;

// double all the elements of the array
/*
void doubler(int num[], int l){
  for(int i = 0; i < l; i++){
    num[i] = 2*num[i];
  }  
}
*/
void doubler(int* num, int l){
  for(int i = 0; i < l; i++){
    *(num+i) = 2*(*(num + i));
  }  
}



int main(){
  int thing[10];

  for(int i = 0; i< 10; i++){
    thing[i] = i;
  }
  
  doubler(thing, 10);

  for(int i = 0; i < 10; i++){
    cout << "thing[" << i << "]: " << thing[i] << endl; 
  }
  
  return 0;
}
