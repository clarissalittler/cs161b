#include <iostream>
using namespace std;

int main(){

  // Initialize an int array with 5 elements.
  int arr[5] = {1, 2, 3, 4, 5};

  // Arrays are zero-indexed, so valid indices are 0..4.
  for(int i=0; i<5; i++){
    cout << arr[i] << endl;
  }

  // A C-string is a char array ending with a null terminator ("\0").
  char msg[100] = "beep boop";

  cout << msg << endl;

  // A 2D char array can store multiple fixed-width C-strings.
  char words[5][20] = {"beep", "boop", "bop", "badoop", "!"};

  for(int i=0; i < 5; i++){
    cout << words[i] << endl;
  }

  return 0;
}
