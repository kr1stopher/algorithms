#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <vector>
#include<algorithm>



using namespace std;

/*
//some polymorphism stuff 
class shape {
    protected:
        double height; 
        double width;
    public:
        shape(int a = 0, int b = 0){
            width = a;
            height = b;
        }
        virtual void area() = 0;
};

class rectangle: public shape {
    public:
        rectangle( int a = 0, int b = 0):shape(a,b) {}

        void area () {
            cout<<"The area is "<<width*height<<endl;
        }


};
*/


//example smart pointer class 
template <class T>
class Smartpointer {
    T *p; //actual pointer 
    public:
        //constructor 
        Smartpointer(T *ptr = NULL){
            p = ptr;
        }
        //Destructor 
        ~Smartpointer(){
            delete(p);
        }
        //overloading dereferencing operator 
        T & operator * () {
            return *p;
        }
        //Overloding arrow operator so that members of T can be accessed like apointer 
        T * operator -> () {
            return p;
        }
}; 


//pass unique ptr to function using "move"
void myFunc(unique_ptr<int> arg){
    cout<<endl<<*arg<<endl;
}
//pass unique ptr by reference
void myFunc2 (unique_ptr<int> & arg){
    int i = *arg;
    cout<<endl<<i<<endl;
}



class shape {
    protected:
        double height;
        double width;
    public:
        shape (int a = 0, int b = 0) {
            width = a; 
            height = b;
        }
        virtual void area() = 0;
};

class rectangle: public shape{
    public:
        rectangle (int a = 0, int b = 0): shape(a,b) {};
        void area () {
            cout<<endl<<"The area of the rectangle is: "<<width*height<<endl;
        }
        rectangle operator+(const rectangle& b) {
            rectangle rect(this->width + b.width, this->height + b.height); 
            return rect;
        }
};

class triangle: public shape{
    public:
        triangle(int a = 0, int b = 0): shape(a,b) {};
        void area () {
            cout<<endl<<"The area of the triangle is: "<<width*height*.5<<endl;
        }
};

//remove the area of the triangle from the rectangle (if rect>tri)


//ptr practice problems 
void user_int (){
    shared_ptr<int> ptr_a = make_shared<int>();
    shared_ptr<int> ptr_b = make_shared<int>();
    cout<<"enter two integers"<<endl;
    cin>>*ptr_a;
    cin>>*ptr_b; 

    cout<<"The value of ptr_a is "<<*ptr_a<<endl;
    cout<<"The value of ptr_b is "<<*ptr_b<<endl;



}

void shift_string(){
    string myString;
    cout<<"Please enter the string you wish to shift"<<endl;
    cin>>myString;

    int i = 0; 
    while (i<myString.length()){
        myString[i]++;
        i++;
    }
    cout<<myString<<endl;
}


int find_odd(int input[], int size){
    map<int, int> totals;
    map<int, int>::iterator it;
    int i = 0; 
    while (i<size){
        it = totals.find(input[i]);
        if (it == totals.end()){
            totals.insert(make_pair(input[i], 1));
        }else {
            it->second++;
        }
        i++;
    }

    for (auto const& i: totals){
        if (i.second % 2 != 0){
            cout<<i.first<<" has odd entries"<<endl;
        }

    }

    return -1;
}


int findodd1(vector<int> arr) {
	int number = 0;
    cout<<0<<endl;
	for( auto a: arr) {
		number = number ^ a;
        cout<<number<<endl;
	}
	return number;
}


void test_vector(){
    vector<int> vec;
    for (int i =0;i<8;i++){
        vec.push_back(i);
    }
    for (auto const& j : vec){
        cout<<j<<endl;
    }

}

void make_box(int n){
    cout<<endl;
    string top(n, '#');
    string center(n-2, ' ');
    center = '#' + center + '#';

    for (int i = 0; i<n; i++){
        if (i==0 or i==n-1){
            cout<<top<<endl;
        }else {
        cout<<center<<endl;
        }
    }

}

