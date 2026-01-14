#include <iostream>
#include <cstring>
using namespace std;

const int roomWidth=5;
const int roomHeight=5;

struct Player {
  int xPos;
  int yPos;
  int numSteps;
};

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

  Player p = {1, 1, 0};
  
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

  char input;
  while(input != 'q'){
    
    printGame(room,p);

    cout << "Which direction? n/e/w/s: ";
    cin >> input;
    movePlayer(room,p,input);
  }
    
  return 0;
}
