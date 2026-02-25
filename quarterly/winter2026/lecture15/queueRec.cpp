#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
};

typedef Node* List;

void printList(List l){
  if(l == nullptr){
    cout << "empty" << endl;
  }
  else{
    cout << l->val << "->";
    printList(l->next);
  }
}

int sizeOf(List l){
  if(l == nullptr){
    return 0;
  }
  else{
    return 1+sizeOf(l->next);
  }
}

/*

  l = 1 -> null

  return 1,
  delete l
  set l to nullptr

  l = 1 -> 2 -> null

  set 1->null
  return 2
  
*/

/*

  2 -> 0 -> empty

  2 != nullptr and -> 0 is not nullptr
  therefore we return
  dequeue(0 -> empty)

  0 != nullptr but empty is the nullptr

  therefore
  we return 0 and we set the next link from 2 to nullptr
  so the list becomes

  2 -> empty
  
*/

int dequeue(List& l){
  if(l != nullptr){
    // now we need to check if l->next is the null pointer, if it is then we're already at
    // the last element
    if(l->next == nullptr){
      int temp = l->val;
      delete l;
      l=nullptr;
      return temp;
    }
    else{
      return dequeue(l->next);
    }
  }
}

void deleteList(List l){
  if(l != nullptr){
    deleteList(l->next);
    delete l;
  }
}

void enqueue(List& l, int v){
  List newNode = new Node;
  newNode->val = v;
  newNode->next = l; // here l is the pointer to the old back
  l = newNode; // now we *change* l to point to the new back 
}

int main(){

  List l = new Node;
  l->val = 0;
  l->next = nullptr;

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
