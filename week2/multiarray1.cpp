/*
 a matrix is a two-dimensional collection of numbers
 it has /rows/ and it has /columns/
  1  3  5
  2  6  7
 -1  5  8

 1 2 2 2 = A
 3 4 5 5

 A_0_0 = 1
 A_0_1 = 2
 A_1_3 = 5

 linearity:
 f(m*a + b) = m*f(a) + f(b)
 
 */
#include <iostream>
using namespace std;

void doubler(int** arr, int rows, int columns){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      arr[i][j] = 2*arr[i][j];
      // arr[i][j] ~= *( *(arr + i) + j)
    }
  }
}

int main(){
  int arr[50][50];

  for(int i = 0; i < 50; i++){
    for(int j = 0; j < 50; j++){
      // how many times does this body run?
      arr[i][j] = i*1000 + j; 
    }
  }

  doubler(arr,50,50);
  
  for(int j = 0; j < 50; j++){
    cout << "The " << j << "th element of row 1 is: " << arr[1][j] << endl;
  }
  
  return 0;
}
