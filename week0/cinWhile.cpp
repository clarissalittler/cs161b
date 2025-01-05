#include <iostream>
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

int main(){
  int num1;
  num1 = readInt("Say somethin' will ya: ");

  cout << "You said: " << num1 << endl;
  return 0;
}
