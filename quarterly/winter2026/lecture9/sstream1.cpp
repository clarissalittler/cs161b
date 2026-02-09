#include <iostream>
#include <sstream>
using namespace std;

int main(){

  string s = "thing1,2,3";
  stringstream streamy(s);

  string item1;
  string strItem2;
  int item2;
  int item3;

  getline(streamy,item1,',');
  getline(streamy,strItem2,',');
  item2 = stoi(strItem2);
  streamy >> item3;

  cout << item1 << " " << item2 << " " << item3 << endl;
  
  return 0;
}
