#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

//strlen : char[] -> int
//strcat : char[] -> char[] -> void (attaches the second argument to the first)
//strcpy : char[] -> char[] -> void (copies the second string into the first string)
//strcmp : char[] -> char[] -> int (0 if they're equal, -1 if the first string is lexographically before the second string, +1 if the first string is lexographically after the second string

/* Hanged man implementation

   Start with a number of allowed wrong guesses (5)
   You can guess a letter and if you your letter appears in the secret word, that letter gets revealed in all the spots it appears

   Once all spots are filled, you win

   If you run out of guesses, you lose
   
 */

int main(){

  srand(time(0));

  // 2d arrays in C/C++
  // you have to declare the rows before the number of columns
  //
  /*

    4 columns
    3 rows
    
    | 1 2 3 4|
    | 3 4 5 6|
    | 6 7 8 9|

     NOT
    | 1 2 |
    | 4 5 6 |
    | 7 8 9 10 11 |

    5 rows (the number of strings)
    20 columns (the maximum length of a string)
  */
  char possibleSecrets[5][20] = {"chicken",
				 "houndstooth",
				 "conformal",
				 "bovidae",
				 "mechanical"};
  
  // fixed at first, make it random later
  char secret[20];
  // we can't set one array equal to another,
  // we can only COPY the contents from one
  // array to another
  strcpy(secret,possibleSecrets[rand()%5]);
  
  // rand is the random number generator that pulls
  // across the entire space of integers
  // so we use the % operator to make it ranger over something smaller
  // 
  cout << strlen(secret) << endl;
  int secretLength = strlen(secret);
  int revealedLength = 1+secretLength;

  int guesses = 5;
  bool solved = false;
  
  char revealed[revealedLength];
  
  for(int i=0;i<revealedLength-1;i++){
    revealed[i] = '_';
  }
  revealed[revealedLength-1] = '\0';

  do {
    cout << "So far: " << revealed << endl;
    cout << "You have " << guesses << " left" << endl;
    cout << "Guess a letter?: " << endl;
    char guess;
    cin >> guess; // actually read the guess
    bool correct = false;
    for(int i=0; i<strlen(secret); i++){
      if(guess == secret[i] && guess != revealed[i]){
	revealed[i] = secret[i];
	correct = true;
      }
    }

    if(!correct){
      guesses = guesses-1;
    }

    if(strcmp(revealed,secret) == 0){
      solved = true;
    }
    
  }while(guesses > 0 && !solved);
  
  // let's check if it was solved
  if(solved){
    cout << "You win!" << endl;
  }
  else {
    cout << "Too bad the secret word was actually: " << secret << endl;
  }
  
  return 0;
}
