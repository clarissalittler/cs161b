#include <iostream>
using namespace std;


struct Node {
  int val;
  Node* next;
};

// we can give a shortcut name to a type
// typedef existingType newName
typedef Node* List;

// an empty list is really just
// nullptr
// a list with one thing (v) in it
// is [v|nullptr]
// a list with two thing (v1,v2) in it
// is [v1|p] where p->[v2|nullptr]
// or in another syntax we could say
// [v1|] -> [v2|nullptr]
// [v1|] -> [v2|] -> [v3|nullptr]

// s->f is syntactic sugar for (*s).f

void printList(List l){
  List l1 = l;
  while(l1 != nullptr){
    // cout << (*l1).val << "->";
    cout << l1->val << "->";
    //l1 = (*l1).next;
    l1 = l1->next;
  }
  cout << "nullptr" << endl;
}

void deleteList(List l){
    List l1 = l;
  while(l1 != nullptr){
    List temp = l1;
    l1 = l1->next;
    delete temp;
  }
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

  List l2 = new Node;
  l2->val = 1;
  l2->next = l;

  printList(l2);

  deleteList(l2);

  cout << l->val << endl;
  
  return 0;
}
