//implement an algorithm to determine if a string has unique characters, wht if you cannot use additional data structures?
#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdio.h>


using namespace std;

//function for not using any other data structures:
bool isUnique (string myString){
  int i = 0;
  while (i<myString.length()){
    int j = 0;
    while (j<myString.length()){
      if (myString[i] == myString[j]) {
        return false;
      }
    }
  }
  return true;
}
//O(n^2) time


//function using other data structures for improved performance
bool isUnique2 (string myString)
{
  //if string > 256 there must be reusused characters
  if (myString.length()>256){
    return false;
  }

  //create an array to house all characters, set equal to true once a character has been encountered
  bool chars[256] = {0};
  for (int i =0; i<myString.length();i++){
    if (chars[int(myString[i])] == true){
      return false;
    }
    chars[int(myString[i])] = true;
  }

  return true;
}
//O(n) efficiency, slightly less space efficiency





int main()
{
  string myString = "potato";
  isUnique(myString) ? cout<<"The string is unique"<<endl : cout<<"The String is not unique"<<endl;
  isUnique2(myString) ? cout<<"The string is unique"<<endl : cout<<"The String is not unique"<<endl;


}
