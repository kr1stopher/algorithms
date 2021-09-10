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



//Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.
string reverseString(string str)
{
  int i = 0;
  string revString (1, str[str.length()-1]);
  ++i;
  while (i < str.length())
  {
    revString = revString + str[str.length()-1-i];
    ++i;
  }
  return revString;
}


bool isPermutation(string str1, string str2){
  for (int i = 0; i<str1.length();i++){
    bool isFound = false;
    for (int j=0; j<str2.length();j++){
      if (str2[j]==str1[i]){
        cout<<" j is "<<j<<endl;
        isFound == true;
        //j = str2.length();
        str1.erase(i,1);
        cout<<str1<<endl;
        cout<<"about to break"<<endl;
        //break;
      }
      if (j == str2.length()-1 && isFound == false){
      cout<<"im in here"<<endl;
        return false;
      }
    }
  }
  return true;
}
//checks to see if a string is a permutation of another string max O(n^2) time
//allows for str2 to be  a substring of str1

bool arePermutation(string str1, string str2)
{
    int count[256] = {0}; //256 == NO_OF_CHARS?
    int i;

    if (str1.length() < str2.length())
      return false;

    //increment count array depending on the character in the string, and decrement str2
    for (i = 0; str1[i] && str2[i];  i++)
    {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    //check if any values are non-zero, if so return false
    for (i = 0; i < 256; i++)
        if (count[i])
            return false;
     return true;
}
//O(n) time


//alg to replace  ' ' characters with "%20" in O(n) time
string replaceSpace(string str)
{
  for (int i = 0; i<str.length(); i++)
  {
    if (str[i]==' ')
    {
      str = str.substr(0,i) + "%20" + str.substr(i+1, str.length()-1-i);
    }
  }
  return str;
}

//count the number of  each character in the string
string charCount(string str)
{
  //count to count variables and charCount as the return
  int count[256] = {0};
  string charCount;

  //increment count at proper variable across length of string
  for (int i = 0; i<str.length(); i++){
    count[str[i]]++;
  }

  //build compressed string for values of count!=0
  for (int j = 0; j<256; j++){
    if (count[j] != 0) {
      charCount +=char(j) + to_string(count[j]);
    }
  }

  //note: compressed string is alphabetized
  return charCount;
}
//O(n) time.


/*
Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become
a2blc5a3. If the "compressed" string would not become smaller than the orig-
inal string, your method should return the original string.
*/
string compressedString(string str){
  int i = 0;
  count = 0;
  string compressedString;

  while (i<str.length()){
    int j = i;
    while (str[i] == string[j]){
      ++j;
    }
    compressedString += 
  }
}


int main()
{
  string myString = "potato";
  isUnique(myString) ? cout<<"The string is unique"<<endl : cout<<"The String is not unique"<<endl;
  isUnique2(myString) ? cout<<"The string is unique"<<endl : cout<<"The String is not unique"<<endl;
  cout<<reverseString(myString)<<" This is the reverse of myString"<<endl;
  isPermutation("mystring", "mmystring") ? cout<<" One string is a permutation of the other"<<endl : cout<<"One string is not a permutation of the  other"<<endl;
  cout<<arePermutation("mystring","mtring")<<endl;
  cout<<replaceSpace("Hello there general kenobi")<<endl;
  cout<<compression("fffeeeaaabb");


}