int collatz(int n){
    cout<<endl<<n<<endl;
    while (n > 1){
        if (n%2 == 0){
            n=n/2;
        }else {
            n=n*3+1;
        }
        cout<<n<<endl;
    }
    return n;
}

int prison(int prison[], int size){
    if (prison[0] == 0) {return 0;};
    int unlocked = 1;
    int freed = 0;
    for (int i =0; i<size; i++){
        if (prison[i] == unlocked){
            freed++;
            unlocked = abs(unlocked - 1);
        }
    }
    cout<<endl<<freed<<" is the total freed"<<endl;
    return freed;
}

int freedPrisoners(vector<int> prison) {
    if (prison[0] == 0) {return 0;};
    int unlocked = 1;
    int freed = 0;
    for (auto const& i:prison){
        if (i == unlocked){
            freed++;
            unlocked = abs(unlocked - 1);
        }
    }
    return freed;
}

bool same_letter(string one, string two){
    bool isSame=true;
    map<char, vector<int>> pattern1;
    map<char, vector<int>> pattern2;
    vector<char> seen1;
    vector<char> seen2;
    int i = 0;
    cout<<"made it"<<endl;
    for (int i =0; i<one.length(); i++){
        if (find(seen1.begin(), seen1.end(), one[i]) ==seen1.end()){
            seen1.push_back(one[i]);
            vector<int> initialize = {i};
            pattern1.insert(make_pair(one[i], initialize));
            cout<<one[i]<<"added"<<endl;
        }else {
            pattern1.find(one[i])->second.push_back(i);
        }
    }
    cout<<pattern1.find(one[i])->second[0];
    cout<<"checkpoint"<<endl;
    for (auto const&i:pattern1.find(one[i])->second){
        cout<<i<<endl;
    }
    for (int i =0; i<two.length(); i++){
        if (find(seen2.begin(), seen2.end(), two[i]) ==seen2.end()){
            seen2.push_back(two[i]);
            vector<int> initialize = {i};
            pattern2.insert(make_pair(two[i], initialize));
            cout<<two[i]<<"added"<<endl;
        }else {
            pattern2.find(two[i])->second.push_back(i);
        }
    }

    //check if they are the same:
    for (int i =0; i<seen1.size();i++){
        if (pattern1.find(seen1[i])->second !=  pattern2.find(seen2[i])->second){
            isSame = false;
        }
    }

    return isSame;
}



/*
Create a function billCount that takes two arguments. The first argument is the amount of money the user has and the second is the array of money bills available. Return the minimum count of money bills required to equal the user money amount.
*/

int billCount (vector<int> avail_bills, int total){
    int total_bills = 0;
    int test_total = 0; 

    while (test_total != total && avail_bills.size() > 0){
        int largest = *max_element(avail_bills.begin(), avail_bills.end());
        while (test_total+largest <= total){
            test_total+=largest;
            total_bills++;
        }
        avail_bills.erase(max_element(avail_bills.begin(), avail_bills.end()));
    }

    if (test_total == total){
        return total_bills;
    } else {
        return -1;
    }
}

int billCount1(vector<int> avail_bills, int total){
    int count = 0;
    sort(avail_bills.begin(), avail_bills.end(), ::greater<int>());
    for (auto i:avail_bills){
        count += total/i;
        total -= (total/i)*i; 
        if (total == 0){break;}
    }
    if (total == 0){
        return count;
    }else {return -1;}
}


string reverse_code(string input){
    int index = 0;
    string output = "";
    int multiple;
    char myChar;
    for (auto i: input){
        if (index == 1){
            multiple = i - '0';
            string s(multiple, myChar);
            output += s;
        }
        if (index == 0){
            myChar = i;
        }
        index = abs(index-1);
    }
    return output;
}


//improved version 
string reverse_code2(string input){
    string output;
    for (int i=0; i<input.length(); i+=2){
        string s(input[i+1]-'0', input[i]);
        output += s;
    }
    return output;
}

