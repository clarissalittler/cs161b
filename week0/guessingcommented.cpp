// Include necessary header files for input/output, time, and random number generation
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Function to safely read an integer input, handling potential input errors
int readInt(string prompt){
  // Declare a temporary integer to store the input
  int tempInt;
  // Display the prompt to the user
  cout << prompt;
  // Attempt to read an integer from user input
  cin >> tempInt;

  // If input fails (e.g., user enters a non-integer)
  while(cin.fail()){
    // Clear the error flag on the input stream
    cin.clear(); 
    // Ignore up to 256 characters until a newline is found
    // This clears any invalid input from the input buffer
    cin.ignore(256,'\n');
    // Reprint the prompt
    cout << prompt;
    // Try to read input again
    cin >> tempInt;
  }
  // Return the successfully read integer
  return tempInt;
}

int main(){
  // Seed the random number generator with the current time
  // This ensures a different random number each time the program runs
  srand(time(0));

  // Generate a random secret number between 1 and 100
  // rand() % 100 generates a number 0-99, then add 1 to make it 1-100
  int secret = rand() % 100 + 1;

  // Set the maximum number of guesses the player has
  int guesses = 5;

  // Declare a variable to store the player's guess
  int guess;

  // Start a do-while loop that continues until guesses run out
  do {
    // Use the readInt function to safely get the player's guess
    guess = readInt("Guess the number: ");

    // If the guess is higher than the secret number
    if(guess > secret){
      cout << "Too high!" << endl;
    }
    // If the guess is lower than the secret number
    else if(guess < secret){
      cout << "Too low!" << endl;
    }
    // If the guess matches the secret number exactly
    else {
      cout << "You win!" << endl;
      // Immediately exit the program if the guess is correct
      return 0;
    }
    // Decrease the number of remaining guesses
    guesses = guesses -1;
  } 
  // Continue the loop as long as there are guesses left
  while(guesses > 0);

  // If the player runs out of guesses without finding the secret number
  cout << "You lose!" << endl;
  
  // Exit the program
  return 0;
}
