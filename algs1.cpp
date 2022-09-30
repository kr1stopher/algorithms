#include <iostream>
#include <memory>



using namespace std;




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


int main() {
    //pass using move function 
    unique_ptr<int> myptr = make_unique<int>();
    *myptr = 9;
    myFunc(move(myptr));
    unique_ptr<int> myptr2 = make_unique<int>();
    *myptr2 = 9;
    myFunc2(myptr2);
    cout<<endl<<myptr2<<" in main"<<endl;

    return 0;

}