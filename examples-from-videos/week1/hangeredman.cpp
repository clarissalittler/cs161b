#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

// this should implement a small game of
// hanged man where we take a secret word
// (fixed in the first draft)
// and let the user guess a number of times
// if the number of incorrect guesses counts
// down to zero, the player loses
// if they completely fill out the word before
// they run out of guesses, they win
// and this program should only use null terminated strings *not* the C++ string type
// at first let everything be lower case

bool checkGuess(char g, char s[], char p[]){
  // this function will loop through the
  // string s and if a character of s
  // matches g, set the variable to be returned
  // to true, and then replace the corresponding blank in p
  // with the letter
  int i = 0;
  bool found = false;
  while(s[i] != '\0'){
    if(s[i] == g){
      found = true;
      p[i] = s[i];
    }
    i++;
  }
  return found;
}

int main(){

  // seed the randomness
  srand(time(0));
  
  char words[5][50] = {"chicken","pants","dapper","houndstooth","kettle"};

  // now we want to build our secret out of
  // two elements of the list of words

  int word1 = rand() % 5;
  int word2 = rand() % 5;
  
  char secret[50];
  strcpy(secret,words[word1]);
  //strcat copies from the second argument
  //*into* the first argument, changing it
  strcat(secret," ");
  strcat(secret,words[word2]);

  char partial[50]; // should be _______

  // to prep the partial word
  // we need to first find the length of the
  // secret

  for(int i=0; i < strlen(secret); i++){
    // put an if to leave the ' ' if it's a space
    if(secret[i] == ' '){
      partial[i] = ' ';
    }
    else{
      partial[i] = '_';
    }
  }
  partial[strlen(secret)] = '\0';
  
  char guess;
  
  int guessesLeft = 5;

  // now we need a do-while loop to do the guessin'
  do {
    cout << "The phrase: " << partial << endl;
    cout << "Guesses left: " << guessesLeft << endl;
    
    // prompt for a guess
    cout << "Enter your guess: ";
    cin >> guess;
    // checkGuess will return a bool
    // true if the letter was found
    // false if it wasn't
    if(!checkGuess(guess,secret,partial)){
      cout << "Whoops!" << endl;
      guessesLeft--;
    } // strcmp(s1,s2) returns 0 if they're equal
    else if(strcmp(secret,partial) == 0){
      cout << "Yay you win!" << endl;
      return 0;
    }
    
  }while(guessesLeft > 0);

  cout << "Dang, you lost!" << endl;
  cout << "The real secret was: " << secret << endl;
  
  return 0;
}
