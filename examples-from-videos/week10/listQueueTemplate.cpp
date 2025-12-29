#include <iostream>
using namespace std;

// we're going to use a linked list
// which is a kind of inductive data structure
// because every list is either nullptr
// OR it's a node followed by another list
// 1 2 3 4 
//         ^current
// 1 --> 2 --> 3 --> 4 --> nullptr

template <typename T>
struct queue{
  T head;
  queue* tail;
};

template <typename T>
void enqueue(T v,queue<T>*& q){
  // add to the front
  // that means making a new queue node
  // taking the old pointer and sticking on the end
  // and then making the by-reference variable q
  // refer to the new head of the list 
  queue<T>* newFront = new queue<T>;
  newFront->head = v;
  queue<T>* temp = q;
  newFront->tail = temp; // [v] --> oldList
  q = newFront; // make the by-reference pointer q
  // actually point to the new head
}

template <typename T>
T dequeue(queue<T>*& q){
  queue<T>* temp = q;
  queue<T>* temp2 = nullptr;
  while(temp->tail != nullptr){ // this lets us stop one step before the end of the list
    // we're assuming here that you are not calling dequeue on an empty list
    temp2 = temp; // keep track of the SECOND to last item
    temp = temp->tail;
  }
  // now HERE we must be on the last node where
  // temp is NOT nullptr BUT the next node is nullptr
  // so temp is the last item and temp2 is the SECOND
  // to last item 
  T v = temp->head; // the value at the end of the list

  delete temp;
  if(temp2 == nullptr){
    q = nullptr;
  }
  else{
    temp2->tail = nullptr;
  }
  
  return v;
}

template <typename T>
void printQueue(queue<T>* q){
  cout << "The status of the queue is (<-- back to front -->):" << endl;
  queue<T>* temp = q;
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

template <typename T>
int sizeQueue(queue<T>* q){
  int size = 0;
  queue<T>* temp = q;
  
  while(temp != nullptr){
    size++;
    temp = temp->tail;
  }
  
  return size;
}

template <typename T>
void cleanup(queue<T>* q){
  queue<T>* temp = q;
  while(temp != nullptr){
    queue<T>* oldTemp = temp;
    temp = temp->tail;
    delete oldTemp;
  }
}

int main(){

  queue<int>* ourQueue = nullptr;
  
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
