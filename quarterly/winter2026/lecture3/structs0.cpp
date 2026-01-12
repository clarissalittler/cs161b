#include <iostream>
using namespace std;

struct Rect{
  int height;
  int width;
};

int main(){

  Rect r; // = { 20, 10};
  // name of the variable followed by a . followed by the name of the field
  r.width = 20;
  r.height = 10;

  cout << r.width << endl;
  cout << r.height << endl;
  
  return 0;
}
