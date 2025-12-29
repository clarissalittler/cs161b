#include <iostream>
#include <fstream>
using namespace std;

const int lineLength = 256;

int main(){

  ifstream ourFile("heck.txt");

  char line[lineLength];
  
  if(!ourFile){
    cout << "Whoops, didn't find that??" << endl;
    return 1;
  }

  cout << "The contents of the file were: " << endl;
  while(ourFile.getline(line,lineLength)){
    cout << line << endl;
  }
  ourFile.close();
  
  return 0;
}
