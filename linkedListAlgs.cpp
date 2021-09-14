#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <stdio.h>
#include <cstddef>
#include <vector>
#include <cmath>
#include <stack>

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
      printf("Node %d contains data %d \n",i,n->data);
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

/*
You have two numbers represented by a linked list, where each node contains a
single digit. The digits are stored in reverse order, such that the Ts digit is at the
head of the list. Write a function that adds the two numbers and returns the sum
as a linked list.
EXAMPLE
Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is, 617 + 295.
Output: 2 -> 1 -> 9.That is, 912.
*/

node magicAddition2(node n){
  vector<int> numbers;
  node *m  = & n;

  //store the  data from the  linked list in numbers
  while (m!=nullptr){
    numbers.push_back(m->data);
    m=m->next;
  }

  //assemble the numbers in proper orderr, convert to int for addition, convert back to string
  int ans = stoi(to_string(numbers[2]) + to_string(numbers[1]) + to_string(numbers[0])) + stoi(to_string(numbers[5]) + to_string(numbers[4]) + to_string(numbers[3]));
  string ansString = to_string(ans);

  //create linked list of answer starting with the ones digit
  node nodeOne = node(ansString[ansString.length()-1] - '0');
  nodeOne.printList();
  for (int i = 1; i<ansString.length(); i++){
    nodeOne.appendNode(ansString[ansString.length()-i-1] - '0');
  }

  //return initial node to linked list
  return nodeOne;
}
//way to improve: rather than conveting to string to index use modulo %
//better immprovement: multiple by 1, 10, 100, & add

//improved magicAddition using floor and % instead of to_string and stoi
node magicAddition(node n){
  vector<int> numbers; //for storing the values in the linked list
  node *m  = & n;
  while (m!=nullptr){   //store the  data from the  linked list in numbers
    numbers.push_back(m->data);
    m=m->next;
  }

  //assemble the numbers in proper orderr, convert to int for addition, convert back to string
  int ans = numbers[2]*100 + numbers[1]*10 + numbers[0]*1 + numbers[5]*100 + numbers[4]*10 + numbers[3]*1;
  node nodeOne = node(ans%10/1);
  nodeOne.appendNode(floor((ans%100)/10));
  nodeOne.appendNode(floor((ans%1000)/100));
  return nodeOne;
}


//detect a loop a linked list
//where nodes collide, they are k nodes away from the start of the loop (k is also the distance from head node to start of loop)
//after collision, move one node to head, then move forward at same speed until colide magicAddition
//return that node
node* detectLoop(node n){
  node* slow = &n;
  node* fast = &n;
  bool init = true;

  while (fast!=slow || init == true){ //go until the pointers collide
    slow = slow->next;
    fast = fast->next->next;
    init = false;
  }
  if (slow == nullptr || fast == nullptr){ //if there was not a loop in the list return nullptr
    return nullptr;
  }

  slow = &n; //set slow back to the starting point
  while (fast!=slow){ //go until they collide again, but at the same speed.
    slow = slow->next;
    fast = fast->next;
  }
  return fast;//collision is the start of the loop
}


//check to see if a linked list  is a palindrome
bool isPalindrome (node n){
  slow = &n;
  fast = &n;
  stack<int> stack;
  while (fast!=nullptr){
    fast = fast->next->next;
    stack.push(slow->data);
    slow = slow->next;
  }
  while (slow!=nullptr){
    if (slow->data != stack.top()){
      return false;
    }
    stack.pop();
    slow = slow->next;
  }
  return true;
}

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

  node nodeAddition = node(7);
  int a1[] = {1,6,5,9,2};
  for (int i = 0;i< sizeof(a)/sizeof(a1[0]); i++){
    nodeAddition.appendNode(a1[i]);
  }
  node answer = magicAddition(nodeAddition);
  cout<<"Below is the magic addition answer"<<endl;
  answer.printList();

  //create a loop in node1's linked list
  node* pointer =  node1.next;
  node* startLoop = pointer->next->next->next;
  while (pointer->next != nullptr){
    pointer = pointer->next;
    }
  pointer->next = startLoop;
  //test to see if detectLoop finds the correct starting point
  if (detectLoop(node1) == startLoop){
    cout<<"The start of the loop was correctly detected in"<<endl;
  }




}
