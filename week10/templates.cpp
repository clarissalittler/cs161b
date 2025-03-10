#include <iostream>
using namespace std;

template <typename T>
void swappy(T& a, T& b){
  T temp = a;
  a = b;
  b = temp;  
}

struct Goofus {
  int a;
  int b;
  float c;
};

int main(){

  int num1 = 0;
  int num2 = 10;

  Goofus g1 = {1,2,3.0};
  Goofus g2 = {5,4,4.0};
  
  cout << "Before swapping: " << endl;
  cout << "g1.a: " << g1.a << endl;
  cout << "g2.a: " << g2.a << endl;

  swappy(g1,g2);
  
  cout << "After swapping: " << endl;
  cout << "g1.a: " << g1.a << endl;
  cout << "g2.a: " << g2.a << endl;
  
  return 0;
}
