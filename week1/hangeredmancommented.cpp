#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
LIBRARY FUNCTION REFERENCE:
strlen(const char* str) -> size_t
    Returns length of null-terminated string

strcpy(char* dest, const char* src) -> char*
    Copies string from src to dest, including null terminator

strcat(char* dest, const char* src) -> char*
    Appends src string to end of dest string

strcmp(const char* str1, const char* str2) -> int
    Compares two strings, returns 0 if equal

rand() -> int
    Returns pseudo-random integer

srand(unsigned int seed) -> void
    Seeds the random number generator

time(time_t* timer) -> time_t
    Returns current calendar time
*/

// Function to check if a guessed letter appears in the secret phrase
bool checkGuess(char g, char s[], char p[]){
    // g: the guessed letter
    // s: the secret phrase
    // p: the partial phrase showing discovered letters
    int i = 0;
    bool found = false;
    while(s[i] != '\0'){  // Loop until end of string
        if(s[i] == g){    // If letter matches
            found = true;  // Mark that we found a match
            p[i] = s[i];  // Reveal the letter in partial string
        }
        i++;
    }
    return found;
}

int main(){
    // Initialize random seed using current time
    srand(time(0));
  
    // Array of possible words for the game
    char words[5][50] = {"chicken","pants","dapper","houndstooth","kettle"};

    // Randomly select two indices for words
    int word1 = rand() % 5;
    int word2 = rand() % 5;
  
    // Buffer to hold the complete secret phrase
    char secret[50];
    strcpy(secret,words[word1]);     // Copy first word
    strcat(secret," ");              // Add space between words
    strcat(secret,words[word2]);     // Add second word

    // Buffer to hold partially revealed phrase
    char partial[50];

    // Initialize partial string with underscores and spaces
    for(int i=0; i < strlen(secret); i++){
        if(secret[i] == ' '){
            partial[i] = ' ';         // Keep spaces visible
        }
        else{
            partial[i] = '_';         // Hide letters with underscores
        }
    }
    // Add null terminator to partial string
    partial[strlen(secret)] = '\0';
  
    char guess;              // Store player's guessed letter
    int guessesLeft = 5;     // Number of wrong guesses allowed

    // Main game loop
    do {
        // Display current game state
        cout << "The phrase: " << partial << endl;
        cout << "Guesses left: " << guessesLeft << endl;
    
        // Get player's guess
        cout << "Enter your guess: ";
        cin >> guess;

        // Check if guess was correct
        if(!checkGuess(guess,secret,partial)){
            cout << "Whoops!" << endl;
            guessesLeft--;           // Decrement remaining guesses
        }
        // Check if player has won
        else if(strcmp(secret,partial) == 0){
            cout << "Yay you win!" << endl;
            return 0;
        }
    
    } while(guessesLeft > 0);    // Continue while guesses remain

    // Game over - player lost
    cout << "Dang, you lost!" << endl;
    cout << "The real secret was: " << secret << endl;
  
    return 0;
}
