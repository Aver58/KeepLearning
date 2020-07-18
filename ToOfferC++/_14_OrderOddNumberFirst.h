#include <iostream>
using namespace std;

class OrderOddNumberFirst
{
    public:
        OrderOddNumberFirst();
        void ReOrder(int*,int n,bool (*func)(int));

};