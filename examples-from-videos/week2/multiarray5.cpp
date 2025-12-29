#include <iostream>
using namespace std;

void doubler(int** arr,int row, int col){

  for(int i = 0; i < row; i++){
    for(int j =0; j < col; j++){
      arr[i][j] = 2*arr[i][j];
    }
  }
}

int main(){

  int** arr = new int*[40];
  for(int i=0; i < 40; i++){
    arr[i] = new int[50];
  }
  
  for(int i=0; i < 40; i++){
    for(int j=0; j < 50; j++){
      arr[i][j] = 1000*i + j;
    }
  }

  doubler(arr,40,50);
  
  for(int i=0; i < 40; i++){
    for(int j=0; j < 50; j++){
      cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;
    }
    cout << endl;
  }
  
  for(int i=0; i < 40; i++){
   delete[] arr[i];
  }
  delete[] arr;
  
  return 0;
}
