#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int readInt(string prompt){
  int tempInt;
  cout << prompt;
  cin >> tempInt;

  while(cin.fail()){
    cin.clear(); // fix the error bit
    cin.ignore(256,'\n');
    cout << prompt;
    cin >> tempInt;
  }
  return tempInt;
}

/*
  This is a program that should run a little
  guessing game where you have five guesses
  to correctly guess a number between 1 and 100

  if you guess correctly, the program ends

  if you don't, you get a "too high" or "too low"
  message depending on whether you are too high
  or too low
 */
int main(){

  srand(time(0));
  int secret = rand() % 100 + 1;
  int guesses = 5;

  int guess;

  do {
    guess = readInt("Guess the number: ");

    if(guess > secret){
      cout << "Too high!" << endl;
    }
    else if(guess < secret){
      cout << "Too low!" << endl;
    }
    else {
      cout << "You win!" << endl;
      return 0;
    }
    guesses = guesses -1;
  } while(guesses > 0);

  cout << "You lose!" << endl;
  
  return 0;
}
