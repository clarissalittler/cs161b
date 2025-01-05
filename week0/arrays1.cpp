#include <iostream>
using namespace std;

int main(){
  int num[5];

  for(int i = 0; i < 5; i++){
    cout << "Enter the " << i << "th number: ";
    cin >> num[i];
  }

  for(int i = 0; i < 5; i++){
    cout << "The " << i << "th number is: " << num[i] << endl;
  }
  
  return 0;
}
