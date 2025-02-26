#include <iostream>
using namespace std;
// this file will implement a queue with an array

const int maxSize = 100;

// first let's build a struct that will hold
// the actual array *and* the current size used
// we'll represent 0 as the "back" of the queue
// i.e. where things get added
// and that means data[current-1] is the next spot in the
// queue to get removed

struct queue {
  int data[maxSize]; // here's the data for the queue
  int current = 0; // here's how many spots are currently used
};

/// 0 1 2 3 4
/// v 0 1 2 3 4 // if you traverse to the left
/// 0 1 2 3 4
/// _ 0 0 0 0 // if you traverse to the right

void enqueue(int v,queue &q){
  if(q.current < maxSize){
    // this should add v to the back of the queue
    // first need to shift the array to the right
    for(int i = q.current-1; i >= 0; i--){
      q.data[i+1] = q.data[i]; // move everything to the right
    }
    q.data[0] = v;
    q.current++;
  }
  else{
    cout << "The queue is full!" << endl;
  }
}

int dequeue(queue &q){
  // this should remove the element at the front of the queue
  if(q.current > 0){
    int temp = q.data[q.current-1];
    q.current--;
    return temp;
  }
  else{
    return 0;
  }
}

void printQueue(queue q){
  cout << "The status of the queue is (<-- back to front -->):" << endl;
  for(int i = 0; i < q.current; i++){
    cout << q.data[i] << " ";
  }
  cout << endl;
}

int sizeQueue(queue q){
  return q.current;
}

int main(){

  queue ourQueue;
  
  int choice;
  int temp;
  do {
    printQueue(ourQueue);
    cout << "1. Enqueue a value" << endl;
    cout << "2. Dequeue a value" << endl;
    cout << "0. Quit" << endl;
    cout << "Make a choice: ";
    cin >> choice;
    
    switch(choice){
    case 1:
      cout << "Enter value to enqueue: ";
      cin >> temp;
      enqueue(temp,ourQueue);
      break;
    case 2:
      if(sizeQueue(ourQueue) > 0) {
        temp = dequeue(ourQueue);
        cout << "We popped the value: " << temp << endl;
      }
      else{
        cout << "You can't dequeue an empty queue" << endl;
      }
      break;
    case 0:
      break;
    }
    
  }while(choice != 0);

  return 0;
}
