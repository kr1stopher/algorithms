#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <stdio.h>
#include <cstddef>
#include <vector>


using namespace std;


class node {
public:
  int data;
  node* next = nullptr;

  node (int info){
    this->data = info;
  }

  void appendNode (int data){
    node* end = new node(data);
    node* n = this;
    while (n->next != nullptr){
      n = n->next;
    }
    n->next = end;
  }

  void printList () {
    int i = 0;
    node* n = this;
    while (n != nullptr){
      cout<<n->data<<"This is node: "<<i<<endl;
      n = n->next;
      ++i;
    }
  }

};


//write a function to remove duplicates from the linked list
void removeDuplictes(node n){
  node* m = & n; //m will be the first pointer

  if (m->next == nullptr){
    return;
  }

  node* m1 = m->next; //m1 will be the further ahead pointer
  vector<int> stored;
  stored.push_back(m->data);
  while (m1!=nullptr){
    bool duplicate = false;
    for (int i =0; i<stored.size(); i++){
      cout<<"(m1->data, stored[i])"<<m1->data<<" , "<<stored[i]<<endl;
      if (stored[i]==m1->data){
        duplicate = true; //delete node
        m->next = m1->next;
        m = m1;
        m1 = m1->next;
        break;
      }
    }
    cout<<stored[stored.size()-1]<<endl;
    if (!duplicate){
      //stored.push_back(m->data);
      m = m->next;
      m1 = m1->next;
    }
    stored.push_back(m->data);
  }
}

void  

int main(){

  node node1 = node(1);
  int a[] = {2,3,3,4,5,6,7,3};
  for (int i = 0;i< sizeof(a)/sizeof(a[0]); i++){
    node1.appendNode(a[i]);
  }
  node1.printList();
//removeDuplictes(node1);
  removeDuplictes(node1);
  cout<<"Below is the list with duplicates removed"<<endl;
  node1.printList();

}
