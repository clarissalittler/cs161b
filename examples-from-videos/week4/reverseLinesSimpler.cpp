#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int lineLength = 256;

/*
  This program will read in a file line by line
  into a two-dimensional array and *then* write out the file with each line reversed (but still with the null characters in the right place)
  
 */

void reverseString(char str[],char reverse[]){
  // null-terminated strings
  int i = strlen(str);

  // here, i now is pointed at the end of the string
  // i.e. str[i] = '\0'
  for(int j=0; j < i; j++){
    reverse[j] = str[(i-1)-j]; // the reverse
  }
  reverse[i]='\0';
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
    char reverseLine[lineLength];
    reverseString(fileData[i],reverseLine);
    outFile << reverseLine << endl;
  }
    
  return 0;
}
