#include <iostream>
using namespace std;

void byVal(int n){
  n = n + 1;
  cout << n << endl; // here n = 11
}

void byRef(int &n){
  n = n + 1;
  cout << n << endl;
}

int main(){

  int num = 10;
  byRef(num);
  cout << "...but actually " << num << endl;
  
  return 0;
}
