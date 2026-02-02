#include <iostream>
#include <fstream>
using namespace std;

struct P1 {
  int width;
  int height;
  // this needs to be an array of arrays
  int** pixels;
};

void readImage(P1 p, ifstream& ifile){
  for(int j=0; j<p.height; j++){
    for(int i=0; i<p.width; i++){
      ifile >> p.pixels[j][i];
      // i >> p.pixels[j][i]
    }
  }
}

void printImage(P1 p){
  for(int j=0; j<p.height; j++){
    for(int i=0; i<p.width; i++){
      cout << p.pixels[j][i] << " ";
    }
    cout << endl;
  }
}

void invertImage(P1 p){
  for(int j=0; j<p.height; j++){
    for(int i=0; i<p.width; i++){
      p.pixels[j][i] = !p.pixels[j][i]; 
    }
  }
}

void writeImage(P1 p, ofstream& f){
  f << "P1" << endl;
  f << p.width << " " << p.height << endl;
  for(int j=0; j<p.height; j++){
    for(int i=0; i<p.width; i++){
      f << p.pixels[j][i] << " ";
    }
    f << endl;
  }
}

int main(){

  ifstream img("test.ppm");
  string header;
  P1 pix;
  
  img >> header;
  if(header != "P1"){
    cout << "This isn't an image file!" << endl;
    return 1; // exit early
  }
  cout << header << endl;
  img >> pix.width;
  img >> pix.height;

  cout << "The image is " << pix.width << " pixels wide" << endl;
  cout << "and it is " << pix.height << " pixels tall" << endl;
  // let's initialize the image
  pix.pixels = new int*[pix.height];
  for(int j=0; j< pix.height; j++){
    pix.pixels[j] = new int[pix.width];
  }
  // now memory has been allocated

  readImage(pix,img);
  
  invertImage(pix);

  printImage(pix);
  
  img.close();

  ofstream oimg("test.ppm");

  writeImage(pix,oimg);
  oimg.close();
  
  for(int j=0; j<pix.height; j++){
    delete[] pix.pixels[j];
  }
  delete[] pix.pixels;
  
  return 0;
}
