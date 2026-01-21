#include <iostream>
// <cstdlib> <- helpful things from the C standard library (like rand/srand)
// <cstring> <- helpful things for c-style strings
// <iomanip> <- formatting text
// <vector> <- vectors
// <fstream> <-- file IO
using namespace std;

// how do we read in a bunch of items and then process it in a menu afterwards?

// 1. finish the sketch
// 1.b (add a error handling function to reading ints)
// 2. turn this into a struct (pair the length and the array together)
// 3. break into functions

int readInt(string prompt){
  int val;

  cout << prompt;
  cin >> val;
  while(cin.fail()){
    cin.clear(); // clears the error bit
    cin.ignore(256,'\n'); // the compiler can't catch if you swap these arguments, your code will just do absurd things
    cout << prompt;
    cin >> val;
  }
  
  return val;
}

int main(){

  int scores[100]; // we use up to a MAX of 100
  int numScores = 0;

  // first we read scores in until the user
  // says stop
  char stop; // should be y for stop, anything else to continue
  do {
    scores[numScores]
      = readInt("Enter a score: ");
    // the current spot which is scores[numScores]
    numScores++;
    cout << "stop? y/n: ";
    cin >> stop;
  }while(stop != 'y');

  int option = -1;
  cout << "Choose an option: " << endl;
  cout << "0) Print scores" << endl;
  cout << "1) Find the max" << endl;
  cin >> option;

  int max = scores[0];
  
  switch(option){
  case 0:
    for(int i=0; i<numScores; i++){
      cout << i << ": " << scores[i] << endl;
    }
    break;
  case 1:
    // okay BECAUSE we force you to enter
    // at least one thing
    for(int i=1; i<numScores; i++){
      if(scores[i] > max){
	max = scores[i];
      }
    }
    cout << "The max element is: "
	 << max << endl;
    break;
  default:
    cout << "What did you just say to me?!"
	 << endl;
  }
  
  return 0;
}
