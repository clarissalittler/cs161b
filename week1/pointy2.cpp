#include <iostream>
using namespace std;

void doubler(int& num){
  num = 2 * num;
}



int main(){
  int thing = 10;
  int* thingAddr = &thing;

  doubler(thing);
  cout << "Now thing is: " << thing << endl;
  
  return 0;
}
