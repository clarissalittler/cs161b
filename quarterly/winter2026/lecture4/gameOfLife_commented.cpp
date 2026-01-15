#include <iostream>
#include <cstring>
using namespace std;

/*
  Conway's Game of Life (summary for students)
  - The world is a 20x20 grid of cells.
  - Each cell is either alive (true) or dead (false).
  - Each step computes neighbor counts (up to 8 neighbors).
  - Rules:
    * Dead cell with exactly 3 neighbors becomes alive.
    * Live cell with 2 or 3 neighbors stays alive.
    * Live cell with fewer than 2 or more than 3 neighbors dies.
  - This program displays the grid, updates one step, then waits
    for Enter so you can watch the evolution one generation at a time.
  - Neighbor layout (X is the cell being updated):
      NW  N  NE
       W  X   E
      SW  S  SE
  - We store neighbor counts in a separate array so the updates
    don't interfere with counts for nearby cells in the same step.
*/

// The board is a fixed 20x20 grid.
const int boardSize = 20;

// Return the cell value at (i, j).
// If (i, j) is out of bounds, treat it as 0 (dead).
int getBit(int i, int j, bool board[][boardSize]){
  if(i >=0 && i < boardSize && j >=0 && j < boardSize){
    return board[i][j];
  }
  else{
    return 0;
  }
}

// For each cell, count how many of its 8 neighbors are alive.
// Store the counts in cs (count store).
void countNeighbors(bool b[][boardSize], int cs[][boardSize]){
  for(int i=0; i<boardSize; i++){
    for(int j=0; j<boardSize; j++){
      int sum = 0;
      for(int k=-1; k <= 1; k++){
        for(int l=-1; l <= 1; l++){
          // Skip the cell itself (k==0 and l==0).
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

// Apply the Game of Life rules using the neighbor counts:
// - A dead cell with exactly 3 neighbors becomes alive.
// - A live cell with fewer than 2 or more than 3 neighbors dies.
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

// Set every cell to dead.
void clearBoard(bool board[][boardSize]){
  for(int i=0; i<boardSize;i++){
    for(int j=0; j<boardSize;j++){
      board[i][j] = false;
    }
  }
}

// Display the board: "o" for live, "_" for dead.
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

// Flip (toggle) a cell if the indices are in bounds.
void toggleBit(int i, int j, bool board[][boardSize]){
  if(!(i < 0 || i >= boardSize || j < 0 || j >= boardSize)){
    board[i][j] = !board[i][j];
  }
}

// Place a 2x2 "block" pattern with top-left at (i, j).
void placeSquare(int i, int j, bool board[][boardSize]){
  toggleBit(i,j,board);
  toggleBit(i+1,j+1,board);
  toggleBit(i,j+1,board);
  toggleBit(i+1,j,board);
}

// Place a "glider" pattern with a chosen anchor at (i, j).
void placeGlider(int i, int j, bool board[][boardSize]){
  toggleBit(i,j,board);
  toggleBit(i+1,j+1,board);
  toggleBit(i+2,j,board);
  toggleBit(i+2,j+1,board);
  toggleBit(i+2,j-1,board);
}

int main(){

  // The board stores alive/dead cells; neighborCounts stores 0..8 counts.
  bool board[boardSize][boardSize];
  int neighborCounts[boardSize][boardSize];

  clearBoard(board);

  // Seed the board with a glider and two blocks.
  placeGlider(10,10,board);
  
  placeSquare(2,2,board);
  placeSquare(4,4,board);

  // Main loop: show, compute, update, wait for user input.
  while(true){
    showBoard(board);
    cout << endl;
    countNeighbors(board,neighborCounts);
    updateCells(board,neighborCounts);
    // Pause until the user hits Enter to advance one generation.
    string waste;  
    getline(cin,waste);
  }
  
  return 0;
}
