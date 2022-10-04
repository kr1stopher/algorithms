#include <iostream>
#include <memory>



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
            return this->area() + b->area();
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
void sub_triangle



int main() {
    //pass using move function 
    unique_ptr<int> myptr = make_unique<int>();
    *myptr = 9;
    myFunc(move(myptr));
    unique_ptr<int> myptr2 = make_unique<int>();
    *myptr2 = 9;
    myFunc2(myptr2);
    cout<<endl<<*myptr2<<" in main"<<endl;


    unique_ptr<rectangle> rect = make_unique<rectangle>();
    unique_ptr<triangle> tri = make_unique<triangle>();
    triangle mytri(1,2); 
    rectangle myrec(2,2);

    *rect = myrec;
    *tri = mytri; 
    
    rect->area();
    tri->area();



    return 0;

}