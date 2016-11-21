#include <iostream>
using namespace std;
/*
// Compiler Sythesis default Ctor
- When base class Ctor and derived class dont have Ctor.
- When contained has Ctor and container dont have Ctor.
- When class has virtual method, so set vptr.
- when class has virtual inheritance.
*/

namespace CtorSynthesisDefault01 {
class CA {
public:
    CA () { 
        /*
         prolog...
         setVptr(CA::vftable)
        */
        
        cout << "CA ctor" << endl;         
    }
    ~CA () { 
        /*
         prolog...
         setVptr(CA::vftable)
        */
        
        cout << "CA Dtor" << endl;         
    }
};
class CB: public CA {
    /*
    CB () 
    {//prolog CA::CA()
    }
    */
};

int main (void) {
    CB obj;
    return 0;
}
}

namespace CtorSynthesisDefault02 {
class CA {
public:
    CA () { cout << "CA ctor" << endl; }
    ~CA () { cout << "CA Dtor" << endl; }
};
class CB {
    CA CAobj;
public:
};

int main (void) {
    CB obj;
    return 0;
}
}

namespace CtorSynthesisDefault03 {
class CA {
public:
    /*CA() {}*/ // Sythesis Ctor to set vptr
    virtual void fun (void) {} //
};

class CB:public CA {
public:
};

int main () {
    CA obj;
    CB obj1;    // compiiler Sythesis CB's & CA's ctor 
}
}

namespace CtorSynthesisDefault04 {
class CA {
};
class CB: virtual CA {
    /*CB() {}*/ // Sythesis Ctor to set vptr
};
int main (void) {
    CB obj;
}
}

namespace CtorCallOrder {
struct IX { IX() { cout<<"X"<<endl; } };
struct IY { IY() { cout<<"Y"<<endl; } };
struct IZ { IZ() { cout<<"Z"<<endl; } };
struct IA { IA() { cout<<"A"<<endl; } };
struct IB { IB() { cout<<"B"<<endl; } };
struct IC { IC() { cout<<"C"<<endl; } };
struct SA : IX,IY,IZ {
    IA m_a;
    IB m_b;
    IC m_c;
    SA(){ cout<<"SA const"<<endl; }
};
int main (void) {
    SA obj;
}
/*x,y,z,a,b,c,sa*/
}

namespace CtorTypes {
/*
- Default Ctor
- Overloaded Ctor
- Copy Ctor
- static Ctor
- virtual Ctor
*/
struct CA {
    CA () {cout << "Default Ctor" << endl;} /*Default Ctor*/
    CA (int) {cout << "Overloaded Ctor" << endl;} /*Overloaded Ctor*/
    CA (int, char) {cout << "Overloaded2 Ctor" << endl;}/*Overloaded Ctor*/
    CA (CA &obj) {cout << "Copy Ctor" << endl;}/*Copy Ctor*/
    CA (CA &obj, int) {cout << "overloaded3 Ctor" << endl;}/*Copy Ctor*/
};
int main (void) {
    CA obj1;
    CA obj2(10);
    CA obj3(10, 'h');
    CA obj4(obj1);
    CA obj5 = obj2;
    CA obj6(obj1, 10);
    return 0;
}
}

namespace CtorStatic {
/*struct SA {
    struct Static {
        int x;
        int y;
        int z;
        
        Static() {
            cout<<"static constructor"<<endl;
        }
    };
    static Static m_static;
};
SA::Static SA::m_static;
void main16() {
    SA o1;
    SA o2;
    SA o3;
    SA o4;
}
*/
#if 0
class CA {
public:
    CA () {cout << "CA Ctor" << endl;}
    ~CA () {cout << "CA Dtor" << endl;}
};
class CB {
public:
    static CA static_obj;
};
CA CB::static_obj;
int main (void) {
    CB o1;
    CB o2;
    CB o3;
    CB o4;
    return 0;
}
#endif
}

namespace CtorExplicit {
struct SA {
    //overloaded
    explicit SA(int data) {}
    //copy const (clone, prototype)
    explicit SA(SA& rhs) {}
};

int main (void) {
    SA o2(123); //overloaded 
    //SA o3 = 123; //<-- error
    SA o5(o2);    //copy constructor
    //SA o6 = o2; //<-- error
    return 0;
}
}

namespace CtorPrologAndEpilog {
class CA
{
public:
    CA()
    {
        /*
         *	prolog...
         *	setVptr(CA::vftable)
         */
        fun();//this->vptr->vtable[0]()()
    }
    virtual void fun()
    {
        cout << "Apple" << endl;
    }
    ~CA()
    {
        /*
         *	prolog...
         *	setVptr(CA::vftable)
         */
        fun();//this->vptr->vtable[0]()
    }
};
class CB :public CA
{
public:
    CB()
    {
        /*
         *              prolog...
         *              call CA::CA()
         *              setVptr(CB::vftable)
         */
    }
    virtual void fun() override//c++11
    {
        cout << "Orange" << endl;
    }
    ~CB()
    {
        /*
         *	prolog...
         *	setVptr(CB::vftable)
         */
    }
    /*
     * call CA::~CA()
     */
};

int main()
{
    CB obj;
    return 0;
}
}