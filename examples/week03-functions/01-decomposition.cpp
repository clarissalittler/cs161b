/*
 * 01-decomposition.cpp
 * Breaking a complex task into manageable functions.
 *
 * We'll build a simple number guessing game, but instead of putting
 * everything in main(), we'll create focused helper functions.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function declarations (prototypes)
// These tell the compiler what functions exist before we define them
int getRandomNumber(int min, int max);
int getGuess(int attemptNumber);
void giveHint(int guess, int secret);
void celebrateWin(int attempts);
bool playAgain();

int main() {
    // Seed the random number generator (do this once at program start)
    srand(time(0));

    cout << "=== Number Guessing Game ===" << endl;
    cout << endl;

    do {
        // Set up the game
        const int MIN = 1;
        const int MAX = 100;
        int secret = getRandomNumber(MIN, MAX);
        int attempts = 0;
        int guess;

        cout << "I'm thinking of a number between " << MIN << " and " << MAX << "." << endl;

        // Main game loop
        do {
            attempts++;
            guess = getGuess(attempts);

            if (guess != secret) {
                giveHint(guess, secret);
            }
        } while (guess != secret);

        celebrateWin(attempts);

    } while (playAgain());

    cout << "Thanks for playing!" << endl;
    return 0;
}

/*
 * Generate a random number between min and max (inclusive)
 */
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

/*
 * Prompt the user for a guess and return it
 */
int getGuess(int attemptNumber) {
    int guess;
    cout << "Attempt #" << attemptNumber << " - Your guess: ";
    cin >> guess;
    return guess;
}

/*
 * Tell the player if their guess was too high or too low
 */
void giveHint(int guess, int secret) {
    if (guess < secret) {
        cout << "Too low!" << endl;
    } else {
        cout << "Too high!" << endl;
    }
}

/*
 * Congratulate the player on winning
 */
void celebrateWin(int attempts) {
    cout << endl;
    cout << "*** Correct! ***" << endl;

    if (attempts == 1) {
        cout << "Incredible! You got it on the first try!" << endl;
    } else if (attempts <= 5) {
        cout << "Great job! Only " << attempts << " attempts." << endl;
    } else if (attempts <= 10) {
        cout << "Not bad! " << attempts << " attempts." << endl;
    } else {
        cout << "You got it in " << attempts << " attempts." << endl;
    }
    cout << endl;
}

/*
 * Ask if the player wants to play again
 * Returns true for yes, false for no
 */
bool playAgain() {
    char response;
    cout << "Play again? (y/n): ";
    cin >> response;
    cout << endl;
    return (response == 'y' || response == 'Y');
}

/*
 * Notice how main() reads almost like English:
 *
 *   - Get a random secret number
 *   - Get a guess
 *   - Give a hint if wrong
 *   - Celebrate when they win
 *   - Ask to play again
 *
 * Each function has ONE job, is easy to understand, and could be
 * tested independently. If we wanted to change how hints work,
 * we only touch giveHint(). If we wanted different celebration
 * messages, we only touch celebrateWin().
 *
 * This is the power of decomposition.
 */
