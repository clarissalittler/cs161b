#include <iostream>
using namespace std;

int main(){

  int arr[5] = {1, 2, 3, 4, 5};

  for(int i=0; i<5; i++){
    cout << arr[i] << endl;
  }

  char msg[100] = "beep boop";

  cout << msg << endl;

  char words[5][20] = {"beep", "boop", "bop", "badoop", "!"};

  for(int i=0; i < 5; i++){
    cout << words[i] << endl;
  }
  
  return 0;
}
