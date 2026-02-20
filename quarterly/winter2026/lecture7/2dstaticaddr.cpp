#include <iostream>
#include <iomanip>
using namespace std;

// void fillCells(int c[][]

int main(){

  // rows x columns
  int cells[10][5];

  for(int i=0; i<10; i++){
    for(int j=0; j<5; j++){
      cout << &(cells[i][j]) << " ";
    }
    cout << endl;
  }
  
  return 0;
}
