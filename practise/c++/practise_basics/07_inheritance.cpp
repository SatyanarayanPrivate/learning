#include<iostream>
using namespace std;


//function
//hidding 
//uppending 
//overriding
//overloading

#if 0
class CA {
private:// guard code
    int x;
protected:
    int y;
public:
    int z;
    CA() : x(12), y(234), z(3)
    {

    }
    void DisplayCA()
    {
        cout << "DispCA !!!" << endl;
        cout << "x=" << x << endl;
        cout << "y=" << y << endl;
        cout << "z=" << z << endl;
        cout << "-----------------------------------------------" << endl;
    }
};

class CB : public CA
{
public:
    void DisplayCB()
    {
        cout << "DispCB !!!" << endl;
        //cout << "x=" << x << endl;	// private member are not visible to derived class
        cout << "y=" << y << endl;		// protected member are visible to derived class
        cout << "z=" << z << endl;      // public member are visible to derived class
        cout << "-----------------------------------------------" << endl;
    }
};

class CC : protected CB
{
public:
    void DisplayCC()
    {
        cout << "DispCC !!!" << endl;
        //cout << "x=" << x << endl;	// private member are not visible to derived class
        cout << "y=" << y << endl;		// protected member are visible to derived class
        cout << "z=" << z << endl;
        cout << "-----------------------------------------------" << endl;
    }
};

class CD : private CA
{
protected:
    using CA::y;
    CA::z;	// using is optional

public:
    // vertical access control
    // changing access of base in derived class
    using CA::DisplayCA;
    // friend function is horizontal access control
    void DisplayCD()
    {
        cout << "DispCD !!!" << endl;
        //cout << "x=" << x << endl;	// private member are not visible to derived class
        cout << "y=" << y << endl;		// protected member are visible to derived class
        cout << "z=" << z << endl;
        cout << "-----------------------------------------------" << endl;
    }
};
int main()
{
    CA obj;
    obj.z = 1212;
    obj.DisplayCA();

    CB obj1;
    obj1.z = 124;
    //obj1.CA::z = 123; // to access base class member
    obj1.DisplayCA();
    obj1.DisplayCB();

    CC obj2;
    //obj2.z = 124; // z is private for CC
    obj2.DisplayCC();
    
    CD obj3;
    obj3.DisplayCD();
    obj3.DisplayCA();

}
#endif

#if 1
class CA {
private:// guard code
    int x;
protected:
    int y;
public:
    int z;
    CA() : CA(10, 20, 12)	// ctor delegation c++11
    {
        cout << "CA Default Ctor" << endl;
    }

    CA(int x, int y, int z) : x(x), y(y), z(z)
    {
        cout << "CA Param" << endl;
    }

    void DisplayCA()
    {
        cout << "DispCA !!!" << endl;
        cout << "x=" << x << endl;
        cout << "y=" << y << endl;
        cout << "z=" << z << endl;
        cout << "-----------------------------------------------" << endl;
    }

    void fun() {
        cout << "apple CA" << endl;
    }
    void fun1() {
        cout << "orange CA" << endl;
    }

    ~CA() {
        cout << "Dtor CA" << endl;
    }
};

class CB : public CA {
public:
    CA ca_obj;
    CB()
    { // prolog:: call CA::CA()
        cout << "CB Default Ctor" << endl;
    }
    // function hidding:: base class fun are hidden
    void fun() {
        cout << "apple CB" << endl;
    }
    ~CB() {
        cout << "Dtor CB" << endl;
    }// epilog:: CA::~CA()
};

int main() {
    //	CA obj;
    //	obj.DisplayCA();

    CB obj1;
    obj1.DisplayCA();
    obj1.fun();
    obj1.fun1();
    
    return 0;
}
#endif