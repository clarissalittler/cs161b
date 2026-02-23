#include <iostream>
using namespace std;

const int rows = 10;
const int cols = 8;

void printMatrix(int** m, int height, int width){
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

void rowflip(int** m, int height, int width){
  for(int i=0; i<height; i++){
    // flip each row
    // we first make a new array of size width
    // then we go ahead and copy backwards from old to new
    // then we put the new one in the slot for the row
    // then we *delete* the old one
    int* newRow = new int[width];
    for(int j=0; j<width; j++){
      newRow[j] = m[i][width-j-1];
    }
    int* temp = m[i]; 
    m[i] = newRow;
    delete[] temp;
  }
}

void flipVertical(int** m, int height){
  // to explain:
  // flipping top with bottom
  // means we have to make a temp row variable
  // that holds the old row and then we simply
  // copy over the pointer positions from old to new and visa versa
  for(int i=0; i<height/2; i++){
    int* temp = m[i];
    m[i] = m[height - i -1];
    m[height - i - 1] = temp;
  }
}

int main(){

  // we could do
  // int matrix[rows][cols];
  // ....
  int** matrix = new int*[rows]; // set aside space
  //for rows
  for(int i=0; i < rows; i++){
    // initialized rows
    matrix[i] = new int[cols];
  }

  // put some data in here:
  for(int i=0; i< rows; i++){
    for(int j=0; j<cols; j++){
      matrix[i][j] = i + 10*j;
    }
  }
  
  printMatrix(matrix,rows,cols);
  cout << endl;
  rowflip(matrix,rows,cols);
  printMatrix(matrix,rows,cols);
  cout << endl;
  flipVertical(matrix,rows);
  printMatrix(matrix,rows,cols);
  
  for(int i=0; i< rows; i++){
    delete[] matrix[i];
  }

  delete[] matrix;
  
  return 0;
}
