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