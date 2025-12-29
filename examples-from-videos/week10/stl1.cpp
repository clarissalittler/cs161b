#include <iostream>
#include <vector>
using namespace std;

/*
  Here's some tricks if you wanted to refactor the image processing program:

  You could have a 2d vector of vectors and create new vectors for each row with new and then push the pixels into each row with push_back and then use this iterator tricks to simplify your code!
 */

int main(){
  vector<int> num = {1,2,3,4,5};

  vector<vector<int>> twoD = {{1,2,3},{4,5,6}};
  
  for(auto i = twoD.begin(); i != twoD.end(); i++){
    for(auto j = i->begin(); j != i->end(); j++){
      cout << *j << " ";
    }
    cout << endl;
  }
  
  return 0;
  
}
