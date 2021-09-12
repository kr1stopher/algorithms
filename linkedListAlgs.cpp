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

  //friend void removeDuplictes(node n);
  void removeDuplictes(){
    node* m = this; //m will be the first pointer

    if (m->next == nullptr){
      return;
    }

    node* m1 = m->next; //m1 will be the further ahead pointer
    vector<int> stored;
    stored.push_back(m->data);
    while (m1->next!=nullptr){
      bool duplicate = false;
      for (int i =0; i<stored.size()-1; i++){
        if (stored[i]==m->data){
          duplicate = true; //delete node
          m->next = m1->next;
          m1 = m->next; //need to add case to check if m is null ptr
          cout<<"at least trying to delete"<<endl;
        }
      }

      stored.push_back(m->data);
      cout<<stored[stored.size()-1]<<endl;
      if (duplicate == false){
        m = m->next;
        m1 = m1->next;
      }
    }


  }
};

/*
//Write code to remove duplicates from an unsorted linked list.
void removeDuplictes(node n){
  node* m = & n; //m will be the first pointer
  if (m->next = nullptr)
    return;
  node* m1 = m->next; //m1 will be the further ahead pointer
  vector<int> stored;
  m1 = m1->next;
  cout<<"just before zz"<<endl;
  node* z = m1->next;
  cout<<"in here"<<endl;
  while (m1->next!=nullptr){
    bool duplicate = false;
    cout<<"in here 2.0 bitches"<<endl;
    for (int i =0; i<stored.size()-1; i++){
      if (stored[i]==m1->data){
        duplicate = true; //delete node
        m->next = m1->next;
        m1 = m->next; //need to add case to check if m is null ptr
      }
    }

    stored.push_back(m->data);
    if (duplicate == false){
      m = m->next;
      m1 = m1->next;
    }
  }


}
*/



int main(){

  node node1 = node(1);
  int a[] = {2,3,3,4,5,6,7,8};
  for (int i = 0;i< sizeof(a)/sizeof(a[0]); i++){
    node1.appendNode(a[i]);
  }
  node1.printList();
//removeDuplictes(node1);
  node1.removeDuplictes();
  cout<<"Below is the list with duplicates removed"<<endl;
  node1.printList();

}
