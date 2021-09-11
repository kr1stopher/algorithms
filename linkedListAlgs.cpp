#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <stdio.h>
#include <cstddef>


using namespace std;

/*
class node1 {
public:
    int data;
    node* next = nullptr;

    node (int info){
      this->data = info;
      this-> next = nullptr;
    }

    void appendNode (int info){
      node* end = new node(info);
      node* n = this;
      while (n->next != nullptr){
        n =n->next;
      }
      n->next = end;
      end->next = nullptr;
    }


    void printList(){
      int i = 0;
      node* n = this;
      while (n->next !=nullptr){
        cout<<n->data<<endl;
        n = n->next;
      }
      cout<<n->data<<endl;
      }
};
*/

class node {
public:
  int data;
  node* next = nullptr;

  node (int info){
    this->data = info;
  }

  void appendNode (data){

  }

  void printList () {
    i = 0;
    node* n = this;
    while (n != nullptr){
      cout<<n->data<<"This is node: "<<i<<endl;
      n = n->next;
      ++i;
    }
  }



}



int main(){
  
  node node = node(1);
  /*
  int a[] = {2,3,4,5,6,7,8};
  for (int i = 0;i< sizeof(a)/sizeof(a[0]); i++){
    node1.appendNode(a[i]);
  }
  node1.printList();
  */
}
