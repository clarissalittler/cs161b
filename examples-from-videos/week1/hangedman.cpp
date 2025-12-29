#include <iostream>
#include <cstring>
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

int ourStrlen(char s[]){
  int i = 0;
  while(s[i] != '\0'){
    i++;
  }

  /*
     0   1    2   3   4   5
    ['h','e','l','l','o','\0',...]
    at the end of this loop
    then i = 5
    
   */
  
  return i;
}

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

bool areEqualStrs(char s1[], char s2[]){
  bool same = true;

  int i = 0;
  while(s1[i] != '\0'){
    if(s1[i] != s2[i]){
      same = false;
    }
    i++;
  }
  
  return same;
}

int main(){

  char secret[50] = "chicken";

  char partial[50]; // should be _______

  // to prep the partial word
  // we need to first find the length of the
  // secret

  for(int i=0; i < ourStrlen(secret); i++){
    partial[i] = '_';
  }
  partial[ourStrlen(secret)] = '\0';
  
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
    }
    else if(areEqualStrs(secret,partial)){
      cout << "Yay you win!" << endl;
      return 0;
    }
    
  }while(guessesLeft > 0);

  cout << "Dang, you lost!" << endl;
  cout << "The real secret was: " << secret << endl;
  
  return 0;
}
