#include <iostream>
#include <iomanip>
using namespace std;

void fillCells(int** c, int h, int w){
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      c[i][j] = i + h*j;
    }
  }
}

int main(){

  int** cells = new int*[10]; // make room for 10 rows
  for(int i=0; i<10; i++){
    cells[i] = new int[5]; // make the rows with five columns each
  }

  fillCells(cells,10,5);
  
  for(int i=0; i<10; i++){
    for(int j=0; j<5; j++){
      cout << setw(3) << cells[i][j] << " ";
    }
    cout << endl;
  }
  
  // to destroy
  for(int i=0; i<10; i++){
    delete[] cells[i];
  }
  delete[] cells;
  
  return 0;
}
