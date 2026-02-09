#include <iostream>
using namespace std;

// let's pick data[0] as the back of the queue
// then data[size-1] is the front
struct Queue {
  int size;
  int data[100];
};

int queueSize(Queue q){
  return q.size;
}
// add to a queue, enqueue
// (note that we're going to silently do nothing if the queue is full)
void enqueue(Queue &q, int n){
  // adding to the back!
  // this is the HARD direction because of our
  // choices
  // since q.data[0] is the back, we need to
  // shift the entire array to the right
  // in order to make space

  // a SHIFT RIGHT
  for(int i=q.size-1; i>= 0; i--){
    q.data[i+1] = q.data[i];
  }
  q.size++;
  q.data[0] = n;  
}

// remove from queue and returns the value, dequeue
int dequeue(Queue &q){
  // with our choice of front and back
  // dequeuing is the EASY direction
  // the front of the queue is
  // q.data[q.size-1]
  // so we just need to "remove" that element
  // and decrease the size
  int v = q.data[q.size-1];
  q.size--;
  return v;
}

void printQueue(Queue q){
  for(int i=0; i<q.size; i++){
    cout << q.data[i] << "->";
  }
  cout << "front";
  cout << endl;
}

int main(){

  Queue q;
  cout << "Welcome to the queue munger" << endl;
  int option;

  do {
    cout << "1. Add to the queue" << endl;
    cout << "2. Remove from the queue" << endl;
    cout << "3. Print the queue" << endl;
    cout << "-1. Quit" << endl;
    cin >> option;
    int temp;
    switch(option){
    case 1:
      cout << "Enter an int: ";
      cin >> temp;
      enqueue(q,temp);
      break;
    case 2:
      temp = dequeue(q);
      cout << "You dequeued " << temp << endl;
      break;
    case 3:
      printQueue(q);
      break;
    case -1:
      break;
    default:
      cout << "I didn't understand that" << endl;
    }
    
  }while(option != -1);
  
  return 0;
}
