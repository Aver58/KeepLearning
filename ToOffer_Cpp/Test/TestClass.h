#include <iostream>
using namespace std;

class A{
    public:
    A(){cout<<1;}
    ~A(){cout<<2;}
};

class B:public A{
    public:
    B(){cout<<3;}
    ~B(){cout<<4;}
};

void testA(){
    B b;
}

void testB(){
    A* a = new B();
    delete a;
}

int main()
{
    testA();//1342
    testB();//132
}


