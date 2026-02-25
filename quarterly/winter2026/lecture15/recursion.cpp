#include <iostream>
using namespace std;

// factorial
// n! = n * (n-1)! (a logician would write (n+1)! = (n+1)*n!
// 0! = 1
// (optional) 1! = 1

int facIteration(int n){
  int temp = 1;
  for(int i=n; i>0; i--){
    temp = i*temp;
  }
  return temp;
}

int trueFactorial(int n){
  if(n <= 1){
    return 1;
  }
  else{
    return n*trueFactorial(n-1);
  }
}
// *why* is it okay that a function calls itself?

int tailCallFactorial(int n, int acc){
  if(n <= 1){
    return acc;
  }
  else{
    return tailCallFactorial(n-1,n*acc);
  }
}

int tcFactorial(int n){
  return tailCallFactorial(n,1);
}

int main(){

  cout << facIteration(5) << endl;
  cout << trueFactorial(5) << endl;
  cout << tcFactorial(5) << endl;
  
  return 0;
}
