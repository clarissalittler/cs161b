#include <iostream>
#include <vector>
using namespace std;

void doubler(vector<int> &v){
  for(int i=0; i<v.size(); i++){
    v[i] *= 2;
  }
}

int main(){

  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.pop_back();
  
  v[0] = 10;

  doubler(v);
  
  for(int i=0; i<v.size(); i++){
    cout << v[i] << endl;
  }
  
  return 0;
}
