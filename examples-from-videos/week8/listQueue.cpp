#include <iostream>
using namespace std;

// we're going to use a linked list
// which is a kind of inductive data structure
// because every list is either nullptr
// OR it's a node followed by another list
// 1 2 3 4 
//         ^current
// 1 --> 2 --> 3 --> 4 --> nullptr

struct queue{
  int head;
  queue* tail;
};

void enqueue(int v,queue*& q){
  // add to the front
  // that means making a new queue node
  // taking the old pointer and sticking on the end
  // and then making the by-reference variable q
  // refer to the new head of the list 
  queue* newFront = new queue;
  newFront->head = v;
  queue* temp = q;
  newFront->tail = temp; // [v] --> oldList
  q = newFront; // make the by-reference pointer q
  // actually point to the new head
}

int dequeue(queue*& q){
  queue* temp = q;
  queue* temp2 = nullptr;
  while(temp->tail != nullptr){ // this lets us stop one step before the end of the list
    // we're assuming here that you are not calling dequeue on an empty list
    temp2 = temp; // keep track of the SECOND to last item
    temp = temp->tail;
  }
  // now HERE we must be on the last node where
  // temp is NOT nullptr BUT the next node is nullptr
  // so temp is the last item and temp2 is the SECOND
  // to last item 
  int v = temp->head; // the value at the end of the list

  delete temp;
  if(temp2 == nullptr){
    q = nullptr;
  }
  else{
    temp2->tail = nullptr;
  }
  
  return v;
}

void printQueue(queue* q){
  cout << "The status of the queue is (<-- back to front -->):" << endl;
  queue* temp = q;
  int sz = 0;
  while(temp != nullptr){
    cout << "head: " << temp->head << " " << "-->" << endl;
    sz++;
    for(int i = 0; i < sz; i++){
      cout << "  ";
    }
    temp = temp->tail;
  }
  cout << "null" << endl;
}

int sizeQueue(queue* q){
  int size = 0;
  queue* temp = q;
  
  while(temp != nullptr){
    size++;
    temp = temp->tail;
  }
  
  return size;
}

void cleanup(queue* q){
  queue* temp = q;
  while(temp != nullptr){
    queue* oldTemp = temp;
    temp = temp->tail;
    delete oldTemp;
  }
}

int main(){

  queue* ourQueue = nullptr;
  
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

  cleanup(ourQueue);
  
  return 0;
}
