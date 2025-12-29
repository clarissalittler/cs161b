#include <iostream>
using namespace std;

int main(){
  int num1;
  
  cout << "Say somethin' will ya: ";
  cin >> num1;

  cout << "You said: " << num1 << endl;

  if(cin.fail()){
    cin.clear(); // fix the error bit
    cin.ignore(256,'\n');
    cout << "What was that again?: ";
    cin >> num1;

    cout << "You said: " << num1 << endl;
  }

  if(cin.fail()){
    cin.clear(); // fix the error bit
    cin.ignore(256,'\n');
    cout << "What was that again?: ";
    cin >> num1;

    cout << "You said: " << num1 << endl;
  }

  return 0;
}
