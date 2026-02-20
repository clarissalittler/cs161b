#include <iostream>
using namespace std;

struct rgb {
  int red;
  int green;
  int blue;
};

struct P3 {
  int height;
  int width;
  rgb** pixels;
};

int main(){

  P3 pic;
  pic.height = 10;
  pic.width = 10;

  pic.pixels = new rgb*[pic.height];
  for(int i=0; i<pic.height; i++){
    pic.pixels[i] = new rgb[pic.width];
  }
  
  
  return 0;
}
