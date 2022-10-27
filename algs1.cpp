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

class shape{
    protected:
        int width; height

};



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
    ptr &i;


    cout<<same_letter("aaaacccadd", "bbbbaaabee")<<endl;
    return 0;

}