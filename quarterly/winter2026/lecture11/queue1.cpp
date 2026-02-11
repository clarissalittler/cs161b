#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
};

// we can give a shortcut name to a type
// typedef existingType newName
typedef Node* List;

// every list is either empty or it is a pointer to a Node, which contains a value and a List

void printList(List l){
  List l1 = l;
  while(l1 != nullptr){
    cout << l1->val << "->";
    l1 = l1->next;
  }
  cout << "empty" << endl;
}

int sizeOf(List l){
  int s = 0;
  List l1 = l;
  while(l1 != nullptr){
    s++;
    l1 = l1->next;
  }
  return s;
}

// if the queue is empty, dequeue is undefined
// and returns the random value in memory
int dequeue(List& l){
  List temp = l; // starting node
  List temp2 = nullptr; // the person behind
  while(temp->next != nullptr){ // this is cheecking whether the person at the "front" is pointing at anyone, if they are
    temp2 = temp; // the person at the fake-front becomes the new person behind
    temp = temp->next; // the person ahead becomes the new tenuous front
  }
  int v = temp->val;
  
  delete temp;
  if(temp2 == nullptr){
    l = nullptr;
  }
  else{
    // the person behind the front has to stop
    // pointing ahead of them
    temp2->next = nullptr;
  }
  return v;
}

void deleteList(List l){
  List l1 = l;
  while(l1 != nullptr){
    List temp = l1;
    l1 = l1->next;
    delete temp;
  }
}

// enqueuePure
List enqueuePure(List l, int v){
  List newNode = new Node;
  newNode->val = v; // set the new value
  newNode->next = l;
  return newNode;
}
// enqueueImpure -> enqueue
void enqueue(Node* &l, int v){
  List newNode = new Node;
  newNode->val = v;
  newNode->next = l; // here l is the pointer to the old back
  l = newNode; // now we *change* l to point to the new back
}

int main(){

  // special value called nullptr
  // super fancy special name for 0
  // meaning the pointer that doesn't point
  // at anything
  // cout << nullptr << endl;

  List l = new Node;
  l->val = 0;
  l->next = nullptr;

  printList(l);

  l = enqueuePure(l,1);
  
  printList(l);

  enqueue(l,2);

  printList(l);

  cout << sizeOf(l) << endl;

  dequeue(l);

  printList(l);
  cout << sizeOf(l) << endl;
  
  deleteList(l);
  
  
  return 0;
}
