#include <iostream>
#include <cstring>
using namespace std;

// Fixed map dimensions for the room layout.
const int roomWidth=5;
const int roomHeight=5;

// Track the player's position and total steps taken.
struct Player {
  int xPos;
  int yPos;
  int numSteps;
};

// Render the room and draw the player on top of the map.
// The +1 is for the null terminator in each row string.
void printGame(char r[][roomWidth+1],
               Player p){
  // for each row
  for(int i=0; i<roomHeight; i++){
    // for each column in the row
    for(int j=0; j<roomWidth; j++){
      if(j == p.xPos && i == p.yPos){
        cout << "P";
      }
      else{
        cout << r[i][j];
      }
    }
    cout << endl;
  }

}

// Move the player one tile based on a direction character.
// This intentionally ignores bounds/walls; the lecture exercise is to fix it.
void movePlayer(char r[][roomWidth+1],
                Player &p,
                char d){
  // 'n' is north (up)
  // 's' is south (down)
  // 'w' is west (left)
  // 'e' is east (right)

  // here's a borked version that
  // lets the player move anywhere
  // your job is to fix it

  switch(d){
  case 'n':
    p.yPos = p.yPos-1;
    p.numSteps++;
    break;
  case 's':
    p.yPos = p.yPos+1;
    p.numSteps++;
    break;
  case 'e':
    p.xPos = p.xPos+1;
    p.numSteps++;
    break;
  case 'w':
    p.xPos = p.xPos-1;
    p.numSteps++;
    break;
  default:
    break;
  }

}

int main(){

  // Start the player at (1,1) with zero steps.
  Player p = {1, 1, 0};

  // A 2D array of chars, with each row stored as a C-string.
  char room[roomHeight][roomWidth+1] =
    {"#####",
     "#___#",
     "#_#_#",
     "#___#",
     "#####"};

  // let's display a room for a text adventure
  // game
  // we then want # mark to be a wall
  // we want _ to be empty space
  // we want P to be the player position

  // NOTE: input should be initialized before the loop.
  char input;
  while(input != 'q'){

    printGame(room,p);

    cout << "Which direction? n/e/w/s: ";
    cin >> input;
    movePlayer(room,p,input);
  }

  return 0;
}
