#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int lineLength = 256;

/*
  This program will read in a file line by line
  into a two-dimensional array and *then* write out the file with each line reversed (but still with the null characters in the right place)
  
 */

void reverseString(char str[]){
  // null-terminated strings
  int i = 0;
  char temp[lineLength];
  while(str[i] != '\0'){
    i++; // first we find the end point of the string
  }
  // here, i now is pointed at the end of the string
  // i.e. str[i] = '\0'
  for(int j=0; j < i; j++){
    temp[j] = str[(i-1)-j]; // the reverse
  }
  //copy the reverse back over
  for(int j=0; j < i; j++){
    str[j] = temp[j];
  }
}

int main(){

  char fileData[100][lineLength];
  ifstream inFile("heck.txt");
  ofstream outFile("kceh.txt");
  int currLine = 0;
  
  while(inFile.getline(fileData[currLine],lineLength)){
    currLine++; // at this point currLine is the length of what we've used so far
  }
  inFile.close();

  // to start, just write out the file as read in
  for(int i=0; i<currLine; i++){
    reverseString(fileData[i]);
    outFile << fileData[i] << endl;
  }
    
  return 0;
}
