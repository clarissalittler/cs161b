#include <iostream>
#include <fstream>
using namespace std;

int main(){

  ofstream myFile("outheck.txt",ios::app);

  if(!myFile){
    cout << "Couldn't open the file for writing?!" << endl;
    return 1;
  }

  myFile << "Me, I'm the chump!" << endl;

  myFile.close();
  
  return 0;
}
