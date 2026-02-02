// this is a little file that's basically a helper for you to see how to do project 3 in my cs161b class!
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// so the tricky bit here is that since we don't know in advance how big the array will be
// we'll need to new in order to build it all out

struct P1 {
  int width;
  int height;
  int** pixels;
};

void parseFile(struct P1 img, ifstream& f){
  for(int i=0; i < img.height; i++){
    for(int j=0; j < img.width; j++){
      f >> img.pixels[i][j];
    }
    f.ignore(256,'\n');
  }
}

void printImage(struct P1 img){
  for(int i=0; i < img.height; i++){
    for(int j=0; j < img.width; j++){
      cout << img.pixels[i][j] << " ";
    }
    cout << endl;
  }
}

void invertImage(struct P1 img){
  for(int i=0; i < img.height; i++){
    for(int j=0; j < img.width; j++){
      img.pixels[i][j] = !img.pixels[i][j];
    }
  }
}


int main(){
  // let's read the preface of the file
  char preface[50];
  ifstream inputFile("test.ppm");

  struct P1 image;
  
  inputFile.getline(preface,50);
  if(strcmp(preface,"P1") == 0){
    cout << "This is an image file so let's process it!" << endl;
    int tempWidth;
    int tempHeight;
    inputFile >> tempWidth;
    inputFile >> tempHeight;
    image.width = tempWidth;
    image.height = tempHeight;
    
    inputFile.ignore(256,'\n');
    // now we initialize the size of our array of arrays
    image.pixels = new int*[image.height];
    for(int i=0; i < image.height; i++){
      image.pixels[i] = new int[image.width];
    }
    // okay we've set up the dynamic array
    // now we can read into it
    parseFile(image,inputFile);
    invertImage(image);
    printImage(image);
  }
  else{
    cout << "Whoops this isn't an image file, bye!" << endl;
    return 0;
  }

  return 0;
}
