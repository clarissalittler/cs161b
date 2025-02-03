#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

/*
  open the file outheck.txt
  if it doesn't exist, write
  "Who's the chump writing this text?"
  if it does exist, read in the first line
  and check if it equals "Who's the chump writing this text?"
  if it does, append the line "Me. I'm the chump!"
  
 */

const int lineLength = 256;

int main(){
  fstream myFile("outheck.txt", ios::app | ios::in | ios::out);
  char line[lineLength];
  
  if(!myFile){
    cout << "Whoopsy doodle!" << endl;
    return 1;
  }

  if(myFile.getline(line,lineLength)){
    //first line was filled
    //now we need to check what it was
    if(strcmp(line,"Who's the chump writing this text?") == 0){
      myFile << "Me. I'm the chump!" << endl;
    }
    else{
      cout << "Sorry, wrong file!" << endl;
    }
  }
  else{
    //there was no first line, so write "Who's the chump writing this text?"
    myFile.clear();
    myFile << "Who's the chump writing this text?" << endl;
  }

  return 0;
}
