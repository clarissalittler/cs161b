#include <iostream>
#include <vector>
using namespace std;

int main(){

  auto x = 10;

  cout << x << endl;

  vector<vector<int>> vv(10);

  for(auto v : vv){
    cout << "got it!" << endl;
  }
  
  return 0;
}
