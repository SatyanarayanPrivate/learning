#include<iostream>
using namespace std;

// compiler synthesis ctor:: 
/*
case 1: if base having constructor derived dont have Ctor.
case 2: when you have virtual function
case 3: container example
case 4: set offset table
*/

#if 0
class CA {
public:
    CA()
    {
        /*
        prolog
        setvptr(CA::vftable)
        */

        fun(); //this->fun();
    }
    virtual void fun() {
        cout << "Apple CA" << endl;
    }
    ~CA()
    {
        /*
        prolog
        setvptr(CA::vftable)
        */
        fun();
    }
};

class CB : public CA
{
public:
    CB()
    {
        /* prolog
        CA::CA()
        setvptr(CB::vftable)
        */
    }
    virtual void fun() override //c++11
    {
        cout << "orange CB" << endl;
    }
    ~CB()
    {
        /*
        setvptr(CB::vftable)
        */

        /* epilog
            CA::~CA()
        */
    }
};

int main() {
    CB obj;    
    return 0;
}
#endif

class CA {
public:
    CA()
    {
        // vptr updated/ overwritten to CA's vtable
        cout << "CA Ctor" << endl;
        fun(); //this->vptr->vtable[0]();
    }
    virtual void fun() {
        cout << "Apple CA" << endl;
    }
    void Myfun() {
        fun();
    }
    ~CA()
    {
        cout << "CA Dtor" << endl;
        fun();//this->vptr->vtable[0]()
    }
};

class CB : public CA
{
public:
    CB()
    {
        // vptr updated/ overwritten to CB's vtable
        cout << "CB Ctor" << endl;
    }
    virtual void fun()
    {
        cout << "orange CB" << endl;
    }
    ~CB()
    {
        cout << "CB Dtor" << endl;
        fun();//this->vptr->vtable[0]()
    }
};

int main() {
    CB obj;
    obj.Myfun();
    
    return 0;
}