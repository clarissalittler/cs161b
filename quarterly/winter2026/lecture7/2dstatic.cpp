#include <iostream>
#include <iomanip>
using namespace std;

const int cols = 5;

void fillCells(int c[][cols], int h){
  for(int i=0; i<h; i++){
    for(int j=0;  j<5; j++){
      c[i][j] = i + h*j;
    }
  }
}

int main(){

  // rows x columns
  int cells[10][cols];

  fillCells(cells,10);

  for(int i=0; i<10; i++){
    for(int j=0; j<5; j++){
      cout << setw(3) << cells[i][j] << " ";
    }
    cout << endl;
  }
  
  return 0;
}
