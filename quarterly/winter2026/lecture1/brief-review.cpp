#include <iostream>
using namespace std;

void hello(string name){
  cout << "Hello, " << name << endl;
}

int main(){

  hello("161b");

  int acc = 0;
  
  for(int i=0; i< 10; i++){
    acc = acc + i;
  }

  string inp;

  do {
    if(inp != ""){
      cout << "Naw, that's not what I was thinking of" << endl;
    }
    cout << "Enter a thing: " << endl;
    cin >> inp;
  }while(inp != "coding");
  cout << "Oh yeah, that's right, I'm supposed to be coding right now" << endl;
  
  return 0; // return code
}
