#include <iostream>
// <cstdlib> <- helpful things from the C standard library (like rand/srand)
// <cstring> <- helpful things for c-style strings
// <iomanip> <- formatting text
// <vector> <- vectors
// <fstream> <-- file IO
using namespace std;

struct Scores {
  int scores[100];
  int numScores=0;
};

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

void readScores(Scores &s){
  char stop; 
  do {
    s.scores[s.numScores]
      = readInt("Enter a score: ");
    
    s.numScores++;
    cout << "stop? y/n: ";
    cin >> stop;
  }while(stop != 'y');
}

void printScores(Scores s){
  for(int i=0; i<s.numScores; i++){
    cout << i << ": " << s.scores[i] << endl;
  }
}

int findMax(Scores s){
  int max = s.scores[0];
  for(int i=1; i<s.numScores; i++){
    if(s.scores[i] > max){
      max = s.scores[i];
    }
  }
  return max;
}

int main(){

  Scores sc;
  
  readScores(sc);
  
  int option = -1;
  cout << "Choose an option: " << endl;
  cout << "0) Print scores" << endl;
  cout << "1) Find the max" << endl;
  cin >> option;

  int max;
  
  switch(option){
  case 0:
    printScores(sc);
    break;
  case 1:
    max = findMax(sc);
    cout << "The max element is: "
	 << max << endl;
    break;
  default:
    cout << "What did you just say to me?!"
	 << endl;
  }
  
  return 0;
}
