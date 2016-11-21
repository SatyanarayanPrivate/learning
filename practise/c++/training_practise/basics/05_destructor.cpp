#include <iostream>
using namespace std;

/*
 * // Compiler Sythesis default Dtor
 * - When base class Dtor and derived class dont have Dtor.
 * - When contained has Dtor and container dont have Dtor.
 * - when class has virtual inheritance.
 */


namespace DtorSynthesis01 {
class CA {
public: 
    ~CA () { cout << "CA Dtor" << endl; }
};

class CB: public CA {
public:
    /*
    ~CB()
    {
    } this->CA::~CA()
    */
};

int main (void) {
    CB obj;
    return 0;
}
}

namespace DtorProLogAndEpiLog_Order {
struct IX { ~IX() { cout<<"X's Dtor"<<endl; } };
struct IY { ~IY() { cout<<"Y's Dtor"<<endl; } };
struct IZ { ~IZ() { cout<<"Z's Dtor"<<endl; } };
struct IA { ~IA() { cout<<"A's Dtor"<<endl; } };
struct IB { ~IB() { cout<<"B's Dtor"<<endl; } };
struct IC { ~IC() { cout<<"C's Dtor"<<endl; } };

struct SA: IX,IY,IZ {
    IA m_a;
    IB m_b;
    IC m_c;
    ~SA()
    {
        //******* prolog ****************
        /*
         *				PUSH EBP
         *				MOV EBP,ESP
         *				ADD ESP,40
         * 
         *				1.initialize virtual inheritance vptr
         * 
         *				2.initialize all virtual function vptr
         */
        //******* body ****************
        /*
         *				programmer writes cleanup code
         */
        cout<<"SA Dtor"<<endl;
        //******* EPILOG ****************
        /*
         *				3.call all data members destructor
         *					in the reverse order of declaration
         *				
         *					m_c.IC::~IC();
         *					m_b.IB::~IB();
         *					m_a.IA::~IA();
         * 
         *				4.call all base class destructor
         *					in the reverse order of inheritance
         *					IZ::~IZ();
         *					IY::~IY();
         *					IX::~IX();
         * 
         *				  MOV ESP,EBP
         *				  pop EBP
         *				  ret
         */
    }
};
int main (void) {
    SA obj;
    return 0;
}
}

namespace DtorOrder {
class CA {
    static int count;
    int x;
public:
    int val;
    CA()
    {
        count++;
        x = count;
        val  = 0x00;
        cout << "CA default ctor" << endl;
    }
    CA (int val): val (val) {
        count++;
        x = count;
        cout << "CA one param ctor" << endl;
    }
    CA(const CA &ref) {
        x = 111;
        cout << "CA Ctor Copy" << endl;
    }

    ~CA() {
        cout << "Dtor x= " << x << " val= "<< val << endl;
    }
};
int CA:: count = 0x00;
// order of global ctor/ dtor is order of declairation.
static CA obj2(12);
CA obj1(11);

void fun2()
{
    static CA obj3(13);
    CA obj4;
    cout << "orange" << endl;
}

int main()
{
    fun2();
    CA *obj5 = new CA();

    delete obj5;
    cout << "Apple" << endl;
    return 0;
}
// 1st fun static obj's dtor gets called then global obj's
}

namespace DtorVitualTableUpdate{
class CA
{
public:
    CA() {
        /* set vptr to CA's vptr*/
        fun();//this->vptr->vtable[0]()
    }
    ~CA() {
        /* set vptr to CA's vptr*/
        fun();//this->vptr->vtable[0]()
    }
    virtual void fun() {
        cout<<"fun ca"<<endl;
    }
};
class CB:public CA {
public:
    /* CB()
    { CA::CA()
         set vptr to CB's vptr
    }
    */
    void fun() {
        cout<<"fun cb"<<endl;
    }
    ~CB() {
        /* set vptr to CB's vptr*/
        fun();//this->vptr->vtable[0]()
    }

};
int main() {
    CB obj;
    obj.fun();
    return 0;
}
}