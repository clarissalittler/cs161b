/*

  Matrix/matrices

  1 2 3
  4 5 6 (a matrix)

  1 0
  0 1 (a matrix)

  1 2 3 4 5
  6 7 8 9
  10 11 (NOT a matrix)

  1 2 3
  4 5 6
 x
  10
  11
  12

  1 * 10 + 2 * 11 + 3 * 12 
  4 * 10 + 5 * 11 + 6 * 12
  = 68
    167

  linear:
  f(m*x + b) = m*f(x) + f(b)
 */

#include <iostream>
using namespace std;

int main(){
  int arr[40][50]; // 40 *rows*, 50 *columns*

  for(int i=0; i < 40; i++){
    for(int j=0; j < 50; j++){
      arr[i][j] = 1000*i + j;
    }
  }

  for(int j=0; j < 40; j++){
    cout << "The jth element of the 5th row is: " << arr[5][j] << endl;
  }
  
  return 0;
}