//returns # of proper fractions available for given denominator d
int proper (int d){
    int count = 0; 
    for (int i =1; i<d; i++){
        if (__gcd(i,d)==1){count++;} 
    }
    return count;
}

//take a vector and find two items such that x*y = n in n time 
vector<int> twoProduct(vector<int> input, int n){
    if (input.size()<2){return {0,0};};
    vector<int> seen;
    vector<int> output;
    if (n == 0){
        vector<int>::iterator it = find(input.begin(), input.end(), 0); 
        if (it == input.begin()){
            return {*it, *++it};
        }else if (it == input.end()){
            return {0,0};
        }else {
            return {*--it, *it};
        }
        
    }
    for (auto i:input){
        if (i != 0 && n!=0 && *find(input.begin(), input.end(), n/i)*i == n){
            return {i, n/i};
        }
        seen.push_back(i); 
    }

    output.push_back(0); 
    output.push_back(0); 
    return output;
}



//same letter
bool samePattern (string input1, string input2){
    if (input1.length() != input2.length()){
        return false;
    }
    cout<<input1.length();
    for (int i =0; i<input1.length(); i++){
        if (input1.find(input1[i]) != input2.find(input2[i])) {
            return false;
        }
    }
    return true;
}



int main() {

    /*
    //pass using move function 
    unique_ptr<int> myptr = make_unique<int>();
    *myptr = 9;
    myFunc(move(myptr));
    unique_ptr<int> myptr2 = make_unique<int>();
    *myptr2 = 9;
    myFunc2(myptr2);
    cout<<endl<<*myptr2<<" in main"<<endl;

>>
    unique_ptr<rectangle> rect = make_unique<rectangle>();
    unique_ptr<triangle> tri = make_unique<triangle>();
    triangle mytri(1,2); 
    rectangle myrec(2,2);

    *rect = myrec;
    *tri = mytri; 
    
    rect->area();
    tri->area();

    unique_ptr<rectangle> newRect =make_unique<rectangle>();
    *newRect = *rect + *rect;
    newRect->area();

    user_int();
    */

   //shift_string();

   /*no longer testing this section
   int test[11] = {0,0,1,1,2,2,3,4,4,5,5};
   cout<<(sizeof(test)/sizeof(test[0]))<<endl;
   find_odd(test, (sizeof(test)/sizeof(test[0])));
   test_vector();
   make_box(8);

    collatz(5);
    int myPrison[7] = {1, 1, 0, 0, 0, 1, 0};
    prison(myPrison, 7);

    vector<int> yPris = {1, 1, 0, 0, 0, 1, 0};
    cout<<freedPrisoners(yPris)<<endl;

    int * ptr;
    int i;
    ptr = &i;
    cout<<same_letter("aaaacccadd", "bbbbaaabee")<<endl;

    */

   vector<int> test = {1,10,20,100};
   int money = 1001;
   cout<<"The min # of bills is "<<billCount(test, money)<<endl;
   cout<<"The min # of bills is "<<billCount1(test, money)<<endl;

    string test_string = "A4B5C2";
    cout<<reverse_code(test_string)<<endl;
    cout<<reverse_code2(test_string)<<endl;

    vector<int> testMe = {0,0,1,1,2,2,2,3,3};
    cout<<findodd1(testMe)<<endl;


    cout<<"Testing bitwise operators"<<endl;
    cout<<(~35)<<endl;

    vector<int> testFraction = {1,2,5,25};
    for (auto i:testFraction){
        cout<<i<<": "<<proper(i)<<endl;
    }

    vector<int> test2 = {0, 2, 3, 9, 13, 5};
    int result = 0;
    cout<<"Test two product"<<endl;
    vector<int> output = twoProduct(test2, result);
    for (auto i: output){
        cout<<i<<endl;
    }


    string testString = "ABAB";
    string testString1 = "CACA";

    if (samePattern(testString, testString1)){
        cout<<"The strings are the same"<<endl;
    }

    return 0;

}