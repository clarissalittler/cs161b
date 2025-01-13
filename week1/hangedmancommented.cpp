/*
Library Functions Used:
cout << (from iostream)
    - Signature: ostream& operator<<(const T& value)
    - Outputs values to console

cin >> (from iostream)
    - Signature: istream& operator>>(T& value)
    - Reads input from console into a variable

strlen() (from cstring) [Note: not actually used in final code]
    - Signature: size_t strlen(const char* str)
    - Returns length of null-terminated string
*/

#include <iostream>
#include <cstring>
using namespace std;

// Function to calculate length of a null-terminated string
// Returns number of chars before the null terminator
int ourStrlen(char s[]){
  int i = 0;
  // Increment counter until null terminator is found
  while(s[i] != '\0'){
    i++;
  }
  return i;
}

// Function to process a single letter guess
// g: the guessed letter
// s: the secret word
// p: the partially revealed word with underscores
// Returns true if guess is found in secret word
bool checkGuess(char g, char s[], char p[]){
  int i = 0;
  bool found = false;
  // Loop through secret word
  while(s[i] != '\0'){
    // If letter matches guess, reveal it in partial word
    if(s[i] == g){
      found = true;
      p[i] = s[i];
    }
    i++;
  }
  return found;
}

// Function to check if two strings are identical
// Returns true if strings match exactly
bool areEqualStrs(char s1[], char s2[]){
  bool same = true;
  int i = 0;
  // Compare each character until null terminator
  while(s1[i] != '\0'){
    if(s1[i] != s2[i]){
      same = false;
    }
    i++;
  }
  return same;
}

int main(){
  // Initialize secret word
  char secret[50] = "chicken";

  // Create array for partially revealed word
  char partial[50];

  // Fill partial word with underscores
  for(int i=0; i < ourStrlen(secret); i++){
    partial[i] = '_';
  }
  // Add null terminator at end
  partial[ourStrlen(secret)] = '\0';
  
  // Variable to store player's guess
  char guess;
  
  // Number of wrong guesses allowed
  int guessesLeft = 5;

  // Main game loop
  do {
    // Display current game state
    cout << "The phrase: " << partial << endl;
    cout << "Guesses left: " << guessesLeft << endl;
    
    // Get player's guess
    cout << "Enter your guess: ";
    cin >> guess;

    // Process the guess
    if(!checkGuess(guess,secret,partial)){
      // If guess is wrong, decrement guesses left
      cout << "Whoops!" << endl;
      guessesLeft--;
    }
    else if(areEqualStrs(secret,partial)){
      // If word is complete, player wins
      cout << "Yay you win!" << endl;
      return 0;
    }
    
  }while(guessesLeft > 0);

  // If we get here, player has lost
  cout << "Dang, you lost!" << endl;
  cout << "The real secret was: " << secret << endl;
  
  return 0;
}
