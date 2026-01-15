#include <iostream>
#include <cstring>
using namespace std;

const int boardSize = 20;

int getBit(int i, int j, bool board[][boardSize]){
  if(i >=0 && i < boardSize && j >=0 && j < boardSize){
    return board[i][j];
  }
  else{
    return 0;
  }
}

void countNeighbors(bool b[][boardSize], int cs[][boardSize]){
  for(int i=0; i<boardSize; i++){
    for(int j=0; j<boardSize; j++){
      int sum = 0;
      for(int k=-1; k <= 1; k++){
	for(int l=-1; l <= 1; l++){
	  if(k != 0 || l != 0){
	    sum += getBit(i+k,j+l,b);
	  }
	}
      }
      cs[i][j] = sum;
      //cout << cs[i][j] << " ";
    }
    //cout << endl;
  }
}

void updateCells(bool b[][boardSize], int c[][boardSize]){
  for(int i=0; i<boardSize; i++){
    for(int j=0; j<boardSize; j++){
      if(!b[i][j]){
	if(c[i][j] == 3){
	  b[i][j] = true;
	}
      }
      else{
	if(c[i][j] < 2 || c[i][j] > 3){
	  b[i][j] = false;
	}
      }
    }
  }
}

void clearBoard(bool board[][boardSize]){
  for(int i=0; i<boardSize;i++){
    for(int j=0; j<boardSize;j++){
      board[i][j] = false;
    }
  }
}

void showBoard(bool board[][boardSize]){
  for(int i=0; i<boardSize; i++){
    for(int j=0; j<boardSize; j++){
      if(board[i][j]){
	cout << "o ";
      }
      else{
	cout << "_ ";
      }
    }
    cout << endl;
  }
}

void toggleBit(int i, int j, bool board[][boardSize]){
  if(!(i < 0 || i >= boardSize || j < 0 || j >= boardSize)){
    board[i][j] = !board[i][j];
  }
}

void placeSquare(int i, int j, bool board[][boardSize]){
  toggleBit(i,j,board);
  toggleBit(i+1,j+1,board);
  toggleBit(i,j+1,board);
  toggleBit(i+1,j,board);
}

void placeGlider(int i, int j, bool board[][boardSize]){
  toggleBit(i,j,board);
  toggleBit(i+1,j+1,board);
  toggleBit(i+2,j,board);
  toggleBit(i+2,j+1,board);
  toggleBit(i+2,j-1,board);
}

int main(){

  bool board[boardSize][boardSize];
  int neighborCounts[boardSize][boardSize];

  clearBoard(board);


  placeGlider(10,10,board);
  
  placeSquare(2,2,board);
  placeSquare(4,4,board);

  while(true){
    showBoard(board);
    cout << endl;
    countNeighbors(board,neighborCounts);
    updateCells(board,neighborCounts);
    string waste;  
    getline(cin,waste);
  }
  
  return 0;
}
