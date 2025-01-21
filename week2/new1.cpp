#include <iostream>
using namespace std;

struct Rect {
  int w;
  int h;
};

int main(){
  Rect* r = new Rect;

  // (*r).w = 10;
  r->w = 10;
  // (*r).h = 20;
  r->h = 20;

  cout << (*r).w << " " << (*r).h << endl;

  delete r;

  // int* stuff = new int[10];
  // delete[] stuff;
  
  return 0;
}
