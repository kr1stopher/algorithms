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
      if (stored[i]==m1->data){
        duplicate = true; //delete node
        m->next = m1->next;
        m = m1;
        m1 = m1->next;
        break;
      }
    }
    if (!duplicate){
      //stored.push_back(m->data);
      m = m->next;
      m1 = m1->next;
    }
    stored.push_back(m->data);
  }
}

//alg to find the kth to last element of a singly linked list
int  kthElement (int k, node n) {
  if (k<1) //return error if k is too small
  {
    cerr<<endl<<"Invalid  input k<1"<<endl;
    exit(1);
  }
  vector<int> elements;
  node* m = & n;

  //go through the linked list adding the data of each node to elements
  while (m!=nullptr){
    elements.push_back(m->data);
    m = m->next;
  }

  //check to make sure that k is not too large for the linked list
  if (k>elements.size())
  {
    cerr<<endl<<"Invalid input k>length of list"<<endl;
    exit(1);
  }

  //return the kth to last element
  return elements[elements.size()-k];
}

//given only a node, delete that node from the linked list
void  deleteNode (node n){
  n.data = n.next->data;
  n.next = n.next->next;
}
//note: cannot be the final node in the list

int main(){

  //create a linked list using the node class for testing algs
  node node1 = node(1);
  int a[] = {2,3,3,4,5,6,7,3};
  for (int i = 0;i< sizeof(a)/sizeof(a[0]); i++){
    node1.appendNode(a[i]);
  }


  //testing algs
  node1.printList();
  removeDuplictes(node1);
  cout<<"Below is the list with duplicates removed"<<endl;
  node1.printList();
  cout<<"2nd ot last element is "<<kthElement(2,node1)<<endl;


}
